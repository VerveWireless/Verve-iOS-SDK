# Verve-Ad-SDK-iOS

##Integrating the SDK
Add the provided framework file to your application by adding it as an Embedded Binary to your target. You can do this by pressing the "+" button under the "Embedded Binaries" section under the "General" tab of your application's target or by dragging and dropping the framework file into this section. If dragging and dropping be sure to move the framework file into the same file as your Xcode project. Be sure to check "Copy Items If Needed" when prompted.

##Interstitial Ads
An Interstitial Ad must be loaded and shown on a UIViewController. This VC should also conform to the VRVInterstitialAdDelegate protocol.

First, import the Interstitial Ad header by calling `#import <verveSDK/VRVInterstitialAd.h>` with your other import statements. Then, use `+ (void)setInterstitialAdDelegate:(UIViewController<VRVInterstitialAdDelegate> *)delegate;`
to set the VC that will show the ad.

>Interstitial Ads will present in their own UIViewController, however a root View Controller must be designated. This root VC should be the active VC when attempting to present an ad.

###VRVInterstitialAdDelegate
```
- (void)onInterstitialAdReadyForZone:(NSString *)zone;
- (void)onInterstitialAdFailedForZone:(NSString *)zone;
- (void)onInterstitialAdClosedForZone:(NSString *)zone;
```

###Loading and Presenting an Interstitial Ad
To load an Interstitial Ad call `+ (void)loadInterstitialAdForZone:(NSString *)zone;` and pass in the desired zone. Only one ad per zone will be loaded. Once a loaded ad is ready to be presented the delegate function `- (void)onInterstitialAdReadyForZone:(NSString *)zone;` will be called. You can now safely call `+ (void)loadInterstitialAdForZone:(NSString *)zone;`, passing in the relevant zone, to present the ad.

Sample Code
```
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

###Other Delegate Calls
If there is a failure loading or presenting the ad `- (void)onInterstitialAdFailedForZone:(NSString *)zone;` will be called. When the ad closes `- (void)onInterstitialAdClosedForZone:(NSString *)zone;` will be called.

##Rewarded Ads
Rewarded Ads work in exactly the same manner as Interstitial ads, only they use the function calls included in `<verveSDK/VRVRewardedAd.h>`. If using both Interstitial and Rewarded ads keep in mind that only one delegate can be active at a time between these two types of full screen ads. Calling `+ (void)setRewardedAdDelegate:(UIViewController<VRVRewardedAdDelegate> *)delegate;` will remove the Interstitial ad delegate and vice versa.

###Rewarded Delegate Call
The only significant way that Rewarded Ads differ from Interstitial ads in their execution is the delegate call `- (void)onRewardedAdRewardedForZone:(NSString *)zone;`. This delegate function will be called when a rewarded ad has reached the point where the user has met the requirements for the reward.6

>To test rewarded ads use the zone "reward".
