//
//  VRVInitializationDelegate.h
//  Verve
//
//  Created by Mohammad Kurabi on 2/12/19.
//  Copyright © 2019 Verve Wireless, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Verve.h"

@class Verve;

NS_ASSUME_NONNULL_BEGIN

/**
 * The methods that you use to receive initialization events from an associated `Verve` object.
 *
 * @note The Verve instance calls the methods of this delegate to report Verve initialization related events to your app.
 * Implement this protocol in an app-specific object and use the methods to update your app.
 */
NS_SWIFT_NAME(InitializationDelegate)
@protocol VRVInitializationDelegate <NSObject>

@optional
/**
 * Tells the delegate that the Verve SDK initialization was successfull
 *
 * @param verve The Verve instance reporting the event.
 * @param options The options that the SDK was initialized with.
 */
- (void)verve:(Verve *)verve didInitializeWithOptions:(NSDictionary<NSString *, id> *)options;

/**
 * Tells the delegate that the Verve SDK initialization failed.
 *
 * @param verve The Verve instance reporting the event.
 * @param error An error object containing the error code that indicates why initialization failed.
 */
- (void)verve:(Verve *)verve didFailToInitializeWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
