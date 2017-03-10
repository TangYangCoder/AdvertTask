/*---------------------------------------------------------------------------
 Copyright © TangYang. 2017. All rights reserved.
 File name:  AdvertView
 Author: TangYang ID:  Version: Implantable advertising Framework
 Description: 用于广告打底页面展示样式
 Note:仅限用于图片,视频
 
 History: 2017 - Later
 ----------------------------------------------------------------------------*/

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import <AVKit/AVKit.h>

typedef void (^AdvertClickBlock)(void);
typedef NS_ENUM(NSUInteger, VideoScalingMode)
{
    VideoScalingModeAspectFill = 0
};

@interface AdvertView : UIImageView
@property (nonatomic, copy) AdvertClickBlock advertClickBlock;
@end

@interface AdvertImageView : AdvertView

@end

@interface AdvertVideoView : AdvertView
@property (nonatomic, strong) AVPlayer *player;
@property (nonatomic, assign) VideoScalingMode videoScalingMode;
- (void)playWithURL:(NSURL *)url;
@end
