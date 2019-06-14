
#import <Foundation/Foundation.h>

@class ROAMPlace;

/**
 A `ROAMVisit` object encapsulates information about a place that the user has been. Visit objects are created by the
 Roam SDK and delivered by the `ROAMVisitManager` object to its delegate after you enable Roam. The visit includes the
 place where the visit occurred and information about the arrival and departure times as relevant.
 Visit objects contain as much information about the visit as possible but may not always include both the arrival and
 departure times. For example, when the user arrives at a location, the system may send an event with only an arrival
 time. When the user departs a location, the event will contain both the arrival and departure times.
 */
NS_SWIFT_NAME(Visit)
@interface ROAMVisit : NSObject <NSCopying, NSSecureCoding>

/**
 A unique identifier representing the visit object. You use this identifier to differentiate each visit within
 your application. This identifier will remain the same between the visit arrival and departure.
 */
@property (readonly, nonnull) NSString *identifier;

/**
 The place at which the user has visited.
 */
@property (readonly, nonnull) ROAMPlace *place;

/**
 The approximate time at which the user arrived at the specified place.
 */
@property (readonly, nonnull) NSDate *arrivalDate;

/**
 The approximate time at which the user departed the specified place.
 @note When the user departs a location, the event will contain both the arrival and departure times.
 */
@property (readonly, nonnull) NSDate *departureDate;

@end
