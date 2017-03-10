/*---------------------------------------------------------------------------
 Copyright © TangYang. 2017. All rights reserved.
 File name:  AdvertDownload
 Author: TangYang ID:  Version: Implantable advertising SDK
 Description: 用于广告分类数据下载:AdvertImageDownload AdvertVideoDownload
 Note:仅限用于图片／视频  数据下载
 
 History: 2017 - Later
 ----------------------------------------------------------------------------*/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^AdvertDownloadProgressBlock)(unsigned long long total, unsigned long long current);

@protocol AdvertDownloadDelegate <NSObject>

- (void)downloadFinishWithURL:(nonnull NSURL *)url;

@end

@interface AdvertDownload : NSObject
@property (assign, nonatomic, nonnull) id<AdvertDownloadDelegate> delegate;
@end

typedef void(^AdvertDownloadImageCompletedBlock)(UIImage *_Nullable image, NSData * _Nullable data, NSError * _Nullable error);

@interface AdvertImageDownload : AdvertDownload
-(nonnull instancetype)initWithURL:(nonnull NSURL *)url delegateQueue:(nonnull NSOperationQueue *)queue progress:(nullable AdvertDownloadProgressBlock)progressBlock completed:(nullable AdvertDownloadImageCompletedBlock)completedBlock;
@end

typedef void(^AdvertDownloadVideoCompletedBlock)(NSURL * _Nullable location, NSError * _Nullable error);

@interface AdvertVideoDownload : AdvertDownload

-(nonnull instancetype)initWithURL:(nonnull NSURL *)url delegateQueue:(nonnull NSOperationQueue *)queue progress:(nullable AdvertDownloadProgressBlock)progressBlock completed:(nullable AdvertDownloadVideoCompletedBlock)completedBlock;
@end



NS_ASSUME_NONNULL_END
