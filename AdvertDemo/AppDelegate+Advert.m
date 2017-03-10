//
//  AppDelegate+Advert.m
//  AdvertDemo
//
//  Created by TangYang on 17/3/8.
//  Copyright © 2017年 ChengDu SefonSoft CO.,LTD. All rights reserved.
//

#import "AppDelegate+Advert.h"
#import "AdvertTask.h"
#import "AdvertConfigurationM.h"
#import "Network.h"
#import "WebViewController.h"

@interface AppDelegate() <AdvertTaskDelegate>

@end

@implementation AppDelegate (Advert)
- (void)performAdvertTask
{
//    [self imageNetworkRequest];
//    [self locationLoadingImage];
//    [self videoNetworkRequest];
    [self locationLoadingVideo];
}

//TODO: -- 1

- (void)imageNetworkRequest
{
    AdvertTask *advertTask = [[AdvertTask alloc] initWithDataSourceDuration:5.0];
    
    [Network getLaunchAdImageDataSuccess:^(NSDictionary *response) {
        NSLog(@"广告数据 = %@",response);
        AdvertConfigurationM *model = [[AdvertConfigurationM alloc] initWithDict:response[@"data"]];
        AdvertImageConfiguration *configuration = [[AdvertImageConfiguration alloc] init];
        configuration.duration = model.duration;
        //广告frame
        configuration.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.width/model.width*model.height);
        //广告图片URLString/或本地图片名(.jpg/.gif请带上后缀)
        configuration.imageNameOrURLString = model.content;
        //缓存机制(仅对网络图片有效)
        configuration.imageOption = ADImageCacheDefault;
        //图片填充模式
        configuration.contentMode = UIViewContentModeScaleToFill;
        //广告点击打开链接
        configuration.openURLString = @"http://blog.sina.com.cn/u/3302479065";
        //广告显示完成动画
        configuration.finishAnimationStyle = FinishAnimationFadein;
        //跳过按钮类型
        configuration.skipButtonType = SkipButtonTypeTimeText;
        //后台返回时,是否显示广告
        configuration.showEnterForeground = NO;
        
#warning :  这里可以自定义跳转按钮的样式
        //start********************自定义跳过按钮**************************
        //configuration.customSkipView = [self customSkipView];
        //********************自定义跳过按钮*****************************end
        
        if ([AdvertTask checkImageInCacheWithURL:[NSURL URLWithString:model.content]])
        {
            configuration.subViews = [self setThePreloadingButton];
        }
        [advertTask performAdvertImageConfiguration:configuration delegate:self];
        
    } failure:^(NSError *error) {
        
    }];
}

//TODO: -- 2

- (void)locationLoadingImage
{
    AdvertImageConfiguration *configuration = [[AdvertImageConfiguration alloc] init];
    configuration.duration = 5;
    configuration.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.width/1242*1786);
    //广告图片URLString/或本地图片名(.jpg/.gif请带上后缀)
    configuration.imageNameOrURLString = @"image2.jpg";
    //缓存机制(仅对网络图片有效)
    configuration.imageOption = ADImageCacheLastUpdateData ;
    //图片填充模式
    configuration.contentMode = UIViewContentModeScaleToFill;
    //广告点击打开链接
    configuration.openURLString = @"http://blog.sina.com.cn/u/3302479065";
    //广告显示完成动画
    configuration.finishAnimationStyle = FinishAnimationFadein;
    //跳过按钮类型
    configuration.skipButtonType = SkipButtonTypeTimeText;
    //后台返回时,是否显示广告
    configuration.showEnterForeground = NO;
    
    [AdvertTask performAdvertImageConfiguration:configuration delegate:self];
}

//TODO: -- 3

- (void)videoNetworkRequest
{
    //!!!: 第一次启动不会加载,因为在下载,如果第二次也没加载,说命第一次没下载完，以此类推
    [AdvertTask setWaitDataSourceDuration:3];
    [Network getLaunchAdVideoDataSuccess:^(NSDictionary *response) {
        NSLog(@"广告数据 = %@",response);
        AdvertConfigurationM *model = [[AdvertConfigurationM alloc] initWithDict:response[@"data"]];
        AdvertVideoConfiguration *configuration = [[AdvertVideoConfiguration alloc] init];
        configuration.duration = model.duration;
        //广告frame
        configuration.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.width/model.width*model.height);
        configuration.videoNameOrURLString = model.content;
        //广告点击打开链接
        configuration.openURLString =  @"http://blog.sina.com.cn/u/3302479065";
        //广告显示完成动画
        configuration.finishAnimationStyle = FinishAnimationFadein;
        //跳过按钮类型
        configuration.skipButtonType = SkipButtonTypeTimeText;
        //后台返回时,是否显示广告
        configuration.showEnterForeground = NO;
        
        if ([AdvertTask checkVideoInCacheWithURL:[NSURL URLWithString:model.content]])
        {
            configuration.subViews = [self setThePreloadingButton];
        }
        [AdvertTask performAdvertVideoConfiguration:configuration delegate:self];
        
    } failure:^(NSError *error) {
        
    }];
}

- (void)locationLoadingVideo
{
    AdvertVideoConfiguration *configuration = [[AdvertVideoConfiguration alloc] init];
    configuration.duration = 5.00;
    configuration.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height);
    configuration.videoNameOrURLString = @"video1.mp4";
    configuration.openURLString =  @"http://blog.sina.com.cn/u/3302479065";
    configuration.finishAnimationStyle = FinishAnimationFadein;
    configuration.skipButtonType = SkipButtonTypeTimeText;
    configuration.showEnterForeground = NO;
    [AdvertTask performAdvertVideoConfiguration:configuration delegate:self];
}

-(NSArray<UIView *> *)setThePreloadingButton
{
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake([UIScreen mainScreen].bounds.size.width-140, 30, 60, 30)];
    label.text  = @"已预载";
    label.font = [UIFont systemFontOfSize:12];
    label.textColor = [UIColor whiteColor];
    label.textAlignment = NSTextAlignmentCenter;
    label.layer.cornerRadius = 5.0;
    label.layer.masksToBounds = YES;
    label.backgroundColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0.5];
    return [NSArray arrayWithObject:label];
    
}

//MARK:自定义跳过按钮

-(UIView *)customSkipView
{
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.backgroundColor =[UIColor orangeColor];
    button.layer.cornerRadius = 5.0;
    button.layer.borderWidth = 1.5;
    button.layer.borderColor = [UIColor lightGrayColor].CGColor;
    [button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    button.titleLabel.font = [UIFont systemFontOfSize:14];
    button.frame = CGRectMake([UIScreen mainScreen].bounds.size.width-100,30, 85, 40);
    [button addTarget:self action:@selector(skipAction) forControlEvents:UIControlEventTouchUpInside];
    return button;
}

//MARK:AdvertTaskDelegate

- (void)applicationPerform:(AdvertTask *)advertTask openURLString:(NSString *)openURLString
{
    NSLog(@"---广告点击---");
    if (openURLString)
    {
        WebViewController *webVC = [[WebViewController alloc] init];
        webVC.URLString = openURLString;
        [self.window.rootViewController presentViewController:webVC animated:YES completion:nil];
    }
}

- (void)applicationPerform:(AdvertTask *)advertTask imageCompleteDownload:(UIImage *)image
{
    NSLog(@"图片下载完成/或本地图片读取完成回调 image:%@",image);
}

- (void)applicationPerformFinished:(AdvertTask *)advertTask
{
    NSLog(@"广告显示完成");
    NSLog(@"path:%@",[AdvertTask AdvertCachePath]);
}

- (void)applicationPerform:(AdvertTask *)advertTask videoCompleteDownload:(NSURL *)pathURL
{
    NSLog(@"video下载/加载完成/保存path = %@",pathURL.absoluteString);
}

- (void)applicationPerform:(AdvertTask *)advertTask videoDownLoadProgress:(float)progress total:(unsigned long long)total current:(unsigned long long)current
{
    NSLog(@"总大小=%lld,已下载大小=%lld,下载进度=%f",total,current,progress);
}


@end
