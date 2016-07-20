
#ifndef __HC_COMM__H__
#define __HC_COMM__H__

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#if defined(__cplusplus)
#define EXTERN_C    extern "C"
#else
#define EXTERN_C    extern
#endif //defined(__cplusplus)

#define HC_CLIENT_DEBUG
#if defined (HC_CLIENT_DEBUG)
#define HCCLIENT_DBGTRACE(s)	kal_prompt_trace s
#else
#define HCCLIENT_DBGTRACE(s)
#endif

#define HC_SOC_SEND_BUFFER_SIZE 2*1024 /* 2K */
#define HC_SOC_RECV_BUFFER_SIZE 2*1024 /* 2k */

typedef unsigned char       HBOOL;
typedef void                HVOID;
typedef char                HCHAR;//
typedef unsigned char       HBYTE;
typedef unsigned short      HWCHAR;
typedef signed short        HSHORT;
typedef unsigned short      HUSHORT;
typedef signed long         HLONG;
typedef unsigned long       HULONG;
typedef signed int          HINT;
typedef unsigned int        HUINT;
typedef unsigned __int64    HU64;
typedef __int64             HS64;
typedef unsigned char       HUINT8;
typedef signed char         HINT8;
typedef unsigned short      HUINT16;
typedef signed short        HINT16;
typedef unsigned long       HUINT32;
typedef signed long         HINT32;
typedef unsigned __int64    HUINT64;
typedef __int64             HINT64;

#if 0
typedef enum _IN_BOOLEAN
{
  INTrue=1,
  INFalse=0
} IN_BOOLEAN;

typedef enum _IN_SOCKET_STATUS
{
    IN_SOCK_STATUS_READY=0,
    IN_SOCK_STATUS_ERROR=1
} IN_SOCKET_STATUS;

typedef struct _INCallback
{
    void (*iCallback)(void*param);
    void* iParam;
} INCallback;

#define INSMS_MAX_DIGITS_LEN        41
typedef struct _INSendSmsExReq
{
    INUint16 iStructSize;
    INUint16 iDestPort;
    INUint16 iSrcPort;
    INUint16 iFlags;
    INUint8  iDCS;
    INUint8  iNumberLen;
    INUint16 iMessageLen;
    char     iNumber[INSMS_MAX_DIGITS_LEN];
    const INUint8* iMessage;
} INGSendSmsExReq;

enum INPhoneStatus
{
    IN_PHONESTATUS_UNKNOWN=0,
    IN_PHONESTATUS_OFFLINE,
    IN_PHONESTATUS_IDLE,
    IN_PHONESTATUS_INCOMING,
    IN_PHONESTATUS_ORIG,
    IN_PHONESTATUS_CONVERSATION
};
typedef struct _INTAPIStatus
{
    INUint16 iStructSize;
    INUint8 iIndex;
    INUint8 iPhoneStatus;
    INUint8 bExist;
    INUint8 bActive;
    INUint8 bRegistered;
    INUint8 bRoaming;
    char PLMN[8];
} INTAPIStatus;

enum IN_SIM_USABLE
{
    IN_SIM1_USABLE=1,                               //!< SIM��1����
    IN_SIM2_USABLE=2,                               //!< SIM��2����
    IN_SIM12_USABLE=IN_SIM1_USABLE|IN_SIM2_USABLE,  //!< SIM��1��SIM��2������

    IN_SIM1_PRESENT,
    IN_SIM2_PRESENT,
    IN_SIM12_PRESENT=IN_SIM1_PRESENT|IN_SIM2_PRESENT,
};

enum IN_SELSIM_METHODS
{
    IN_SELSIM_GET_SIM_NUM,          //!< ��ȡϵͳ֧�ֵ�SIM������
    IN_SELSIM_GET_SIM_USAGE,        //!< ��ȡ��ǰϵͳ��SIM������״̬������ֵ�μ�::IN_SIM_USABLE

    
    IN_SELSIM_SET_SMS_CHANNEL,      //!< ���ö�����SIM��
    IN_SELSIM_SET_CALL_CHANNEL,     //!< ���õ绰��SIM��
    IN_SELSIM_SET_DATA_CHANNEL,     //!< ����������SIM��
    IN_SELSIM_SET_OP_CHANNEL,       //!< ��������������SIM��

    IN_SELSIM_GET_SMS_CHANNEL,      //!< ��ȡ������SIM��
    IN_SELSIM_GET_CALL_CHANNEL,     //!< ��ȡ�绰��SIM��
    IN_SELSIM_GET_DATA_CHANNEL,     //!< ��ȡ������SIM��
    IN_SELSIM_GET_OP_CHANNEL,       //!< ��ȡ����������SIM��

    IN_SELSIM_GET_SIM_PRESENT,      //!< ��ȡ������
    IN_SELSIM_GET_SIM_PLMN,         //!< ��ȡPLMN   (��������IN_SELSIM_SET_OP_CHANNEL)
    IN_SELSIM_GET_SIM_ICCID,        //!< ��ȡICCID  (��������IN_SELSIM_SET_OP_CHANNEL)    
    
    IN_SELSIM_INIT_SIM_SMSC,		//!<��ʼ���������ĺ��룬��Ϊ����ϵͳ������õ������Բ�����IN_SELSIM_GET_SIM_SMSC˳�����
    IN_SELSIM_GET_SIM_SMSC,			//!< ��ȡ�������ĺ���  (��������IN_SELSIM_SET_OP_CHANNEL)
	IN_SELSIM_GET_SIM_LAC,			//!< ��ȡLAC  (��������IN_SELSIM_SET_OP_CHANNEL)
	IN_SELSIM_GET_SIM_CELLID,		//!< ��ȡCELL ID  (��������IN_SELSIM_SET_OP_CHANNEL)    
};
#endif
#ifdef __cplusplus
}
#endif //__cplusplus

#endif //!__IN_COMM__H__


