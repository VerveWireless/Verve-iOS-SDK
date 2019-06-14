
#import <Foundation/Foundation.h>

@class ROAMBeaconManager;
@class ROAMPlace;
@class ROAMBeaconSighting;

/**
 * The methods that you use to receive events from an associated `ROAMBeaconManager` object.
 *
 * @note The beacon manager calls the methods of this delegate to report beacon-related events to your app.
 * Implement this protocol in an app-specific object and use the methods to update your app.
 */
NS_SWIFT_NAME(BeaconManagerDelegate)
@protocol ROAMBeaconManagerDelegate <NSObject>

@optional
/**
 * Tells the delegate that zero or more beacons are in range for a place.
 *
 * @param manager The beacon manager object reporting the event.
 * @param beaconSightings An array of `ROAMBeaconSighting` objects representing the beacons currently in range. If
 * beacons is empty, you can assume that no beacons are found in this place. You can use the information in the
 * `ROAMBeaconSighting` objects to determine the range of each beacon and its identifying information.
 * @param place The place for which beacon sightings are currently in.
 */
- (void)beaconManager:(nonnull ROAMBeaconManager *)manager didRangeBeaconsWithSightings:(nonnull NSArray<ROAMBeaconSighting *> *)beaconSightings inPlace:(nonnull ROAMPlace *)place;

/**
 * Tells the delegate that an error occurred while attempting to range beacons in a place.
 *
 * @param manager The beacon manager object reporting the event.
 * @param place The place object that encountered the error.
 * @param error An error object containing the error code that indicates why ranging failed.
 */
- (void)beaconManager:(nonnull ROAMBeaconManager *)manager rangingBeaconsDidFailForPlace:(nonnull ROAMPlace *)place withError:(nonnull NSError *)error;

@end

/**
 * The beacon manager allows you to determine the proximity of a user to beacons within a place. Beacons and their
 * associations to a place are managed exclusivly on the Roam Developer Portal.
 */
NS_SWIFT_NAME(BeaconManager)
@interface ROAMBeaconManager : NSObject

/**
 * The delegate object to receive beacon event updates.
 */
@property (nonatomic, weak, nullable) id<ROAMBeaconManagerDelegate> delegate;

/**
 * The set of places who's beacons are currently being tracked using ranging.
 *
 * @note The beacon manager does not persists the set of places being ranged between launches of your app. If
 * your app is terminated and then relaunched, you may begin ranging for places which the user is currently visiting
 * by fetching the places from the `currentVisits` in the `ROAMVisitManager`.
 */
@property (nonatomic, readonly, nonnull) NSSet<ROAMPlace *> *rangedPlaces;

/**
 * Starts the delivery of beacon sightings for any beacons in the specified place.
 *
 * @param place The place who's beacons should be ranged.
 * @note Once registered, the beacon manager reports any encountered beacons in that place to its delegate by
 * calling the `visitManager:didRangeBeaconsWithSightings:inPlace:` method. This place will get added to the set of
 * `rangedPlaces` upon ranging for a place.
 */
- (void)startRangingBeaconsInPlace:(nonnull ROAMPlace *)place;

/**
 * Stops the delivery of beacon sightings for any beacons in specified place.
 * @param place The place who's beacons should not longer be ranged.
 */
- (void)stopRangingBeaconsInPlace:(nonnull ROAMPlace *)place;

@end
