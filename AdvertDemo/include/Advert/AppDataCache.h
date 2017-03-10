/*---------------------------------------------------------------------------
 Copyright © TangYang. 2017. All rights reserved.
 File name:  AppDataCache.h
 Author: TangYang ID:  Version: General Framework
 Description: 用于本地缓存
 Note:仅限用于图片,视屏缓存
 
 History: 2017 - Later
 ----------------------------------------------------------------------------*/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^VideoStorageCompletionBlock)(BOOL result , NSURL * pathURL);

@interface AppDataCache : NSObject

/**
 从缓存的图片URL中获取图片

 @param url 图片url
 @return 获取的image对象
 */
+ (UIImage *)getCacheImageWithURL:(NSURL *)url;

/**
 缓存图片

 @param data 图片转二进制数据
 @param url 图片url
 @return YES成功 NO不存储或失败
 */
+ (BOOL)saveImageData:(NSData *)data imageURL:(NSURL *)url;

/**
 缓存图片 - 异步

 @param data 图片转二进制数据
 @param url 图片url
 */
+ (void)async_saveImageData:(NSData *)data imageURL:(NSURL *)url;

/**
 检查是否已缓存在该图片url

 @param url 图片url
 @return BOOL
 */
+ (BOOL)checkImageInCacheWithURL:(NSURL *)url;

/**
 检查是否已缓存该视频url

 @param url video url
 @return BOOL
 */
+ (BOOL)checkVideoInCacheWithURL:(NSURL *)url;

/**
 获取缓存视频路径

 @param url 视频链接url
 @return 视频本地路径
 */
+ (nullable NSURL *)getCacheVideoWithURL:(NSURL *)url;

/**
 保存视频到缓存目录

 @param location 视频路径
 @param url 视频url
 @return 视频保存路径
 */
+ (nullable NSURL *)saveVideoAtLocation:(NSURL *)location URL:(NSURL *)url;

/**
 保存视频到缓存目录 - 异步

 @param location 视频路径
 @param url 视频url
 */
+ (void)async_saveVideoAtLocation:(NSURL *)location URL:(NSURL *)url;

/**
 缓存路径
 默认是保存在:Library/appCacheData/encryptFile路径下
 @return 缓存路径
 */
+ (NSString *)applicationDataCachePath;

/**
 生成视频路径

 @param url 视频url
 @return url生成视频路径
 */
+ (NSString *)videoPathWithURL:(NSURL *)url;

/**
 清除本地缓存
 */
+ (void)clearDiskCache;

/**
 @return 本地缓存大小(M)
 */
+ (float)diskCacheSize;
@end

NS_ASSUME_NONNULL_END
