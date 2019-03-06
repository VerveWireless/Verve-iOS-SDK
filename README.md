# Verve-Ad-SDK-iOS

## Integrating the SDK
Add the provided framework file to your application by adding it as an Embedded Binary to your target. You can do this by pressing the "+" button under the "Embedded Binaries" section under the "General" tab of your application's target or by dragging and dropping the framework file into this section. If dragging and dropping be sure to move the framework file into the same file as your Xcode project. Check "Copy Items If Needed" when prompted.

## App ID
Verve should have sent you a unique identifier for your application. This identifier should be used to fill in the fields labelled "appID".

## Interstitial Ads
An Interstitial Ad must be loaded and shown on a UIViewController. This VC should also conform to the VRVInterstitialAdDelegate protocol.

First, import the Interstitial Ad header by calling `#import <verveAdSDK/VRVInterstitialAd.h>` with your other import statements. Then, use `+ (void)setInterstitialAdDelegate:(UIViewController<VRVInterstitialAdDelegate> *)delegate appID:(NSString *)appID;`
to set the VC that will show the ad.

>Interstitial Ads will present in their own UIViewController, however a root View Controller must be designated. This root VC should be the active VC when attempting to present an ad.

### VRVInterstitialAdDelegate
```objc
- (void)onInterstitialAdReadyForZone:(NSString *)zone;
- (void)onInterstitialAdFailedForZone:(NSString *)zone;
- (void)onInterstitialAdClosedForZone:(NSString *)zone;
```

### Loading and Presenting an Interstitial Ad
To load an Interstitial Ad call `+ (void)loadInterstitialAdForZone:(NSString *)zone;` and pass in the desired zone. Only one ad per zone will be loaded. Once a loaded ad is ready to be presented the delegate function `- (void)onInterstitialAdReadyForZone:(NSString *)zone;` will be called. After this delegate call you can safely call `+ (void)loadInterstitialAdForZone:(NSString *)zone;`, passing in the relevant zone, to present the ad.

Sample Code
```objc
#import "ViewController.h"
#import <verveAdSDK/VRVInterstitialAd.h>

@interface ViewController () <VRVInterstitialAdDelegate>
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [VRVInterstitialAd setInterstitialAdDelegate:self];
    [VRVInterstitialAd loadInterstitialAdForZone:@"vast2"];
}

- (void)onInterstitialAdReadyForZone:(nonnull NSString *)zone {
    if ([zone isEqualToString:@"vast2"]) {
      [VRVInterstitialAd showInterstitialAdForZone:zone];
    }
}

@end
```

### Other Delegate Calls
If there is a failure loading or presenting the ad `- (void)onInterstitialAdFailedForZone:(NSString *)zone;` will be called. 
When the ad closes `- (void)onInterstitialAdClosedForZone:(NSString *)zone;` will be called.

## Rewarded Ads
Rewarded Ads work in exactly the same manner as Interstitial ads, only they use the function calls included in `<verveAdSDK/VRVRewardedAd.h>`. If using both Interstitial and Rewarded ads keep in mind that only one delegate can be active at a time between these two types of full screen ads. Calling `+ (void)setRewardedAdDelegate:(UIViewController<VRVRewardedAdDelegate> *)delegate appID:(NSString *)appID;` will remove the Interstitial ad delegate and vice versa.

### Rewarded Delegate Call
The only significant way that Rewarded Ads differ from Interstitial ads in their execution is the delegate call `- (void)onRewardedAdRewardedForZone:(NSString *)zone;`. This delegate function will be called when a rewarded ad has reached the point where the user has met the requirements for the reward.

>To test rewarded ads use the zone "reward".

## Banner Ads
To create a banner ad instantiate a VRVBannerAdView object using 
```objc
- (instancetype)initWithDelegate:(id<VRVBannerAdDelegate>)delegate
                           appID:(NSString *)appID
                      bannerSize:(VRVBannerAdSize)adSize 
                       andRootVC:(UIViewController *)rootVC;
``` 

This view will automatically be sized to fit the width of the screen in portrait mode according to the following ratios for different VRVBannerAdSize's:

| Size          | Constant           | Description          |
| ------------- |:------------------:| --------------------:|
| 320x50        | VRVBannerSizeBanner| Standard banner      |
| 728x90        | VRVBannerSizeTabletBanner	     | IAB Leaderboard      | 
| 300x250	    | VRVBannerSizeMedRectangle   | IAB Medium Rectangle |

After creation, call `- (void)loadAdForZone:(NSString *)zone;` on the created VRVBannerView object to load an ad, which will display in the view as soon as it's loaded.

### VRVBannerAdDelegate / RootVC
A delegate must be attached to a banner ad which conforms to the VRVBannerAdDelegate protocol
```objc
- (void)onBannerAd:(VRVBannerAdView *)bannerAd readyForZone:(NSString *)zone;
- (void)onBannerAd:(VRVBannerAdView *)bannerAd failedForZone:(NSString *)zone;
- (void)onBannerAd:(VRVBannerAdView *)bannerAd closedForZone:(NSString *)zone;
```
`- (void)onBannerAd:(VRVBannerAdView *)bannerAd readyForZone:(NSString *)zone;` will be called after `- (void)loadAdForZone:(NSString *)zone;`, when the ad is ready and being shown on the banner view.

`- (void)onBannerAd:(VRVBannerAdView *)bannerAd failedForZone:(NSString *)zone;` will be called if any errors occur loading and displaying the ad.

`- (void)onBannerAd:(VRVBannerAdView *)bannerAd closedForZone:(NSString *)zone;` will be called if the ad will close in the banner ad.

Additionally, a reference to the UIViewController (rootVC) that will hold the banner ad must be passed to it. The delegate and rootVC can be the same object.

### Scroll View Reference
Some ads will change behavior according to the scrolling of a view. To use this feature you must call the function `- (void)informBannerAdOfScrollViewEvent:(UIScrollView *)scrollView;` on the banner view object when this scroll view scrolls. This is generally done within the function `- (void)scrollViewDidScroll:(UIScrollView *)scrollView`, which is a delegate call for `UIScrollViewDelegate`.

>Please note that it is the application's responsibility to add the VRVBannerView as a subview and position it.

Sample Code:
```objc
#import "ViewController.h"
#import <verveAdSDK/VRVBannerAdView.h>

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
        [self.view addConstraint:bottomBanner];
    }
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    if (self.bannerView) {
        [self.bannerView informBannerAdOfScrollViewEvent:scrollView];
    }
}

@end
```
