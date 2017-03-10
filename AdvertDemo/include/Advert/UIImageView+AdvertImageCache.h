#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "AdvertImageManager.h"

@interface UIImageView (AdvertImageCache)
- (void)ad_setImageWithURL:(nonnull NSURL *)url;

- (void)ad_setImageWithURL:(nonnull NSURL *)url placeholderImage:(nullable UIImage *)placeholder;

- (void)ad_setImageWithURL:(nonnull NSURL *)url placeholderImage:(nullable UIImage *)placeholder options:(ADImageOptions)options;

- (void)ad_setImageWithURL:(nonnull NSURL *)url placeholderImage:(nullable UIImage *)placeholder completed:(nullable ExternalCompletionBlock)completedBlock;

- (void)ad_setImageWithURL:(nonnull NSURL *)url completed:(nullable ExternalCompletionBlock)completedBlock;

- (void)ad_setImageWithURL:(nonnull NSURL *)url placeholderImage:(nullable UIImage *)placeholder options:(ADImageOptions)options completed:(nullable ExternalCompletionBlock)completedBlock;
@end
