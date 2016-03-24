// Generated by Apple Swift version 2.1 (swiftlang-700.1.101.6 clang-700.1.76)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#if defined(__has_feature) && __has_feature(modules)
@import UIKit;
@import CoreGraphics;
@import ObjectiveC;
@import LPInfra;
@import Foundation;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class NSCoder;

SWIFT_CLASS("_TtC14LPMessagingSDK17AgentIsTypingView")
@interface AgentIsTypingView : UIView
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@protocol UIAdapterDelegate;

SWIFT_PROTOCOL("_TtP14LPMessagingSDK39ConversationViewControllerAgentDelegate_")
@protocol ConversationViewControllerAgentDelegate
@optional
- (void)agentDidChangeUserInputText:(NSString * __nonnull)text;
- (void)setUIAdapterDelegate:(id <UIAdapterDelegate> __nonnull)delegate;
@end


SWIFT_CLASS("_TtC14LPMessagingSDK5LPLog")
@interface LPLog : NSObject
@property (nonatomic, copy) NSString * __nullable timestamp;
@property (nonatomic, copy) NSString * __nullable className;
@property (nonatomic, copy) NSString * __nullable funcName;
@property (nonatomic, copy) NSString * __nullable text;
@end

@protocol ConversationParamProtocol;
@class UIViewController;
@class LPUser;
@class NSData;
@protocol LPMessagingSDKNotificationDelegate;
@class UIImage;
@protocol LPMessagingSDKdelegate;

SWIFT_CLASS("_TtC14LPMessagingSDK14LPMessagingSDK")
@interface LPMessagingSDK : NSObject <UINavigationControllerDelegate>
@property (nonatomic, weak) id <LPMessagingSDKdelegate> __nullable delegate;
@property (nonatomic, weak) id <LPMessagingSDKNotificationDelegate> __nullable notificationDelegate;
@property (nonatomic, copy) NSString * __nullable accountID;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
+ (LPMessagingSDK * __nonnull)instance;
- (void)initialize:(NSString * __nullable)brandID;
- (void)showConversation:(id <ConversationParamProtocol> __nonnull)conversationQuery authenticationCode:(NSString * __nullable)authenticationCode containerViewController:(UIViewController * __nullable)containerViewController;
- (void)removeConversation:(id <ConversationParamProtocol> __nonnull)conversationQuery;
- (void)reconnect:(id <ConversationParamProtocol> __nonnull)conversationQuery authenticationCode:(NSString * __nonnull)authenticationCode;
- (void)toggleChatActions:(NSString * __nonnull)accountID;
- (void)setUserProfile:(LPUser * __nonnull)lpuser accountID:(NSString * __nonnull)accountID;
- (void)handlePush:(NSDictionary * __nonnull)userInfo;
- (void)registerPushNotificationsWithToken:(NSData * __nonnull)token notificationDelegate:(id <LPMessagingSDKNotificationDelegate> __nullable)notificationDelegate;
- (id <ConversationParamProtocol> __nonnull)getConversationBrandQuery:(NSString * __nonnull)brandID;
- (id <ConversationParamProtocol> __nonnull)getConversationBrandAndSkillQuery:(NSString * __nonnull)brandID skillID:(NSString * __nonnull)skillID;
- (id <ConversationParamProtocol> __nonnull)getConversationConsumerQuery:(NSString * __nonnull)consumerID brandID:(NSString * __nonnull)brandID agentToken:(NSString * __nonnull)agentToken;
- (void)setCustomButton:(UIImage * __nullable)image;
- (BOOL)isUrgent:(id <ConversationParamProtocol> __nonnull)conversationQuery;
- (void)markAsUrgent:(id <ConversationParamProtocol> __nonnull)conversationQuery;
- (void)dismissUrgent:(id <ConversationParamProtocol> __nonnull)conversationQuery;
- (void)resolveConversation:(id <ConversationParamProtocol> __nonnull)conversationQuery;
- (BOOL)isBrandReady:(NSString * __nonnull)brandID;
- (void)subscribeLogEvents:(enum LogLevel)logLevel logEvent:(void (^ __nonnull)(LPLog * __nonnull))logEvent;
@end


@interface LPMessagingSDK (SWIFT_EXTENSION(LPMessagingSDK))
- (void)initSocketForBrandID:(NSString * __nonnull)brandID agentToken:(NSString * __nonnull)agentToken readyCompletion:(void (^ __nullable)(void))readyCompletion;
- (id <ConversationViewControllerAgentDelegate> __nonnull)showAgentConversation:(id <ConversationParamProtocol> __nonnull)conversationQuery authenticationCode:(NSString * __nullable)authenticationCode containerViewController:(UIViewController * __nonnull)containerViewController;
@end


@interface LPMessagingSDK (SWIFT_EXTENSION(LPMessagingSDK))
- (void)logout;
- (void)destruct;
@end

@class LPNotification;

SWIFT_PROTOCOL("_TtP14LPMessagingSDK34LPMessagingSDKNotificationDelegate_")
@protocol LPMessagingSDKNotificationDelegate
@optional
- (void)LPMessagingSDKNotificationWithDidReceivePushNotification:(LPNotification * __nonnull)notification;
- (BOOL)LPMessagingSDKNotificationWithShouldShowPushNotification:(LPNotification * __nonnull)notification;
- (UIView * __nonnull)LPMessagingSDKNotificationWithCustomLocalPushNotificationView:(LPNotification * __nonnull)notification;
- (void)LPMessagingSDKNotificationWithNotificationTapped:(LPNotification * __nonnull)notification;
@end

@class NSError;

SWIFT_PROTOCOL("_TtP14LPMessagingSDK22LPMessagingSDKdelegate_")
@protocol LPMessagingSDKdelegate
@optional
- (void)LPMessagingSDKCustomButtonTapped;
- (void)LPMessagingSDKAgentDetails:(LPUser * __nonnull)agent;
- (void)LPMessagingSDKActionsMenuToggled:(BOOL)toggled;
- (void)LPMessagingSDKHasConnectionError:(NSString * __nullable)error;
- (void)LPMessagingSDKDidReceiveEventLog:(NSString * __nonnull)eventLog;
- (void)LPMessagingSDKCSATScoreSubmissionDidFinish:(NSString * __nonnull)accountID rating:(NSInteger)rating;
@required
- (void)LPMessagingSDKObseleteVersion:(NSError * __nonnull)error;
- (void)LPMessagingSDKAuthenticationFailed:(NSError * __nonnull)error;
- (void)LPMessagingSDKTokenExpired:(NSString * __nonnull)brandID;
@optional
- (void)LPMessagingSDKAgentIsTypingStateChanged:(BOOL)isTyping;
@end

@class Message;

SWIFT_CLASS("_TtC14LPMessagingSDK14LPNotification")
@interface LPNotification : NSObject
@property (nonatomic, copy) NSString * __nonnull text;
@property (nonatomic, strong) LPUser * __nonnull user;
@property (nonatomic, copy) NSString * __nonnull accountID;
@property (nonatomic) BOOL isRemote;
@property (nonatomic, readonly, copy) NSString * __nonnull toString;
- (nonnull instancetype)initWithText:(NSString * __nonnull)text firstName:(NSString * __nullable)firstName lastName:(NSString * __nullable)lastName uid:(NSString * __nullable)uid accountID:(NSString * __nonnull)accountID isRemote:(BOOL)isRemote;
- (nonnull instancetype)initWithMessage:(Message * __nonnull)message isRemote:(BOOL)isRemote;
- (nonnull instancetype)initWithText:(NSString * __nonnull)text user:(LPUser * __nonnull)user accountID:(NSString * __nonnull)accountID isRemote:(BOOL)isRemote OBJC_DESIGNATED_INITIALIZER;
@end

@class User;

SWIFT_CLASS("_TtC14LPMessagingSDK6LPUser")
@interface LPUser : NSObject
@property (nonatomic, copy) NSString * __nullable firstName;
@property (nonatomic, copy) NSString * __nullable lastName;
@property (nonatomic, copy) NSString * __nullable profileImageURL;
@property (nonatomic, copy) NSString * __nullable phoneNumber;
@property (nonatomic, copy) NSString * __nullable uid;
- (nonnull instancetype)initWithUser:(User * __nonnull)user;
- (nonnull instancetype)initWithFirstName:(NSString * __nullable)firstName lastName:(NSString * __nullable)lastName uid:(NSString * __nullable)uid profileImageURL:(NSString * __nullable)profileImageURL phoneNumber:(NSString * __nullable)phoneNumber OBJC_DESIGNATED_INITIALIZER;
@end

@class Conversation;
@class UITableView;
@class NSIndexPath;
@class ConversationDataSource;
@class UITableViewCell;
@class UITextView;
@class UIColor;
@class UIGestureRecognizer;

SWIFT_PROTOCOL("_TtP14LPMessagingSDK17UIAdapterDelegate_")
@protocol UIAdapterDelegate
@optional
- (BOOL)sendClickedWithMessage:(NSString * __nonnull)message inConversation:(Conversation * __nonnull)inConversation;
- (UITableViewCell * __nullable)cellForRowAtIndexPath:(UITableView * __nonnull)tableView indexPath:(NSIndexPath * __nonnull)indexPath dataSource:(ConversationDataSource * __nonnull)dataSource;
- (void)executeActionAtIndex:(UIViewController * __nonnull)viewController index:(NSInteger)index conversation:(Conversation * __nullable)conversation complition:(void (^ __nonnull)(void))complition;
- (void)textViewDidBeginEditingWithConversation:(Conversation * __nullable)conversation;
- (void)textViewDidEndEditingWithConversation:(Conversation * __nullable)conversation;
- (BOOL)textView:(UITextView * __nonnull)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString * __nonnull)text conversation:(Conversation * __nullable)conversation;
- (BOOL)shouldSetUIReadOnly:(Conversation * __nullable)conversation;
- (UIColor * __nonnull)getTableViewBackgroundColor:(id <ConversationParamProtocol> __nonnull)conversationQuery;
- (UIImage * __nonnull)getDefaultRecepientAvatarImage:(id <ConversationParamProtocol> __nonnull)conversationQuery;
- (UIGestureRecognizer * __nonnull)getTableViewCustomGestureRecognizer;
@end


@interface UIImageView (SWIFT_EXTENSION(LPMessagingSDK))
@end


@interface UITableViewCell (SWIFT_EXTENSION(LPMessagingSDK))
@end


@interface UIView (SWIFT_EXTENSION(LPMessagingSDK))
@end

#pragma clang diagnostic pop
