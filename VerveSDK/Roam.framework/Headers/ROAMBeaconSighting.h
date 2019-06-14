
#import <Foundation/Foundation.h>

@class ROAMBeacon;

/**
 Constants that reflect the relative distance to a beacon.
 */
typedef NS_ENUM(NSInteger, ROAMBeaconProximity)
{
    /// The beacon proximity could not be determined.
    ROAMBeaconProximityUnknown NS_SWIFT_NAME(unknown),
    /// The beacon is in the user’s immediate vicinity.
    ROAMBeaconProximityImmediate NS_SWIFT_NAME(immediate),
    /// The beacon is relatively close to the user.
    ROAMBeaconProximityNear NS_SWIFT_NAME(near),
    /// The beacon is far away.
    ROAMBeaconProximityFar NS_SWIFT_NAME(far)
} NS_SWIFT_NAME(BeaconProximity);

/**
 A `ROAMBeaconSighting` class represents a singular beacon sighting in time being encountered. This includes the
 current RSSI and proximity to enable custom user experiences.
 **/
NS_SWIFT_NAME(BeaconSighting)
@interface ROAMBeaconSighting : NSObject <NSCopying, NSSecureCoding>

/**
 The beacon currently being sighted
 */
@property (readonly, nonnull) ROAMBeacon *beacon;

/**
 The received signal strength of the beacon, measured in decibels.
 */
@property (readonly) NSInteger rssi;

/**
 The relative distance to the beacon.
 */
@property (readonly) ROAMBeaconProximity proximity;

@end
