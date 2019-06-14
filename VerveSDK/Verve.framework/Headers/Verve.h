#import <Foundation/Foundation.h>

#import "VRVInitializationDelegate.h"

/// :nodoc:
typedef NSString * VRVInitializationOption NS_TYPED_ENUM NS_SWIFT_NAME(InitializationOption);

NS_ASSUME_NONNULL_BEGIN

/**
 *  Verve base. Coordinates configuration and enables all Verve services.
 */
@interface Verve : NSObject

/**
 *  Returns the Verve singleton object.
 */
+ (instancetype)sharedInstance;

/**
 * The delegate object to receive initialization event updates.
 */
@property (nonatomic, weak, nullable) id<VRVInitializationDelegate> initializationDelegate;

/**
 * Initialize Verve. Call this method within your App Delegate's `application:didFinishLaunchingWithOptions:`
 *
 * This method is a convenience initializer for the `initializeWithApplicationID:secret:options:` method.
 *
 * @param applicationID A string representing your app's application id found on the Verve developer portal
 * @param secret A string representing your app's secret found on the Verve developer portal
 *
 */
- (void)initializeWithApplicationID:(NSString *)applicationID secret:(NSString *)secret;


/**
 * Initialize Verve. Call this method within your App Delegate's `application:didFinishLaunchingWithOptions:`
 *
 * This method is a convenience initializer for the `initializeWithApplicationID:secret:options:` method.
 *
 * @param applicationID A string representing your app's application id found on the Verve developer portal
 * @param secret A string representing your app's secret found on the Verve developer portal
 * @param options A dictionary representing your options your app would like like to initialize with
 */
- (void)initializeWithApplicationID:(NSString *)applicationID secret:(NSString *)secret options:(nullable NSDictionary<VRVInitializationOption, id> *)options;

@end

NS_ASSUME_NONNULL_END
