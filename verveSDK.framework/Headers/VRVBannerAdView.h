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
    VRVBannerSizeBanner,
    VRVBannerSizeTabletBanner,
    VRVBannerSizeMedRectangle
};

@class VRVBannerAdView;

@protocol VRVBannerAdDelegate <NSObject>

@required
- (void)onBannerAd:(VRVBannerAdView *)bannerAd readyForZone:(NSString *)zone;
- (void)onBannerAd:(VRVBannerAdView *)bannerAd failedForZone:(NSString *)zone;
- (void)onBannerAd:(VRVBannerAdView *)bannerAd closedForZone:(NSString *)zone;

@end

@interface VRVBannerAdView : UIView

- (instancetype)initWithDelegate:(id<VRVBannerAdDelegate>)delegate bannerSize:(VRVBannerAdSize)adSize andRootVC:(UIViewController *)rootVC;
- (void)loadAdForZone:(NSString *)zone;

//Optional
- (void)informBannerAdOfScrollViewEvent:(UIScrollView *)scrollView;

@end

NS_ASSUME_NONNULL_END
