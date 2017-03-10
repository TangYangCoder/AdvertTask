/*---------------------------------------------------------------------------
   Copyright © 2017年 ChengDu SefonSoft CO.,LTD. All rights reserved.
   File name:  AdvertConfiguration.m
   Author: TangYang ID:  Version:  Date:17/3/8
   Description: 
   Others:
   Role:
   Note:
 
   History: 2017 - Later
 ----------------------------------------------------------------------------*/

#import "AdvertConfigurationM.h"

@implementation AdvertConfigurationM
- (instancetype)initWithDict:(NSDictionary *)dict
{
    self = [super init];
    if (self) {
        
        self.content = dict[@"content"];
        self.openUrl = dict[@"openUrl"];
        self.duration = [dict[@"duration"] integerValue];
        self.contentSize = dict[@"contentSize"];
    }
    return self;
}
-(CGFloat)width
{
    return [[[self.contentSize componentsSeparatedByString:@"*"] firstObject] floatValue];
}
-(CGFloat)height
{
    return [[[self.contentSize componentsSeparatedByString:@"*"] lastObject] floatValue];
}
@end
