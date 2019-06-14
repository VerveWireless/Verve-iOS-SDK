
#import <Foundation/Foundation.h>

/**
 A `ROAMPlace` object encapsulates information about a place. The place includes details entered in the Roam Developer
 portal such as name and properties, and hence managed exclusively via the developer portal.
 */
NS_SWIFT_NAME(Place)
@interface ROAMPlace : NSObject <NSCopying, NSSecureCoding>

/**
 A unique identifier representing the place object. You use this identifier to differentiate each place within
 your application.
 */
@property (readonly, nonnull) NSString *identifier;

/**
 The name of the place as it was entered in the Roam Developer Portal.
 */
@property (readonly, nonnull) NSString *name;

/**
 The key-value pair property descriptions assigned to the place as it was entered in the Roam Developer Portal.
 @note Use this property to store custom attributes that are related to this place.
 */
@property (readonly, nonnull) NSDictionary<NSString *, NSString *> *properties;

@end
