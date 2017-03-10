/*---------------------------------------------------------------------------
 Copyright © TangYang. 2017. All rights reserved.
 File name:  AdvertConfiguration
 Author: TangYang ID:  Version: Implantable advertising Framework
 Description: 用于广告分类数据配置:AdvertImageConfiguration AdvertVideoConfiguration
 Note:仅限用于图片／视频  Model类数据传递
 
 History: 2017 - Later
 ----------------------------------------------------------------------------*/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdvertImageManager.h"
#import "AdvertSkipButton.h"

NS_ASSUME_NONNULL_BEGIN

/**
 广告加载完成后跳转动画样式
 
 - FinishAnimationNone: 无
 - FinishAnimationFadein: 淡入(默认)
 - FinishAnimationLite:  放大淡入
 */
typedef NS_OPTIONS(NSUInteger, FinishAnimationStyle)
{
    FinishAnimationNone = 2 << 0,
    FinishAnimationFadein = 2 << 1,
    FinishAnimationLite = 2 << 2
};


@interface AdvertConfiguration : NSObject
//停留时间 默认5s
@property (nonatomic, assign) double duration;
//跳过按钮类型 默认SkipButtonTypeTimeText
@property (nonatomic, assign) SkipButtonType skipButtonType;
//广告加载完成后跳转动画 默认FinishAnimationFadein
@property (nonatomic, assign) FinishAnimationStyle finishAnimationStyle;
//设置开屏广告的frame 默认全屏
@property (nonatomic, assign) CGRect frame;
//程序从后台恢复时,是否需要展示广告 默认 NO
@property (nonatomic, assign) BOOL showEnterForeground;
//点击打开广告链接
@property (nonatomic,   copy) NSString *openURLString;
//自定义跳过按钮(若定义此视图,将会自定替换系统跳过按钮)
@property (nonatomic, strong) UIView *customSkipView;
//子视图(若定义此属性,这些视图将会被自动添加在广告视图上)
@property(nonatomic,copy,nullable) NSArray<UIView *> *subViews;
@end

@interface AdvertImageConfiguration : AdvertConfiguration
//图片广告缩放模式 default UIViewContentModeScaleToFill
@property (nonatomic, assign) UIViewContentMode contentMode;
//image本地图片名(jpg/gif图片请带上扩展名)或网络图片URL string
@property (nonatomic,   copy) NSString *imageNameOrURLString;
//缓存机制 default AdImageCacheDefault
@property (nonatomic, assign) ADImageOptions imageOption;
+ (AdvertImageConfiguration *)defaultConfiguration;
@end

@interface AdvertVideoConfiguration : AdvertConfiguration

//video本地名或网络链接URL string
@property(nonatomic,copy)NSString *videoNameOrURLString;
+ (AdvertVideoConfiguration *)defaultConfiguration;
@end

NS_ASSUME_NONNULL_END
