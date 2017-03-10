/*---------------------------------------------------------------------------
 Copyright © TangYang. 2017. All rights reserved.
 File name:  NSString+MD5
 Author: TangYang ID:  Version: General Framework
 Description: 用于本地缓存数据URL绝对路径 MD5解密
 Note:仅限用于图片,视屏缓存
 
 History: 2017 - Later
 ----------------------------------------------------------------------------*/

#import <Foundation/Foundation.h>

@interface NSString (MD5)
@property (nonatomic, assign, readonly) BOOL isURLString;
@property (nonatomic, copy, readonly,nonnull) NSString *videoName;
@property (nonatomic, copy, readonly,nonnull) NSString *md5String;

-(BOOL)containsSubString:(nonnull NSString *)subString;
@end
