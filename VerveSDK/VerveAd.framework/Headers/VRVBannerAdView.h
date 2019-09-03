//
//  VRVBannerAdView.h
//  verveSDK
//
//  Created by Sam Boyce on 11/26/18.
//  Copyright © 2018 Sam Boyce. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, VRVBannerAdSize) {
    //320x50
    VRVBannerSizeBanner NS_SWIFT_NAME(Banner),
    //728x90
    VRVBannerSizeTabletBanner NS_SWIFT_NAME(TabletBanner),
    //300x250
    VRVBannerSizeMedRectangle NS_SWIFT_NAME(MedRectangle),
    //Used for debug purposes, passing this value will result in a 320x50
    VRVBannerSizeNone NS_SWIFT_NAME(None)
} NS_SWIFT_NAME(BannerAdSize);

@class VRVBannerAdView;

/**
 * This protocol will inform the delegate of events for a specific banner ad
 */
NS_SWIFT_NAME(BannerAdDelegate)
@protocol VRVBannerAdDelegate <NSObject>

@required
/**
 * Tells the delegate that the requested ad is ready
 *
 * @param bannerAd The ad view reporting the event
 * @param zone The zone associated with the relevant ad
 */
- (void)onBannerAd:(VRVBannerAdView *)bannerAd readyForZone:(NSString *)zone;
/**
 * Tells the delegate that the requested ad failed to load
 *
 * @param bannerAd The ad view reporting the event
 * @param zone The zone associated with the relevant ad
 */
- (void)onBannerAd:(VRVBannerAdView *)bannerAd failedForZone:(NSString *)zone;
/**
 * Tells the delegate that the ad will close
 *
 * @param bannerAd The ad view reporting the event
 * @param zone The zone associated with the relevant ad
 */
- (void)onBannerAd:(VRVBannerAdView *)bannerAd closedForZone:(NSString *)zone;

@optional
/**
 * Tells the delegate that the ad has loaded a clickout view
 *
 * @param zone The zone associated with the relevant ad
 */
- (void)onBannerAdClickedForZone:(NSString *)zone;

@end

NS_SWIFT_NAME(BannerAdView)
@interface VRVBannerAdView : UIView

/**
 * This method creates the banner ad view.
 *
 * @note An ad is not specifically requested in this method. Use -(void)loadAdForZone:(NSString *)zone
 *
 * @param delegate The object that will recieve messages for the banner ad
 * @param appID A unique identifier provided by Verve
 * @param adSize An enumerated type to specify what size of banner is desired
 * @param rootVC A reference to the view controller that will contain this banner ad view
 */
- (instancetype)initWithDelegate:(id<VRVBannerAdDelegate>)delegate appID:(NSString *)appID bannerSize:(VRVBannerAdSize)adSize andRootVC:(UIViewController *)rootVC;
/**
 * Loads a banner ad. The ad will appear in the banner ad view object as soon as it is ready.
 *
 * @param zone The zone associated with the relevant ad
 */
- (void)loadAdForZone:(nullable NSString *)zone;

/**
 * Loads a banner ad. The ad will appear in the banner ad view object as soon as it is ready.
 *
 * @param zone The zone associated with the relevant ad
 * @param markup The ad markup to be used
 */
- (void)loadAdForZone:(nullable NSString *)zone markup:(nullable NSString *)markup;

/**
 * This optional method is used for ads that have special behavior associated with the scrolling of a scroll view. This method should be called in the scrollViewDidScroll: delegate method.
 *
 * @param scrollView The view whose scrolling should cause the ad to trigger
 */
- (void)informBannerAdOfScrollViewEvent:(UIScrollView *)scrollView;
/**
 Used to toggle logging on the Ad SDK. Default is to not show logs.
 */
+ (void)showVRVLogs:(BOOL)shouldShowLogs;

@end

NS_ASSUME_NONNULL_END
