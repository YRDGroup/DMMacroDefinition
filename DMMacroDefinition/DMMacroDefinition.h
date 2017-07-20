//
//  DMMacroDefinition.h
//  DMMacroDefinitionDemo
//
//  Created by 李二狗 on 2017/7/5.
//  Copyright © 2017年 YRHY Science and Technology (Beijing) Co., Ltd. All rights reserved.
//

#ifndef DMMacroDefinition_h
#define DMMacroDefinition_h

//NSLog宏定义
#ifndef __OPTIMIZE__
#define NSLog(...) NSLog(__VA_ARGS__)
#else
#define NSLog(...) {}
#endif

#define __AppFrame                         [__MainScreen applicationFrame]  //{{0, 20}, {320, 460}}
//屏幕尺寸
#define __MainScreen                       [UIScreen mainScreen]            //{{0, 0}, {320, 480}}
//屏幕宽度
#define __Screen_W                    (__MainScreen.bounds.size.width)
//屏幕高度
#define __Screen_H                    (__MainScreen.bounds.size.height)

//不包括状态栏的导航高度
#define __Nav_H                       44
//状态栏高度
#define __StatusBar_H                 20
//导航栏，iOS7 以前是44. 不再考虑
#define __StatusNav_H                 (__StatusBar_H + __Nav_H)
//tabbar height
#define __Tabbar_H                    49
//1像素的高度，多用于cell的底部分割线
#define __OnePixel (1.0 / __MainScreen.scale)

//获取图片资源
#define __DMGetImage(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]

//弱引用，使用weakSelf调用
#define __DMWeakSelf(type)  __weak typeof(type) weak##type = type;
#define __DMStrongSelf(type)  __strong typeof(type) type = weak##type;

//判断当前的iPhone设备/系统版本
//判断是否为iPhone
#define __ISIPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

//判断是否为iPad
#define __ISIPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//判断是否为ipod
#define __ISIPOD ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

//是否是 iPhone4 尺寸的手机
#define __ISIPHONE4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)

//是否是 iPhone5 尺寸的手机
#define __ISIPHONE5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

//是否是 iPhone6 尺寸的手机
#define __ISIPHONE6  ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? (CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size)) : NO)

//是否是 iPhone6P 尺寸的手机
#define __ISIPHONE6P ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? (CGSizeEqualToSize(CGSizeMake(1125, 2001), [[UIScreen mainScreen] currentMode].size) || CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size)) : NO)

//获取系统版本
//获取当前系统版本
#define __IOS_SYSTEM_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define __IOS_SYSTEM_STRING [[UIDevice currentDevice] systemVersion]

//判断 iOS 8 或更高的系统版本
#define __IS_iOS8_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >=8.0)? (YES):(NO))
//判断 iOS 9 或更高的系统版本
#define __IS_iOS9_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >=9.0)? (YES):(NO))
//判断 iOS 10 或更高的系统版本
#define __IS_iOS10_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >=10.0)? (YES):(NO))

//网络状态判断
#define __IsWifiConnected     \
([[Reachability reachabilityForInternetConnection] currentReachabilityStatus] == ReachableViaWiFi)
#define __IsWWANConnected     \
([[Reachability reachabilityForInternetConnection] currentReachabilityStatus] == ReachableViaWWAN)
#define __IsNetWorkConnected  \
(__IsWifiConnected || __IsWWANConnected)

#endif /* DMMacroDefinition_h */
