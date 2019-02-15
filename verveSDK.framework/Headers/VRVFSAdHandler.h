//
//  VRVFSAdHandler.h
//  verveSDK
//
//  Created by Sam Boyce on 11/14/18.
//  Copyright © 2018 Sam Boyce. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol VRVFSAdDelegate <NSObject>

@required
- (void)onFSAdReadyForZone:(NSString *)zone;
- (void)onFSAdFailedForZone:(NSString *)zone;
- (void)onFSAdClosedForZone:(NSString *)zone;

@optional
- (void)onFSAdRewardedForZone:(NSString *)zone;

@end

@interface VRVFSAdHandler : NSObject

+ (VRVFSAdHandler *)sharedHandler;

- (void)setFSAdDelegate:(id<VRVFSAdDelegate>)delegate andRootVC:(UIViewController *)rootVC;
- (void)loadFSAdForZone:(NSString *)zone;
- (void)showFSAdForZone:(NSString *)zone;

@end

NS_ASSUME_NONNULL_END
