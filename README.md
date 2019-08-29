# Verve iOS SDK

## Integrating the SDK Framework
Supports iOS 10 and above

Add the provided framework files (Verve, VerveAd, and Roam) to your application by adding them as a Embedded Binaries to your target. You can do this by pressing the "+" button under the "Embedded Binaries" section under the "General" tab of your application's target or by dragging and dropping the framework file into this section. If dragging and dropping be sure to move the framework file into the same file as your Xcode project. Check "Copy Items If Needed" when prompted.

![alt text](https://cdn.mediabrix.com/sdk4/images/iOS-Addfile.png)
![alt text](https://cdn.mediabrix.com/sdk4/images/iOS-Frameworks.png)

### App ID and Secret
Once you have been signed up by our Publisher Services team, the credentials for your application will be sent out to you automatically. The App ID should be used to fill in the fields labelled `appID`. If you do not have an App ID or Secret, please contact your Verve Publisher Services Account Manager.

### Initialization
In your AppDelegate class you should import the Verve SDK with your other imports `#import <Verve/Verve.h>`, in the `(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions` call you should initialize the Verve SDK like so:
```objc
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [Verve.sharedInstance initializeWithApplicationID:@"YOUR-APP-ID" secret:@"YOUR-SECRET"];
    return YES;
}
```

### Zones
The zone field can be passed an arbitrary string or can be used to target ads in certain situations. If you were directed by a Verve representative to use specific "keywords" when making ad requests, these should be passed in the Zone field. 

Alternatively you can this string to group your data for reporting, just limit the string length to 100 characters. Also note the "|" character is a restricted character. A nil or NULL Zone will be treated as an empty string.

### XML Library
You will also need to update a couple of Build Settings for your app's target:

`Header Search Paths` needs to contain `/usr/include/libxml2`

`Other Linker Flags` needs to contain `-lxml2`

### App Transport Security
The Ad SDK will need to communicate with HTTP endpoints to function. To allow this you will have to add a value to the `info.plist` file associated with your application's target. To do this, click on your application's project in Xcode, then select the app's target. Click the `info` tab and add a new key to the `Custom iOS Target Properties` called `App Transport Security Settings`. This should create a dictionary, to which you should add the key `Allow Arbitrary Loads` and set the value for that key to `YES`.

![alt text](https://cdn.mediabrix.com/sdk4/images/iOS-Settings.png)

### Testing
Verve ads can only be shown to IP addresses located inside the US. If you are testing outside of the US, please utilize a proxy or VPN on your device to ensure delivery of test campaigns.

## Interstitial Video
An Interstitial Ad must be loaded and shown on a UIViewController. This VC should also conform to the VRVInterstitialAdDelegate protocol.

### Import Headers and Set AppID
First, import the Interstitial Ad header by calling `#import <VerveAd/VRVInterstitialAd.h>` with your other import statements.

Then, use `+ (void)setInterstitialAdDelegate:(UIViewController<VRVInterstitialAdDelegate> *)delegate appID:(NSString *)appID;`
to set the VC that will show the ad.

>Interstitial Ads will present in their own UIViewController, however a root View Controller must be designated. This root VC should be the active VC when attempting to present an ad.

### Loading an Interstitial Ad
To load an Interstitial Ad call `+ (void)loadInterstitialAdForZone:(nullable NSString *)zone;` and pass in the desired zone. Only one ad per zone will be loaded.

Once an ad is ready to be shown, the delegate function `- (void)onInterstitialAdReadyForZone:(NSString *)zone;` will be called.

### Show an Interstitial Ad

After loading successfully, you can safely call `+ (void)showInterstitialAdForZone:(nullable NSString *)zone;` to show the ad.

After successfully closing the ad once it's been viewed, `- (void)onInterstitialAdClosedForZone:(NSString *)zone;` will be called.

### Interstitial Delegate Callbacks - VRVInterstitialAdDelegate
```objc
    // Called when ad has been successfully loaded, and is ready to be shown
- (void)onInterstitialAdReadyForZone:(NSString *)zone;

    // Called when no ad is available to be shown, or an ad has failed to load
- (void)onInterstitialAdFailedForZone:(NSString *)zone;

    // Called when ad has been closed and dismissed from view
- (void)onInterstitialAdClosedForZone:(NSString *)zone;
```

### Sample Code
```objc
#import "ViewController.h"
#import <VerveAd/VRVInterstitialAd.h>

@interface ViewController () <VRVInterstitialAdDelegate>
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [VRVInterstitialAd setInterstitialAdDelegate:self appID:@"6cFM0mTUUh"];
    [VRVInterstitialAd loadInterstitialAdForZone:@"vast2"];
}

- (void)onInterstitialAdReadyForZone:(nonnull NSString *)zone {
    if ([zone isEqualToString:@"vast2"]) {
      [VRVInterstitialAd showInterstitialAdForZone:zone];
    }
}

@end
```


## Rewarded Video
Rewarded Ads work in exactly the same manner as Interstitial ads, only they use the function calls included in `<VerveAd/VRVRewardedAd.h>`.

![alt text](https://cdn.mediabrix.com/sdk4/images/Ad.png)

### Import Headers and Set AppID
First, import the Rewarded Ad header by calling `#import <VerveAd/VRVRewardedAd.h>` with your other import statements.

Then, use `+ (void)setRewardedAdDelegate:(UIViewController<VRVRewardedAdDelegate> *)delegate appID:(NSString *)appID;`
to set the VC that will show the ad.

### Loading a Rewarded Video Ad
To load an Rewarded Video Ad call `+ (void)loadRewardedAdForZone:(nullable NSString *)zone;` and pass in the desired zone. Only one ad per zone will be loaded.

Once an ad is ready to be shown, the delegate function `- (void)onRewardedAdReadyForZone:(NSString *)zone;` will be called.

### Show a Rewarded Video Ad

After loading successfully, you can safely call `+ (void)showRewardedAdForZone:(nullable NSString *)zone;` to show the ad.

After successfully closing the ad once it's been viewed, `- (void)onRewardedAdClosedForZone:(NSString *)zone;` will be called.

### Rewarded Video Delegate Callbacks - VRVRewardedAdDelegate
The only significant way that Rewarded Ads differ from Interstitial ads in their execution is the delegate call `- (void)onRewardedAdRewardedForZone:(NSString *)zone;`. This delegate function will be called when a rewarded ad has reached the point where the user has met the requirements for the reward.

```objc
    // Called when ad has been successfully loaded, and is ready to be shown
- (void)onRewardedAdReadyForZone:(NSString *)zone;

    // Called when no ad is available to be shown, or an ad has failed to load
- (void)onRewardedAdFailedForZone:(NSString *)zone;

    // Called when a user has completed the ad view, and has earned the reward
- (void)onRewardedAdRewardedForZone:(NSString *)zone;

    // Called when ad has been closed and dismissed from view
- (void)onRewardedAdClosedForZone:(NSString *)zone;
```

## Banner Ads
To create a banner ad instantiate a VRVBannerAdView object using
```objc
- (instancetype)initWithDelegate:(id<VRVBannerAdDelegate>)delegate
                           appID:(NSString *)appID
                      bannerSize:(VRVBannerAdSize)adSize
                       andRootVC:(UIViewController *)rootVC;
```

This view will automatically be sized according to the following dimensions for different VRVBannerAdSize's:

| Size          | Constant           | Description          |
| ------------- |:------------------:| --------------------:|
| 320x50        | VRVBannerSizeBanner| Standard banner      |
| 728x90        | VRVBannerSizeTabletBanner	     | IAB Leaderboard      |
| 300x250	    | VRVBannerSizeMedRectangle   | IAB Medium Rectangle |

### Loading a Banner Ad
After creation, call `+ (void)loadAdForZone:(nullable NSString *)zone;` on the created VRVBannerView object to load an ad, which will display in the view as soon as it's loaded.

### VRVBannerAdDelegate / RootVC
A delegate must be attached to a banner ad which conforms to the VRVBannerAdDelegate protocol. Additionally, a reference to the UIViewController (rootVC) that will hold the banner ad must be passed to it. The delegate and rootVC can be the same object.

```objc
    // Called when ad has been successfully loaded
- (void)onBannerAd:(VRVBannerAdView *)bannerAd readyForZone:(NSString *)zone;

    // Called when no ad is available to be shown, or an ad has failed to load
- (void)onBannerAd:(VRVBannerAdView *)bannerAd failedForZone:(NSString *)zone;

    // Called when the banner ad will close
- (void)onBannerAd:(VRVBannerAdView *)bannerAd closedForZone:(NSString *)zone;
```


### Scroll View Reference
Some ads will change behavior according to the scrolling of a view. To use this feature you must call the function `- (void)informBannerAdOfScrollViewEvent:(UIScrollView *)scrollView;` on the banner view object when this scroll view scrolls. This is generally done within the function `- (void)scrollViewDidScroll:(UIScrollView *)scrollView`, which is a delegate call for `UIScrollViewDelegate`.

>Please note that it is the application's responsibility to add the VRVBannerView as a subview and position it.

### Sample Code:
```objc
#import "ViewController.h"
#import <VerveAd/VRVBannerAdView.h>

@interface ViewController () <VRVBannerAdDelegate, UIScrollViewDelegate>

@property VRVBannerAdView *bannerView;
@property UIScrollView *scrollView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, 100, 100)];
    [self.view addSubview:self.scrollView];

    self.bannerView = [[VRVBannerAdView alloc] initWithDelegate:self
                                                          appID:@"6cFM0mTUUh"
                                                     bannerSize:VRVBannerSizeBanner
                                                      andRootVC:self];
    [self.view addSubview:self.bannerView];
    [self.bannerView loadAdForZone:@"banner"];
}

- (void)onBannerAd:(VRVBannerAdView *)bannerAd readyForZone:(NSString *)zone {
    if ([zone isEqualToString:@"banner"] && [bannerAd isEqual:self.bannerView]) {
        NSLayoutConstraint *bottomBanner = [NSLayoutConstraint constraintWithItem:bannerAd
                                                                        attribute:NSLayoutAttributeBottom
                                                                        relatedBy:NSLayoutRelationEqual
                                                                           toItem:self.view.layoutMarginsGuide
                                                                        attribute:NSLayoutAttributeBottom
                                                                       multiplier:1
                                                                         constant:0];
        NSLayoutConstraint *centerBanner = [NSLayoutConstraint constraintWithItem:bannerAd
                                                                        attribute:NSLayoutAttributeCenterX 
                                                                        relatedBy:NSLayoutRelationEqual
                                                                           toItem:self.view.layoutMarginsGuide 
                                                                        attribute:NSLayoutAttributeCenterX
                                                                       multiplier:1
                                                                         constant:0];
        [self.view addConstraints:@[bottomBanner, centerBanner]];
    }
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    if (self.bannerView) {
        [self.bannerView informBannerAdOfScrollViewEvent:scrollView];
    }
}

@end
```
