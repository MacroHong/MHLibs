//
//  DEFINE.h
//
//  defines for iOS project


// 全局宏



#ifndef DEFINE_h
#define DEFINE_h

//#import "AppDelegate.h"


// MARK:    -----调试打印-----
#ifdef DEBUG
#define ISDEBUG 1
#else
#define ISDEBUG 0
#endif
// 调试时才打印 printf  NSLog
#define DebugLog(s, ...) if(ISDEBUG) {\
printf("\n*************DebugLog*************\n");\
printf("path:%s\n", __FILE__);\
printf("lines:%d, time:%s\n", __LINE__, __TIME__);\
printf("%s\n", [[NSString stringWithFormat:s, ## __VA_ARGS__] UTF8String]);\
printf("\n***********EndOfDebugLog**********\n\n\n");\
}


// MARK:    -----屏幕宽高-----
/*屏幕宽度*/
#define kWidth [[UIScreen mainScreen] bounds].size.width

/*屏幕高度*/
#define HHH [[UIScreen mainScreen] bounds].size.height
#define kHeight (HHH==812.0 ? HHH-34 : HHH)

#define kStateBarHeight ([UIApplication sharedApplication].statusBarFrame.size.height)



/*导航栏高度*/
#define kNavbarHeight (HHH==812.0 ? 84 : 64)

// MARK:    -----版本判断-----
/*当前版本号，一位小数*/
#define CurrentVersion [[[UIDevice currentDevice] systemVersion] floatValue]
/*当前版本号，整数*/
#define IsIOS(version) (CurrentVersion>(version##.0f-1) && CurrentVersion<(version##.0f+1))
/*当前版本不低于*/
#define IsIOSHeigher(minVersion) (CurrentVersion >= minVersion##.0f)
/*当前版本不高于*/
#define IsIOSLower(maxVersion) (CurrentVersion <= maxVersion##.0f)


// MARK:    -----系统单例-----
/*AppDelegate单例, 需要导入"AppDelegate.h"**/
#define APPDELEGATE ((AppDelegate *)[[UIApplication sharedApplication] delegate])

/*唯一Window, 需要导入"AppDelegate.h"*/
#define WINDOW (((AppDelegate *)[[UIApplication sharedApplication] delegate]).window)


// MARK:    -----颜色相关-----
// 随机色
#define RandomColor [UIColor colorWithRed:(arc4random()%255)/255.0 green:(arc4random()%255)/255.0 blue:(arc4random()%255)/255.0 alpha:1]

// 十六进制颜色
#define RGBCOLOR(color) [UIColor colorWithRed:(((color)>>16)&0xff)*1.0/255.0 green:(((color)>>8)&0xff)*1.0/255.0 blue:((color)&0xff)*1.0/255.0 alpha:1.0]


// MARK:    -----解除循环引用-----
// block外调用
#define WeakSelf(type)  __weak typeof(type) weak##type = type
// block内调用
#define StrongSelf(type)  __strong typeof(type) type = weak##type


// MARK:    -----国际化-----
#define L10NString(key) [[NSBundle mainBundle] localizedStringForKey:key value:@"" table:@"L10N"]


// MARK:    -----单例-----
#define MHSharedInstance_h(className) + (className *)sharedInstance;

#define MHSharedInstance_m(className) \
+ (className *)sharedInstance{ \
static className *sharedSingleton = nil; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^(void){ \
sharedSingleton = [[className alloc] init]; \
}); \
return sharedSingleton; \
}


#endif /* DEFINE_h */
