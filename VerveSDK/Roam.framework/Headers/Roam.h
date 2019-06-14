
#import <Foundation/Foundation.h>

#import "ROAMVisitManager.h"
#import "ROAMBeaconManager.h"

#import "ROAMVisit.h"
#import "ROAMPlace.h"
#import "ROAMBeacon.h"
#import "ROAMBeaconSighting.h"

/**
 *  Roam base. Coordinates configuration and enables all Roam services.
 */
@interface Roam : NSObject

/**
 The user opt-in state of Roam
 */
@property (readonly) BOOL isOptedIn;

/**
 *  Returns the Roam singleton object.
 */
+ (nonnull instancetype)sharedInstance;

/**
 * Opts in to Roam
 *
 * This state is persisted across app launches and can be checked with the `isOptedIn` method.
 *
 * @note Use this method when opting your user in to features enabled by Roam. Before enabling Roam, you should prompt
 * for the `Always` location permission. This method will immediately prompt for the location permission if the
 * `ROAMOptionPresentLocationPermissionAlert` option is set to true when initializing the Roam SDK, even if visit
 * monitoring is disabled remotely. The location permission will not be re-prompted if the user has already accepted or
 * declined the permission.
 */
- (void)optIn;

/**
 * Opts in to Roam
 *
 * This state is persisted across app launches and can be checked with the `isOptedIn` method.
 *
 * @param requestLocationAuthorization A boolean indicating if Roam should present the location authorization dialog
 */
- (void)optIn:(BOOL)requestLocationAuthorization NS_SWIFT_NAME(optIn(requestLocationAuthorization:));

/**
 * Opts the user out of all Roam services
 *
 * Use this method to stop the delivery of all visit and/or beacon events that were started using the `optIn` method.
 */
- (void)optOut;

@end
