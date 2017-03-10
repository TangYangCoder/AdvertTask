/*---------------------------------------------------------------------------
 Copyright © TangYang. 2017. All rights reserved.
 File name:  AdvertSkipButton
 Author: TangYang ID:  Version: Implantable advertising Framework
 Description: 用于广告页面跳转
 Note:仅限用于图片,视频
 
 History: 2017 - Later
 ----------------------------------------------------------------------------*/

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
/**
 跳转按钮类型
 
 - SkipButtonTypeNone: 无
 - SkipButtonTypeTime: 倒计时
 - SkipButtonTypeText: 跳过
 - SkipButtonTypeTimeText: 倒计时+跳过(默认)
 */
typedef NS_ENUM(NSUInteger, SkipButtonType)
{
    SkipButtonTypeNone      = 0,
    SkipButtonTypeTime      = 1,
    SkipButtonTypeText      = 2,
    SkipButtonTypeTimeText  = 3
};

@interface AdvertSkipButton : UIButton
@property (nonatomic, strong) UILabel *timeLab;
@property (nonatomic, assign) CGFloat leftRightSpace;
@property (nonatomic, assign) CGFloat topBottomSpace;
@property (nonatomic, assign) SkipButtonType skipType;

-(void)stateWithskipType:(SkipButtonType)skipType andDuration:(double)duration;
@end

NS_ASSUME_NONNULL_END
