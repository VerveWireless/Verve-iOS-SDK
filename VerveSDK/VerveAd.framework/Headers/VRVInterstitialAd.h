//
//  VRVInterstitialAd.h
//  verveSDK
//
//  Created by Sam Boyce on 1/28/19.
//  Copyright © 2019 Sam Boyce. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * This protocol will inform the delegate of events for an interstitial ad
 */
NS_SWIFT_NAME(InterstitialAdDelegate)
@protocol VRVInterstitialAdDelegate <NSObject>

@required
/**
 * Tells the delegate that the requested ad is ready
 *
 * @param zone The zone associated with the relevant ad
 */
- (void)onInterstitialAdReadyForZone:(NSString *)zone;
/**
 * Tells the delegate that the requested ad failed to load
 *
 * @param zone The zone associated with the relevant ad
 */
- (void)onInterstitialAdFailedForZone:(NSString *)zone;
/**
 * Tells the delegate that the ad has closed
 *
 * @param zone The zone associated with the relevant ad
 */
- (void)onInterstitialAdClosedForZone:(NSString *)zone;

@optional
/**
 * Tells the delegate that the ad has loaded a clickout view
 *
 * @param zone The zone associated with the relevant ad
 */
- (void)onInterstitialAdClickedForZone:(NSString *)zone;

@end

NS_SWIFT_NAME(InterstitialAd)
@interface VRVInterstitialAd : NSObject

/**
 * Sets the delegate for interstitial ads, must be called before loading an interstitial ad
 *
 * @param delegate The object that will receive messages for interstitial ads @note must be a class of UIViewController
 * @param appID A unique identifier provided by Verve
 */
+ (void)setInterstitialAdDelegate:(UIViewController<VRVInterstitialAdDelegate> *)delegate appID:(NSString *)appID;
/**
 * Loads an interstitial ad.
 *
 * @param zone The zone associated with the relevant ad
 */
+ (void)loadInterstitialAdForZone:(nullable NSString *)zone;
/**
 * Loads an interstitial ad using ad markup.
 *
 * @param zone The zone associated with the relevant ad
 * @param markup The ad markup to be used
 */
+ (void)loadInterstitialAdForZone:(nullable NSString *)zone markup:(NSString *)markup;
/**
 * Show an interstitial ad. The ad will be presented in a new view controller.
 *
 * @param zone The zone associated with the relevant ad
 */
+ (void)showInterstitialAdForZone:(nullable NSString *)zone;

/**
 Used to toggle logging on the Ad SDK. Default is to not show logs.
 */
+ (void)showVRVLogs:(BOOL)shouldShowLogs;

@end

NS_ASSUME_NONNULL_END
