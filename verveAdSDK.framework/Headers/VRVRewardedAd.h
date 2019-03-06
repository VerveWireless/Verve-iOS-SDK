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

@protocol VRVRewardedAdDelegate <NSObject>

@required
- (void)onRewardedAdReadyForZone:(NSString *)zone;
- (void)onRewardedAdFailedForZone:(NSString *)zone;
- (void)onRewardedAdClosedForZone:(NSString *)zone;
- (void)onRewardedAdRewardedForZone:(NSString *)zone;

@end

@interface VRVRewardedAd : NSObject

+ (void)setRewardedAdDelegate:(UIViewController<VRVRewardedAdDelegate> *)delegate appID:(NSString *)appID;
+ (void)loadRewardedAdForZone:(NSString *)zone;
+ (void)showRewardedAdForZone:(NSString *)zone;

@end

NS_ASSUME_NONNULL_END
