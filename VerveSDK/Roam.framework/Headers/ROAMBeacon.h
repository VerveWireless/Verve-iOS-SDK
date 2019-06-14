
#import <Foundation/Foundation.h>

/**
 The `ROAMBeacon` class represents a beacon that was encountered during beacon ranging. The `ROAMBeaconManager` object
 reports encountered beacons to its associated delegate object.
 */
NS_SWIFT_NAME(Beacon)
@interface ROAMBeacon : NSObject <NSCopying, NSSecureCoding>

/**
 A unique identifier representing the beacon object. You use this identifier to differentiate each beacon within
 your application.
 */
@property (readonly, nonnull) NSString *identifier;

/**
 The name of the beacon as it was entered in the Roam Developer Portal.
 */
@property (readonly, nonnull) NSString *name;

/**
 The key-value pair property descriptions assigned to the beacon as it was entered in the Roam Developer Portal.
 @note Use this property to store custom attributes that are related to this beacon.
 */
@property (readonly, nonnull) NSDictionary *properties;

@end
