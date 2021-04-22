//
//  MMPaperHoleModel.h
//  Paperang
//
//  Created by 王明阳 on 2019/9/3.
//  Copyright © 2019 Hoho. All rights reserved.
//  装订孔参数

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MMPaperHoleModel : NSObject
//（仅限C1）装订孔共2组，每组3孔，孔为虚线，直径0.5cm，每孔间隔距离为1.4cm，两组间距为4.5cm。装订孔距离打印纸最左边0.5cm，装订孔为页面纵向居中位置

@property (nonatomic,assign) NSInteger groupCount;

@property (nonatomic,assign) NSInteger countPerGroup;

@property (nonatomic,assign) CGFloat radius_mm;//半径

@property (nonatomic,assign) CGFloat space_mm;

@property (nonatomic,assign) CGFloat groupSpace_mm;

@property (nonatomic,assign) CGFloat leftMargin_mm;

@property (nonatomic,assign) CGFloat contentLeftMarginPercent;

@end

NS_ASSUME_NONNULL_END
