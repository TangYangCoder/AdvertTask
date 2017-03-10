/*---------------------------------------------------------------------------
 Copyright © TangYang. 2017. All rights reserved.
 File name:  AdvertImageManager
 Author: TangYang ID:  Version: Implantable advertising Framework
 Description: 用于管理图片广告缓存方式
 Note:仅限用于图片／视频
 
 History: 2017 - Later
 ----------------------------------------------------------------------------*/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdvertDownloader.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ExternalCompletionBlock)(UIImage * _Nullable image, NSError * _Nullable error, NSURL * _Nullable imageURL);

/**
 广告图片的操作方式
 
 - ADImageCacheDefault: 有缓存,读取缓存,不重新加载,没缓存先加载,并缓存
 - ADImageLoadingDefault: 只加载,不缓存
 - ADImageCacheLastUpdateData: 先读缓存,再加载刷新图片和缓存
 - ADImageCacheInBackground: 后台缓存本次不显示,缓存OK后下次再显示
 */
typedef NS_OPTIONS(NSUInteger, ADImageOptions)
{
    ADImageCacheDefault = 1 << 0,
    ADImageLoadingDefault = 1 << 1,
    ADImageCacheLastUpdateData = 1 << 2,
    ADImageCacheInBackground = 1 << 3
};

@interface AdvertImageManager : NSObject
+ (instancetype)sharedManager;
- (void)loadImageWithURL:(NSURL *)url options:(ADImageOptions)options  progress:(nullable AdvertDownloadProgressBlock)progressBlock completed:(ExternalCompletionBlock)completedBlock;
@end

NS_ASSUME_NONNULL_END
