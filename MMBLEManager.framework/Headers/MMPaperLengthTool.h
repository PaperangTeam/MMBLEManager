//
//  MMPaperLengthTool.h
//  Paperang
//
//  Created by 王明阳 on 2019/3/26.
//  Copyright © 2019 Hoho. All rights reserved.
//  纸张长度计算

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MMBLEManager/MMBLEManager.h>
#import "MMPaperModel.h"

//纸张长度类型
typedef enum : NSUInteger {
    PaperLengthTypeNone = 0,
    PaperLengthTypeA4,
    PaperLengthTypeA5,
    PaperLengthType16,
    PaperLengthType32,
    PaperLengthTypeOther
} PaperLengthType;

NS_ASSUME_NONNULL_BEGIN

@interface MMPaperLengthTool : NSObject
/**
 毫米转换成像素
 
 @param mmValue mmValue description
 @return return value descriptio
 */
+ (CGFloat)getLengthWithMMValue:(CGFloat)mmValue;

/**
 根据纸张类型获得显示长度
 
 @param type type description
 @return return value description
 */
+ (CGFloat)getLengthWithType:(PaperLengthType)type;


/**
 根据纸张长度类型获得长度，单位毫米

 @param lengthType lengthType description
 @return 毫米
 */
+ (CGFloat)getPaperHeightWithLengthType:(PaperLengthType)lengthType;


/**
 获得纸张展示内容最大宽度,单位毫米

 @return return value description
 */
+ (CGFloat)getPaperContentMaxWidthWithType:(MMDeviceType)deviceType;


/**
 获得纸张宽度字符串，可能与实际计算的宽度不一样,单位毫米

 @param deviceType deviceType description
 @return return value description
 */
+ (CGFloat)getShowPaperTotalWidthWithType:(MMDeviceType)deviceType ;


/**
 根据设备类型获得纸张总宽度,单位毫米

 @param deviceType deviceType description
 @return return value description
 */
+ (CGFloat)getPaperTotalWidthWithType:(MMDeviceType)deviceType;


/**
 调用getLengthWithImageSizes:(NSArray<NSValue *> *)imageSizes
            isContinuePrint:(BOOL)continuePrint
 isAddBlank为YES
 */
+ (CGFloat)getLengthWithImageSizes:(NSArray<NSValue *> *)imageSizes;

/**
 通过多个图片尺寸获取打印的纸张长度,单位毫米

 @param imageSizes 图片尺寸数组
 @param isAddBlank 是否添加空白走纸计算
 @return 打印的纸张长度(单位毫米)
 */
+ (CGFloat)getLengthWithImageSizes:(NSArray<NSValue *> *)imageSizes
                        isAddBlank:(BOOL)isAddBlank;

/**
 根据图片大小，计算出打印的纸张长度,单位毫米
 
 @param imageSize imageSize description
 @return return value description
 */
+ (CGFloat)getLengthWithImageSize:(CGSize)imageSize;


/**
 获得当前纸的总宽度，单位毫米

 @return return value description
 */
+ (CGFloat)getCurrentPaperTotalWidth;

/**
 获得当前纸的总宽度，单位毫米,可能与实际不一样

 @return return value description
 */
+ (CGFloat)getCurrentShowPaperTotalWidth;

/**
 获得固定打印长度的图片

 @param image 图片
 @param targetHeight_mm 目标长度，若太小则压缩;为0，则返回原图，单位毫米
 @return 图片
 */
+ (UIImage *)getPrintImageWithImage:(UIImage *)image
                    targetHeight_mm:(CGFloat)targetHeight_mm
                         deviceType:(MMDeviceType)type;


/**
 根据原始宽度，判断设备类型后，获得最终宽度

 @param value value description
 @return return value description
 */
+ (CGFloat)getTypeWidthWithValue:(CGFloat)value;

/**
 获得纸与默认纸(p1,p2等)的宽度倍数

 @param deviceType deviceType description
 @return return value description
 */
+ (CGFloat)getMultipleWithDeviceType:(MMDeviceType)deviceType;

+ (CGFloat)getCurrentMultiple;

@end

NS_ASSUME_NONNULL_END
