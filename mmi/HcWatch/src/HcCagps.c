#if defined(__HC_CAGPS__)
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h" 
#include "mmi_frm_queue_gprot.h"
#include "mmi_msg_struct.h"
#include "fs_gprot.h"
#include "HcCagps.h"


AGPSParserStruct gAGPSParser;


///short����ת��
short cmo_short_reverse(short sh)
{
   char *p0 = (char *)&sh;
   short ret = 0;
   char *p1 = (char *)&ret;
   
   p1[0] = p0[0];
   p1[1] = p0[1];
   
   return ret;
}

///��ϵͳ����MSG_ID_MMI_EM_UPDATE_REQ����Ϣ����
/*
typedef struct
{
 LOCAL_PARA_HDR
 kal_uint8 info_request[EM_INFO_REQ_NUM]; 
} mmi_em_update_req_struct;
*/
void share_SendEMUpdataReq(BOOL bState)
{
   S32 i;
   MYQUEUE Message;
   mmi_em_update_req_struct *update_req;
   
   Message.oslMsgId = MSG_ID_MMI_EM_UPDATE_REQ;
   update_req = OslConstructDataPtr(sizeof(mmi_em_update_req_struct));
   for(i = 0; i < EM_INFO_REQ_NUM; i++)
   {
		update_req->info_request[i] = EM_OFF;
   }
   
   if(bState)
   {
		//update_req->info_request[RR_EM_LAI_INFO] = EM_ON;
		update_req->info_request[RR_EM_MEASUREMENT_REPORT_INFO] = EM_ON;							 
   }
   
   Message.oslDataPtr = (oslParaType *)update_req;
   Message.oslPeerBuffPtr = NULL;
   Message.oslSrcId = MOD_MMI;
   Message.oslDestId = MOD_L4C;

   OslMsgSendExtQueue(&Message);
}


///���û�վ��λ
static void cagps_reset(void)
{
	gAGPSParser.ai_item = AI_NULL;
}


///ע��ص�����
U32 cagps_reg_valid_cb(cagps_set_agpsdata_cb fun_ptr)
{
	U8 i = 0;
	cagps_set_agpsdata_cb *parser_data_cb_list = gAGPSParser.set_agpsdata_cb;

	ASSERT(fun_ptr != NULL);
	while(parser_data_cb_list[i] != fun_ptr)
	{
		if(parser_data_cb_list[i] == fun_ptr)
		{
			return 1;//RT_HAS_DONE;
		}
		i++;
		if(i >= 6)
		{
			return 2;//RT_FAILED;
		}
	}

	parser_data_cb_list[i] = fun_ptr;

	return 0;//RT_SUCCESSED;
}
///ȡ��ע��ص�����
BOOL cagps_unreg_valid(cagps_set_agpsdata_cb fun_ptr)
{
	U8 i = 0;
	cagps_set_agpsdata_cb *parser_data_cb_list = gAGPSParser.set_agpsdata_cb;
	ASSERT(fun_ptr != NULL);

	while(i < 6)
	{
		if(parser_data_cb_list[i] == fun_ptr)
		{
			parser_data_cb_list[i] = NULL;
			return TRUE;
		}
		i++;
	}
	return FALSE;
}
///ִ�лص�����
static void cagps_excute_valid(const AGPSDataStruct *p_agpsdata)
{
	U8 i = 0;
	cagps_set_agpsdata_cb *parser_data_cb_list = gAGPSParser.set_agpsdata_cb;
	while(i < 6)
	{
		if(parser_data_cb_list[i] != NULL)
		{
			(*parser_data_cb_list[i])(p_agpsdata);
		}
		i++;
	}
}


///�����õ���LAI����
static void cagps_parse_lai_info(const rr_em_lai_info_struct *data_ptr)
{
	AGPSDataStruct *p_ckAGPSData = &gAGPSParser.agpsdata;

	p_ckAGPSData->cell_id = data_ptr->cell_id;
	if(data_ptr->cell_id == 0)
	{
		return;
	}
	///lac
	memcpy(&p_ckAGPSData->location_area_code,data_ptr->lac,sizeof(WORD));
	p_ckAGPSData->location_area_code = cmo_short_reverse((short)p_ckAGPSData->location_area_code);

	///mcc
	p_ckAGPSData->mobile_country_code = data_ptr->mcc[0]*100 + data_ptr->mcc[1]*10 + data_ptr->mcc[2];
  
	///mnc
	if(data_ptr->mnc[2] != 0x0f)
	{
		p_ckAGPSData->mobile_network_code = data_ptr->mnc[0]*100 + data_ptr->mnc[1]*10 + data_ptr->mnc[2];
	}
	else
	{
		p_ckAGPSData->mobile_network_code = data_ptr->mnc[0]*10 + data_ptr->mnc[1];
	}

	gAGPSParser.ai_item |= AI_LAI;
  
	if(gAGPSParser.ai_item == AI_ALL)
	{
		cagps_excute_valid(&gAGPSParser.agpsdata);
		cagps_reset();
	}
}

///����MR����
static void cagps_parse_mr_info(const rr_em_measurement_report_info_struct *data_ptr)
{
	AGPSDataStruct *p_ckAGPSData = &gAGPSParser.agpsdata;

	//kal_prompt_trace(MOD_BT,"cagps_parse_mr_info timing_advance %d", data_ptr->timing_advance);
	///ta
	if(data_ptr->timing_advance != 0xff)
	{
		//p_ckAGPSData->timing_advance = data_ptr->timing_advance * 550;
		p_ckAGPSData->timing_advance = data_ptr->timing_advance;
	}
	///RSSI
	p_ckAGPSData->signal_strength = data_ptr->serv_rla_in_quarter_dbm * 4;

	gAGPSParser.ai_item |= AI_MR;

	if(gAGPSParser.ai_item == AI_ALL)
	{
		cagps_excute_valid(&gAGPSParser.agpsdata);
		cagps_reset();
	}
}


///�ⲿ�õ���վ��Ϣ
AGPSDataStruct *cagps_get_data(void)
{
    WORD wCID = gAGPSParser.agpsdata.cell_id;
 
	if(wCID == 0)
	{
	}
	return &gAGPSParser.agpsdata;
}


///��MSG_ID_MMI_EM_UPDATE_RSP�Ĵ���
static void cagps_update_rsp_hdlr(void *inMsg)
{
    /*mmi_em_update_rsp_struct *rsp_p = (mmi_em_update_rsp_struct *)inMsg;
	 if(rsp_p == NULL)
	 {
	    
	 }
	 if(rsp_p->result)
	 {
	 }
	 else
	 {
	 }*/
}


///��MSG_ID_MMI_EM_STATUS_IND�Ĵ���
static void cagps_status_ind_hdlr(void *info)
{
   mmi_em_status_ind_struct *msg = (mmi_em_status_ind_struct *)info;
   
   if(msg == NULL)
   { 
   
   }
   /// ����lai
   if(msg->em_info == RR_EM_LAI_INFO)
   {
		rr_em_lai_info_struct *data_ptr;
		U16 mm_pdu_len;
		data_ptr = (rr_em_lai_info_struct *)get_pdu_ptr(msg->info,&mm_pdu_len);
		cagps_parse_lai_info(data_ptr);
   }
   ///���� MR
   if(msg->em_info == RR_EM_MEASUREMENT_REPORT_INFO)
   {
		rr_em_measurement_report_info_struct *data_ptr;
		U16 mm_pdu_len;
		data_ptr = (rr_em_measurement_report_info_struct *)get_pdu_ptr(msg->info,&mm_pdu_len);
		cagps_parse_mr_info(data_ptr);
   }
   free_peer_buff(msg->info);
}

///������Ϣӳ�亯�����������վ��λ��ʱ������������ϢMSG_ID_MMI_EM_UPDATE_RSP��MSG_ID_MMI_EM_STATUS_IND
///MSG_ID_MMI_EM_UPDATE_RSP ���Ƿ�����ɹ���
///MSG_ID_MMI_EM_STATUS_IND �Եõ������ݽ��д���
///[ע]�˴��õ���mmi_frm_set_protocol_event_handler();
void cagps_setevent_handler()
{
	//SetProtocolEventHandler();
	mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_UPDATE_RSP, cagps_update_rsp_hdlr, MMI_TRUE);
	mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_STATUS_IND, cagps_status_ind_hdlr, MMI_TRUE);
}


///������վ��λ��ʱ����Ҫ�����ʼ��
///1.��ʼ��������ֵ��������Ϊ0.
///2.����ai_item�Ĳ���ΪAI_NULL��ʾΪ���յ���վ����Ϣ AI_LAI AI_MR ��ʾ���յ���LAI MR����
///3.������Ϣӳ�亯����
void cagps_init(void)
{
   memset(&gAGPSParser,0,sizeof(AGPSParserStruct));
   gAGPSParser.ai_item = AI_NULL;
   cagps_setevent_handler();
}

///�򿪻�վ��λ��������ϢMSG_ID_MMI_EM_UPDATE_REQ
BOOL cagps_open(void)
{
	if(!gAGPSParser.bt_open)
	{
		gAGPSParser.bt_open = TRUE;
		share_SendEMUpdataReq(TRUE);
		
	}
	return gAGPSParser.bt_open;
}

///�رջ�վ��λ
void cagps_close(void)
{
	if(gAGPSParser.bt_open)
	{
		share_SendEMUpdataReq(FALSE);
		gAGPSParser.bt_open = FALSE;
		cagps_reset();
	}
}

#endif
