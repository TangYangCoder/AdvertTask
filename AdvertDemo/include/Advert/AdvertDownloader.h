/*---------------------------------------------------------------------------
 Copyright © TangYang. 2017. All rights reserved.
 File name:  AdvertDownloader
 Author: TangYang ID:  Version: Implantable advertising SDK
 Description: 用于广告分类数据下载,下载完成后进行多线程操作缓存
 Note:仅限用于图片／视频  数据缓存策略
 
 History: 2017 - Later
 ----------------------------------------------------------------------------*/

#import <Foundation/Foundation.h>
#import "AdvertDownload.h"

NS_ASSUME_NONNULL_BEGIN

@interface AdvertDownloader : NSObject
+(nonnull instancetype )sharedDownloader;

- (void)downloadImageWithURL:(nonnull NSURL *)url progress:(nullable AdvertDownloadProgressBlock)progressBlock completed:(nullable AdvertDownloadImageCompletedBlock)completedBlock;

- (void)downLoadImageAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray;

- (void)downloadVideoWithURL:(nonnull NSURL *)url progress:(nullable AdvertDownloadProgressBlock)progressBlock completed:(nullable AdvertDownloadVideoCompletedBlock)completedBlock;

- (void)downLoadVideoAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray;
@end

NS_ASSUME_NONNULL_END
