//
//  VRVRewardedAd.h
//  verveSDK
//
//  Created by Sam Boyce on 1/28/19.
//  Copyright © 2019 Sam Boyce. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * This protocol will inform the delegate of events for a rewarded ad
 */
NS_SWIFT_NAME(RewardedAdDelegate)
@protocol VRVRewardedAdDelegate <NSObject>

@required
/**
 * Tells the delegate that the requested ad is ready
 *
 * @param zone The zone associated with the relevant ad
 */
- (void)onRewardedAdReadyForZone:(NSString *)zone;
/**
 * Tells the delegate that the requested ad failed to load
 *
 * @param zone The zone associated with the relevant ad
 */
- (void)onRewardedAdFailedForZone:(NSString *)zone;
/**
 * Tells the delegate that the ad has closed
 *
 * @param zone The zone associated with the relevant ad
 */
- (void)onRewardedAdClosedForZone:(NSString *)zone;
/**
 * Tells the delegate that the ad has reached the point where the application should reward the user
 *
 * @param zone The zone associated with the relevant ad
 */
- (void)onRewardedAdRewardedForZone:(NSString *)zone;

@end

NS_SWIFT_NAME(RewardedAd)
@interface VRVRewardedAd : NSObject

/**
 * Sets the delegate for interstitial ads, must be called before loading a rewarded ad
 *
 * @param delegate The object that will receive messages for interstitial ads @note must be a class of UIViewController
 * @param appID A unique identifier provided by Verve
 */
+ (void)setRewardedAdDelegate:(UIViewController<VRVRewardedAdDelegate> *)delegate appID:(NSString *)appID;
/**
 * Loads a rewarded ad.
 *
 * @param zone The zone associated with the relevant ad
 */
+ (void)loadRewardedAdForZone:(nullable NSString *)zone;
/**
 * Loads a rewarded ad with ad markup.
 *
 * @param zone The zone associated with the relevant ad
 * @param markup The ad markup to be used
 */
+ (void)loadRewardedAdForZone:(nullable NSString *)zone markup:(nullable NSString *)markup;
/**
 * Show a rewarded ad. The ad will be presented in a new view controller.
 *
 * @param zone The zone associated with the relevant ad
 */
+ (void)showRewardedAdForZone:(nullable NSString *)zone;
/**
 Used to toggle logging on the Ad SDK. Default is to not show logs.
 */
+ (void)showVRVLogs:(BOOL)shouldShowLogs;

@end

NS_ASSUME_NONNULL_END
