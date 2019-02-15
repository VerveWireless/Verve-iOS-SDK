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

@protocol VRVInterstitialAdDelegate <NSObject>

@required
- (void)onInterstitialAdReadyForZone:(NSString *)zone;
- (void)onInterstitialAdFailedForZone:(NSString *)zone;
- (void)onInterstitialAdClosedForZone:(NSString *)zone;

@end

@interface VRVInterstitialAd : NSObject

+ (void)setInterstitialAdDelegate:(UIViewController<VRVInterstitialAdDelegate> *)delegate appID:(NSString *)appID;
+ (void)loadInterstitialAdForZone:(NSString *)zone;
+ (void)showInterstitialAdForZone:(NSString *)zone;

@end

NS_ASSUME_NONNULL_END
