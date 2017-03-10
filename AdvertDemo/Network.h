/*---------------------------------------------------------------------------
   Copyright © 2017年 ChengDu SefonSoft CO.,LTD. All rights reserved.
   File name:  Network.h
   Author: TangYang ID:  Version:  Date:17/3/8
   Description: 
   Others:
   Role:
   Note:
 
   History: 2017 - Later
 ----------------------------------------------------------------------------*/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^NetworkSucess) (NSDictionary * response);
typedef void(^NetworkFailure) (NSError *error);

@interface Network : NSObject

/**
 *  此处用于模拟广告数据请求,实际项目中请做真实请求
 */
+(void)getLaunchAdImageDataSuccess:(NetworkSucess)success failure:(NetworkFailure)failure;
+(void)getLaunchAdVideoDataSuccess:(NetworkSucess)success failure:(NetworkFailure)failure;

@end

NS_ASSUME_NONNULL_END
