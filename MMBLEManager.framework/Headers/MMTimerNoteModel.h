//
//  MMTimerNoteModel.h
//  Paperang
//
//  Created by 王明阳 on 2019/6/18.
//  Copyright © 2019 Hoho. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, MMTimerNoteType) {
    MMTimerNoteTypeTomato,
    MMTimerNoteTypeAlarm,
};

#define MMTimerNoteModelUpdateNotification @"MMTimerNoteModelUpdateNotification"

#define MMTimerNoteModelSelectNotification @"MMTimerNoteModelSelectNotification"

NS_ASSUME_NONNULL_BEGIN

@interface MMTimerNoteModel : NSObject

@property (nonatomic,copy) NSString *content;
@property (nonatomic,assign) BOOL isDefault;
@property (nonatomic,assign) BOOL isSelect;
@property (nonatomic,copy) NSString *paperId;
@property (nonatomic,copy) NSString *paperImg;
@property (nonatomic,copy) NSString *title;

@property (nonatomic,assign) MMTimerNoteType noteType;

@property (nonatomic,strong,nullable) UIImage *showImage;
@property (nonatomic,strong,nullable) UIImage *printImage;

+ (UIImage *)getTargetImageWithImage:(UIImage *)image
                                text:(NSString *)text
                               width:(CGFloat)width;

@end

NS_ASSUME_NONNULL_END
