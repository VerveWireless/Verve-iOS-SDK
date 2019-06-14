
#import <Foundation/Foundation.h>

@class ROAMVisit;
@class ROAMVisitManager;

/**
 * The methods that you use to receive events from an associated `ROAMVisitManager` object.
 *
 * @note The visit manager calls the methods of this delegate to report visit-related events to your app.
 * Implement this protocol in an app-specific object and use the methods to update your app.
 */
NS_SWIFT_NAME(VisitManagerDelegate)
@protocol ROAMVisitManagerDelegate <NSObject>

@optional
/**
 * The visit manager calls this method whenever it has a new visit began event to report to your app.
 *
 * @param manager The visit manager object reporting the event.
 * @param visit The visit object that contains the information about the visit begin event.
 */
- (void)visitManager:(nonnull ROAMVisitManager *)manager didBeginVisit:(nonnull ROAMVisit *)visit;

/**
 * The visit manager calls this method whenever it has a new visit end event to report to your app.
 *
 * @param manager The visit manager object reporting the event.
 * @param visit The visit object that contains the information about the visit end event.
 */
- (void)visitManager:(nonnull ROAMVisitManager *)manager didEndVisit:(nonnull ROAMVisit *)visit;

@end

/**
 * Get visit updates in the most power-efficient way. The places monitored by the `ROAMVisitManager` are managed in the
 * Roam Developer Portal. Visit event updates are delivered by the `ROAMVisitManagerDelegate`.
 */
NS_SWIFT_NAME(VisitManager)
@interface ROAMVisitManager : NSObject

/**
 * The delegate object to receive visit event updates.
 */
@property (nonatomic, weak, nullable) id<ROAMVisitManagerDelegate> delegate;

/**
 * The set of in-progress and current visits the user is currently observing.
 *
 * @note The visit manager persists in-progress and current visit data between launches of your app. If your app
 * is terminated and then relaunched, the contents of this property are repopulated with visit objects.
 */
@property (readonly, nonnull) NSSet<ROAMVisit *> *currentVisits;

@end
