#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ImplClass : NSObject

- (instancetype)init;

@property (assign) NSInteger implProperty;
@property (assign) NSInteger defaultIntProperty;

+ (void)runTests;
- (nonnull NSString *)someMethod;

@end

NS_ASSUME_NONNULL_END
