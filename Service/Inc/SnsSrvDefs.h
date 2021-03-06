#ifndef __SNS_SRV_DEFS_H__
#define __SNS_SRV_DEFS_H__

#define SRV_SNS_FEATURE_FRIENDS_BASIC            0x01
#define SRV_SNS_FEATURE_FRIENDS_REQUESTS         0x02

#define SRV_SNS_FEATURE_ACTIVITIES_BASIC         0x01
#define SRV_SNS_FEATURE_ACTIVITIES_COMMENTS      0x02
#define SRV_SNS_FEATURE_ACTIVITIES_NOTIFICATIONS 0x04

#define SRV_SNS_FEATURE_SHARE_BASIC              0x01
#define SRV_SNS_FEATURE_SHARE_PHOTO              0x02

#define SRV_SNS_FEATURE_MESSAGES_BASIC           0x01
#define SRV_SNS_FEATURE_MESSAGES_THREADS         0x02
#define SRV_SNS_FEATURE_MESSAGES_SEND            0x04
#define SRV_SNS_FEATURE_MESSAGES_GROUP_SEND      0x08

#define SRV_SNS_FEATURE_PHOTOS_BASIC             0x01

#define SRV_SNS_FEATURE_EVENTS_BASIC             0x01

typedef enum {
   SRV_SNS_FEATURE_FRIENDS,
   SRV_SNS_FEATURE_ACTIVITIES,
   SRV_SNS_FEATURE_SHARE,
   SRV_SNS_FEATURE_MESSAGES,
   SRV_SNS_FEATURE_PHOTOS,
   SRV_SNS_FEATURE_EVENTS,
   SRV_SNS_FEATURE_FUTURE_1,
   SRV_SNS_FEATURE_FUTURE_2,
   SRV_SNS_FEATURE_TOTAL,
   SRV_SNS_FEATURE_ANY
} srv_sns_feature_category;

typedef enum {
   SRV_SNS_OK                = 0,
   SRV_SNS_UNKNOWN_ERROR     = -999,
   SRV_SNS_SIM_PREFERENCE_UPDATE,
   SRV_SNS_OUT_OF_MEMORY,
   SRV_SNS_BUSY,
   SRV_SNS_DS_ERROR,
   SRV_SNS_SO_NOT_FOUND,
   SRV_SNS_NOT_SUPPORTED,
   SRV_SNS_NOT_LOADED,
   SRV_SNS_LIST_NOT_FOUND,
   SRV_SNS_PROCESS_NOT_FOUND,
   SRV_SNS_NO_MORE_DATA,
   SRV_SNS_GROUP_EXISTS, 
   SRV_SNS_NOT_READY,
   SRV_SNS_NOT_ENOUGH_SPACE,
   SRV_SNS_UPGRADING,
   SRV_SNS_FORMAT,
   SRV_SNS_DEV_PLUG_OUT,
   SRV_SNS_USB_MS_MODE,
   SRV_SNS_INVALID_TOKEN,
   SRV_SNS_INVALID_ACCOUNT,
   SRV_SNS_CONNECTION_FAIL, 
   SNS_SNS_INCORRECT_TIME,
   SRV_SNS_CANCELLED,
} srv_sns_result;

typedef enum {
   SRV_SNS_LOGO_SMALL,
   SRV_SNS_LOGO_LARGE,
   SRV_SNS_LOGO_TOTAL,
} srv_sns_logo_enum;

typedef enum {
   SRV_SNS_LOGIN_DONT_CARE,
   SRV_SNS_LOGIN_TRUE,
   SRV_SNS_LOGIN_FALSE,
} srv_sns_login_enum;

typedef enum {
   SRV_SNS_ACTIVITY_NEWSFEED,
   SRV_SNS_ACTIVITY_TO_ME
} srv_sns_activity_enum;

typedef enum {
   SRV_SNS_PIC_USER,
   SRV_SNS_PIC_THUMBNAIL,
   SRV_SNS_PIC_PHOTO
} srv_sns_pic_enum;

typedef enum {
   SRV_SNS_PIC_DOWNLOADING,
   SRV_SNS_PIC_DOWNLOAD_SUCCESS,
   SRV_SNS_PIC_DOWNLOAD_FAIL,
} srv_sns_pic_state;

typedef enum {
   SRV_SNS_OBJECT_ACTIVITY,
   SRV_SNS_OBJECT_PHOTO,
   SRV_SNS_OBJECT_ALBUM,
   SRV_SNS_OBJECT_FRIEND,
   SRV_SNS_OBJECT_APP,
   SRV_SNS_OBJECT_OTHER,
   SRV_SNS_OBJECT_TOTAL,
} srv_sns_object_enum;

typedef enum {
   SRV_SNS_GENDER_UNKNOWN,
   SRV_SNS_GENDER_MALE,
   SRV_SNS_GENDER_FEMALE
} srv_sns_gender_enum;

typedef enum {
   SRV_SNS_SETTING_SYNC_CONTACTS,
   SRV_SNS_SETTING_SYNC_CALENDAR,
   SRV_SNS_SETTING_SYNC_PHONEBOOK,
   SRV_SNS_SETTING_LAST_FRIEND_SYNCED,
   SRV_SNS_SETTING_NEWS_REMINDER,
   SRV_SNS_SETTING_SYNC_INTERVAL
} srv_sns_setting_enum;

typedef enum {
   SRV_SNS_NEWS_REMINDER_NEVER,
   SRV_SNS_NEWS_REMINDER_5_MINS,   
   SRV_SNS_NEWS_REMINDER_15_MINS,   
   SRV_SNS_NEWS_REMINDER_30_MINS,   
   SRV_SNS_NEWS_REMINDER_1_HOUR,   
   SRV_SNS_NEWS_REMINDER_3_HOURS,   
} srv_sns_news_reminder_enum;

typedef enum {
   SRV_SNS_SYNC_INTERVAL_MANUAL,
   SRV_SNS_SYNC_INTERVAL_1_HOUR,   
   SRV_SNS_SYNC_INTERVAL_3_HOURS,   
   SRV_SNS_SYNC_INTERVAL_6_HOURS,   
   SRV_SNS_SYNC_INTERVAL_12_HOURS,   
   SRV_SNS_SYNC_INTERVAL_1_DAY,   
   SRV_SNS_SYNC_INTERVAL_1_WEEK,   
} srv_sns_sync_interval_enum;

typedef enum {
   SRV_SNS_BKGD_PROCESS_INVALID,
   SRV_SNS_BKGD_PROCESS_ADD_COMMENT,
   SRV_SNS_BKGD_PROCESS_UPDATE_STATUS,
   SRV_SNS_BKGD_PROCESS_UPLOAD_PHOTO,
   SRV_SNS_BKGD_PROCESS_SEND_MESSAGE,
   SRV_SNS_BKGD_PROCESS_SYNC_FRIENDS,
   SRV_SNS_BKGD_PROCESS_SYNC_CALENDAR,
   SRV_SNS_BKGD_PROCESS_FB_WRITE_WALL,
   SRV_SNS_BKGD_PROCESS_TWT_RETWEET,
   SRV_SNS_BKGD_PROCESS_GET_NOTIFICATION_COUNTS,
   SRV_SNS_BKGD_PROCESS_TYPE_MAX,
} srv_sns_bkgd_process_type;

typedef enum {
   SRV_SNS_LIST_INVALIDATED_REASON_LOGIN,
   SRV_SNS_LIST_INVALIDATED_REASON_LOGOUT,
   SRV_SNS_LIST_INVALIDATED_REASON_EDITED,
} srv_sns_list_invalidated_reason;

typedef enum {
   SRV_SNS_LOGOUT_ACTIVELY,
   SRV_SNS_LOGOUT_PASSIVELY,
} srv_sns_log_out_type;

typedef enum {
   SRV_SNS_EVENT_TYPE_NORMAL,
   SRV_SNS_EVENT_TYPE_BIRTHDAY,
} srv_sns_event_type;

typedef enum {
   SRV_SNS_EVENT_SEARCH_TYPE_TIME,
   SRV_SNS_EVENT_SEARCH_TYPE_DAILY,
   SRV_SNS_EVENT_SEARCH_TYPE_WEEKLY,
   SRV_SNS_EVENT_SEARCH_TYPE_MONTHLY,
   SRV_SNS_EVENT_SEARCH_TYPE_BEFORE,
   SRV_SNS_EVENT_SEARCH_TYPE_AFTER,
   SRV_SNS_EVENT_SEARCH_TYPE_INCOMING,
   SRV_SNS_EVENT_SEARCH_TYPE_PREVIOUS,
   SRV_SNS_EVENT_SEARCH_TYPE_ALL,
   SRV_SNS_EVENT_SEARCH_TYPE_DURATION,
   SRV_SNS_EVENT_SEARCH_TYPE_ALARM,
   SRV_SNS_EVENT_SEARCH_TOTAL
} srv_sns_event_search_type_enum;

#define SRV_SNS_PROVIDER_ALL      0xFFFFFFFF
#define SRV_SNS_PROVIDER_FACEBOOK 0xfaceb00c
#define SRV_SNS_PROVIDER_TWITTER  0x54776974
#define SRV_SNS_PROVIDER_RENREN     26598088
#define SRV_SNS_PROVIDER_WEIBO    0x00000000
#define SRV_SNS_PROVIDER_KAIXIN   0x00000000

#define SRV_SNS_MEMORY_SIZE 200*1024

#define SRV_SNS_SELECTED_FRIENDS_GROUP_ID          21

#define SRV_SNS_MAX_LEN_ID                         40
#define SRV_SNS_MAX_LEN_NAME                       75
#define SRV_SNS_MAX_LEN_PIC_URL                    256 // for user pic
#define SRV_SNS_MAX_LEN_PIC_PATH                   57
#define SRV_SNS_MAX_LEN_MESSAGE_BODY               512 // activity text, message body
#define SRV_SNS_MAX_NUM_PROVIDERS                  8
#define SRV_SNS_MAX_NUM_GROUPS                     8
#define SRV_SNS_MAX_NUM_FRIENDS                    500
#define SRV_SNS_MAX_NUM_SELECTED_FRIENDS           5
#define SRV_SNS_MAX_NUM_FRIENDS_PER_GROUP          50
#define SRV_SNS_MAX_NUM_FRIENDS_PER_LINKED_CONTACT 4
#define SRV_SNS_MAX_NUM_RECIPIENTS                 10
#define SRV_SNS_MAX_NUM_EVENTS                     80

#define SRV_SNS_CONTACT_ID_ME                      SRV_PHB_INVALID_INDEX

#endif
