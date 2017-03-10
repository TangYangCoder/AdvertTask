/*---------------------------------------------------------------------------
 Copyright © TangYang. 2017. All rights reserved.
 File name:  UIImage+Cache
 Author: TangYang ID:  Version: General Framework
 Description: 用于UIImage缓存
 Note:仅限用于图片
 
 History: 2017 - Later
 ----------------------------------------------------------------------------*/
#import <UIKit/UIKit.h>

@interface UIImage (Cache)
+ (__kindof UIImage *)imageCacheWithName:(NSString *)imageName;
+ (__kindof UIImage *)imageCacheWithData:(NSData *)imageData;
@end
