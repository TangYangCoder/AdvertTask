/*---------------------------------------------------------------------------
 Copyright © TangYang. 2017. All rights reserved.
 File name:  AdvertTask
 Author: TangYang ID:  Version: Implantable advertising Framework
 Description: 用于广告数据配置,任务的启动
 Note:仅限用于图片,视频
 
 History: 2017 - Later
 ----------------------------------------------------------------------------*/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdvertConfiguration.h"

#define DefaultDurationKey  3.00
#define ADTASK [AdvertTask shareInstance]

NS_ASSUME_NONNULL_BEGIN

@class AdvertTask;

@protocol AdvertTaskDelegate <NSObject>

@optional
/**
 *  @author Tangyang
 *
 *  @brief 广告接入详情
 *
 *  @param advertTask           执行广告任务
 *  @param openURLString        打开页面链接
 */

- (void)applicationPerform:(AdvertTask *)advertTask openURLString:(NSString *)openURLString;

/**
 *  @author Tangyang
 *
 *  @brief 广告任务执行完成
 */
- (void)applicationPerformFinished:(AdvertTask *)advertTask;

/**
 *  @author Tangyang
 *
 *  @brief  倒计时回调
 *
 *  @param advertTask     执行广告任务
 *  @param loadingview    跳过加载广告页
 *  @param duration       倒计时时间
 */
- (void)applicationPerform:(AdvertTask *)advertTask skipLoadingView:(UIView *)loadingview duration:(double)duration;

///==================
///   图片广告相关协议
///==================
/**
 *  @author Tangyang
 *
 *  @brief 图片本地读取或下载完成回调
 *
 *  @param advertTask     执行广告任务
 *  @param image          下载完成的image对象
 */
- (void)applicationPerform:(AdvertTask *)advertTask imageCompleteDownload:(UIImage *)image;

/**
 *  @author Tangyang
 *
 *  @brief  SDWebImage 等及其它框架加载网络广告图片的缓存策略
 *
 *  @param advertTask      执行广告任务
 *  @param imageView       启动广告图片视图
 *  @param url             图片URL
 */
- (void)applicationPerform:(AdvertTask *)advertTask loadingAdvertImageView:(UIImageView *)imageView imageURL:(NSURL *)url;

///==================
///   视频广告相关协议
///==================
/**
 *  @author Tangyang
 *
 *  @brief 视频本地读取或下载完成回调
 *
 *  @param advertTask     执行广告任务
 *  @param pathURL        本地保存路径
 */
- (void)applicationPerform:(AdvertTask *)advertTask videoCompleteDownload:(NSURL *)pathURL;

/**
 *  @author Tangyang
 *
 *  @brief 视频下载进度回调

 *  @param advertTask 执行广告任务
 *  @param progress 下载进度
 *  @param total    总大小
 *  @param current  当前已下载大小
 */
- (void)applicationPerform:(AdvertTask *)advertTask  videoDownLoadProgress:(float)progress total:(unsigned long long)total current:(unsigned long long)current;

@end


@interface AdvertTask : NSObject
@property (nonatomic, weak) id<AdvertTaskDelegate> delegate;

/**
 初始化设置等待数据源时间

 @param duration `默认是 3s`
 */
- (instancetype)initWithDataSourceDuration:(double)duration;

/**
 设置等待数据源时间
 
 @param duration `默认是 3s`
 */
+ (void)setWaitDataSourceDuration:(double)duration;

/**
 图片开屏广告数据普通配置

 @param advertImageConfiguration 图片数据配置Model对象
 @return AdvertTask 对象
 */
+ (AdvertTask *)performAdvertImageConfiguration:(AdvertImageConfiguration *)advertImageConfiguration;

/**
 图片开屏广告数据代理配置

 @param advertImageConfiguration 图片数据配置Model对象
 @param delegate 关联代理
 @return AdvertTask 对象
 */
+ (AdvertTask *)performAdvertImageConfiguration:(AdvertImageConfiguration *)advertImageConfiguration delegate:(nullable id<AdvertTaskDelegate>)delegate;
- (AdvertTask *)performAdvertImageConfiguration:(AdvertImageConfiguration *)advertImageConfiguration delegate:(nullable id<AdvertTaskDelegate>)delegate;

/**
 批量下载并缓存image(异步)
 
 @param urlArray image URL Array
 */
+ (void)downloadImageAndCacheWithURLArray:(NSArray <NSURL *> * )urlArray;

/**
 视频开屏广告数据配置

 @param videoAdconfiguration 数据配置
 @return AdvertTask 对象
 */
+ (AdvertTask *)performAdvertVideoConfiguration:(AdvertVideoConfiguration *)videoAdconfiguration;

/**
 视频开屏广告数据配置

 @param advertVideoConfiguration 数据配置
 @param delegate delegate 关联代理
 @return AdvertTask 对象
 */
+ (AdvertTask *)performAdvertVideoConfiguration:(AdvertVideoConfiguration *)advertVideoConfiguration delegate:(nullable id<AdvertTaskDelegate>)delegate;
- (AdvertTask *)performAdvertVideoConfiguration:(AdvertVideoConfiguration *)advertVideoConfiguration delegate:(nullable id<AdvertTaskDelegate>)delegate;

/**
 批量下载并缓存视频(异步)
 
 @param urlArray 视频 URL Array
 */
+ (void)downloadVideoAndCacheWithURLArray:(NSArray <NSURL *> * )urlArray;


#pragma mark ---------------------
/**
 *  跳过按钮事件
 */
+ (void)skipAction;
- (void)skipAction;

///===============================
///作用:缓存相关
///===============================
/**
 *  是否已缓存在该图片
 *
 *  @param url image url
 *
 *  @return BOOL
 */
+ (BOOL)checkImageInCacheWithURL:(NSURL *)url;

/**
 *  是否已缓存该视频
 *
 *  @param url video url
 *
 *  @return BOOL
 */
+ (BOOL)checkVideoInCacheWithURL:(NSURL *)url;

#pragma mark - 缓存清除及大小

/**
 *  清除本地缓存
 */
+ (void)clearAdvertCache;

/**
 *  获取本地缓存Ad大小(M)
 */
+ (float)AdvertCacheSize;

/**
 *  缓存路径
 */
+ (NSString *)AdvertCachePath;

@end

NS_ASSUME_NONNULL_END
