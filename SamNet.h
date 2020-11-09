// 下列 ifdef 區塊是建立巨集以協助從 DLL 匯出的標準方式。
// 這個 DLL 中的所有檔案都是使用命令列中所定義 SamNetDLL_EXPORTS 符號編譯的。
//  任何使用這個 DLL 的專案都不應定義這個符號。這樣的話，原始程式檔中包含這檔案的任何其他專案
// 會將 SamNetDLL_API 函式視為從 DLL 匯入的，而這個 DLL 則會將這個巨集定義的符號視為匯出的。
#pragma once
#include "type_def.h" 
#ifdef SamNetDLL_EXPORTS 
#define FNTYPE __declspec(dllexport)
#else
#define FNTYPE __declspec(dllimport)
#endif

typedef unsigned long U32;
typedef unsigned long DWORD;
typedef short SHORT;
typedef unsigned short USHORT;
typedef long LONG;
#define SamNet_IO32IN32OUT	0x0010
#define SamNet_IO32IN		0x8011
#define SamNet_IO32OUT		0x8012
#define SamNet_IO16IN		0x8015
#define SamNet_IO16OUT		0x8016
#define SamNet_IO16IN16OUT	0x8017

#define SamNet_RGB			0x0020
#define SamNet_4XMA			0x0030


#define SamNet_SPEED_25M	0x0
#define SamNet_SPEED_12M	0x1
#define SamNet_SPEED_6M		0x2
#define SamNet_SPEED_3M		0x3


#define Err_NoError			0x0000
#define Err_CardNotFound	0x0001
#define Err_TimeOut			0x0002
#define Err_ParameterError	0x0004
#define Err_DeviceTypeError 0x0008
#define Err_DeviceOffLine	0x0010 
#define Err_ReCheckError    0x0020
#define Err_IOError			0x0011
#define Err_BufferCreateErr 0x1000

#define bit_RDY			0x0001
#define bit_ALM			0x0002
#define bit_PEL			0x0004
#define bit_MEL			0x0008
#define bit_ORG			0x0010
#define bit_DIR			0x0020
#define bit_EMG			0x0040
#define bit_PCS			0x0080
#define bit_ERC			0x0100
#define bit_EZ			0x0200
#define bit_DONE		0x0400
#define bit_Latch		0x0800
#define bit_SD			0x1000
#define bit_INP			0x2000
#define bit_SVON		0x4000

#define IOMode_TimerOut 0x0001
#define IOMode_TimerIn  0x0001
#define IOMode_TimerStart 0x0002
#define IOMode_TimerReset 0x0003

//-------4XMA Error bit define---------

#define bitErr_STP_CMP1	0x00000001
#define bitErr_STP_CMP2 0x00000002
#define bitErr_STP_CMP3 0x00000004
#define bitErr_STP_CMP4 0x00000008
#define bitErr_STP_CMP5 0x00000010
#define bitErr_STP_PEL  0x00000020
#define bitErr_STP_MEL  0x00000040
#define bitErr_STP_ALM  0x00000080
#define bitErr_STP_CSTP 0x00000100
#define bitErr_STP_CEMG 0x00000200
#define bitErr_STP_SD   0x00000400
#define bitErr_STP_DATA 0x00001000
#define bitErr_STP_INTP 0x00002000
#define bitErr_PAPB_OVR 0x00004000
#define bitErr_INTP_OUT 0x00008000
#define bitErr_EAEB_ERR 0x00010000
#define bitErr_PAPB_ERR 0x00020000

//------------4XMA Motion done code----------------
#define mdc_USC			0	//Under stopped condition
#define mdc_WaitDR		1	//Wait for DR input
#define mdc_WaitCSTA	2	//Wait for CSTA input
#define mdc_WaitISS		3	//Wait for an internal synchronous signal
#define mdc_WaitAAS		4   //Wait for another axis stop
#define mdc_WaitERC		5   //Wait for a completion of ERC timer
#define mdc_WaitDCT		6   //Wait for a completion of direction change timer
#define mdc_Correcting	7   //Correcting backlash
#define mdc_WaitPAPB	8   //Wait for PA/PB input
#define mdc_FALOW		9   //Feeding at FA low speed
#define mdc_FLLOW		10  //Feeding at FL low speed
#define mdc_ACC			11  //Accelerating
#define mdc_FHLOW		12  //Feeding at FL low speed
#define mdc_DEC			13  //Decelerating
#define mdc_WaitINP		14  //Wait for INP input
#define mdc_Other		15  //Others(Controlling start)

#define SamNet_ERC_TM_12us		0x00
#define SamNet_ERC_TM_102us	0x01
#define SamNet_ERC_TM_408us	0x02
#define SamNet_ERC_TM_1K6us	0x03
#define SamNet_ERC_TM_13ms	0x04
#define SamNet_ERC_TM_52ms	0x05
#define SamNet_ERC_TM_104ms	0x06
#define SamNet_ERC_Logic_LV	0x07

#ifdef __cplusplus
extern "C" {
#endif
int FNTYPE SamNet_OpenCard();
I16 FNTYPE SamNet_SetSpeed(U16 CardNo,U16 ConnectNo, U32 Speed);
I16 FNTYPE SamNet_GetSWID(I16 CardNo, U32 *SWID);
I16 FNTYPE SamNet_GetVersion(I16 CardNo, F64 *pDblVersion);
I16 FNTYPE SamNet_GetModuleVersion(U16 CardNo,U16 ConnectNo, U16 SlaveNo, F64 *pDblVersion);
I16 FNTYPE SamNet_WriteOut(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32 Value);
I16 FNTYPE SamNet_WriteOutChannel(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32 Channel, bool Value);
I16 FNTYPE SamNet_ReadIn(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32* Value);
I16 FNTYPE SamNet_ReadInChannel(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32 Channel, bool *Value);
I16 FNTYPE SamNet_ReadOut(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32* Value);
I16 FNTYPE SamNet_ReadOutChannel(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32 Channel, bool *Value);
I16 FNTYPE SamNet_ReadQuality(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32* Quality);
I16 FNTYPE SamNet_ReadDeviceID(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32* DeviceID);
I16 FNTYPE SamNet_ReadOnLine(U16 CardNo,U16 ConnectNo, U16 SlaveNo, bool* OnLine);
I16 FNTYPE SamNet_Out_Set_Mode(U16 CardNo,U16 ConnectNo, U16 SlaveNo,
	U16 Point, U16 Mode, U16 TimerNo);
I16 FNTYPE SamNet_Out_Get_Mode(U16 CardNo,U16 ConnectNo, U16 SlaveNo,
	U16 Point, U16 *pMode, U16 *pTimerNo);
I16 FNTYPE SamNet_In_Set_Mode(U16 CardNo,U16 ConnectNo, U16 SlaveNo,
	U16 Point, U16 Mode, U16 TimerNo, U16 SampleCLK);
I16 FNTYPE SamNet_In_Get_Mode(U16 CardNo,U16 ConnectNo, U16 SlaveNo,
	U16 Point, U16 *pMode, U16 *pTimerNo, U16 *pSampleCLK);
I16 FNTYPE SamNet_Counter_Set_Clock(U16 CardNo,U16 ConnectNo, U16 SlaveNo,
	U16 CLKDiv); //Count Clock=50MHz/CLKDiv
I16 FNTYPE SamNet_Counter_Set_Mode(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U16 TimerNo, U32 Mode,
	U32 CountSource, bool CountUp, bool InLogic, bool OutLogic,
	bool StartLogic, bool ResetLogic, U32 PlsCount);
I16 FNTYPE SamNet_Counter_Set_Target(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U16 TimerNo, U32 Target);
I16 FNTYPE SamNet_Counter_Get_Target(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U16 TimerNo, U32* pTarget);
I16 FNTYPE SamNet_Counter_Set_Initial(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U16 TimerNo, U32 Initial);
I16 FNTYPE SamNet_Counter_Get_Initial(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U16 TimerNo, U32* pInitial);
I16 FNTYPE SamNet_Counter_Get_Count(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U16 TimerNo, U32* pValue);
I16 FNTYPE SamNet_Counter_Start(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U16 TimerNo);
I16 FNTYPE SamNet_Counter_Reset(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U16 TimerNo);
//--------------------------------------------RGB&DA--------------------------------------------
I16 FNTYPE SamNet_WriteRGB(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32 Channel, U32 R, U32 G, U32 B);
I16 FNTYPE SamNet_WriteDA(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32 Channel, U32 Value);
I16 FNTYPE SamNet_ReadRGB(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32 Channel, U32 *pR, U32 *pG, U32 *pB);
I16 FNTYPE SamNet_ReadDA(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32 Channel, U32 *pValue);
//---------------------------------------------AD-----------------------------------------------------------
I16 FNTYPE SamNet_ReadAD(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32 Channel, U32 *pValue);
I16 FNTYPE SamNet_SetADConfig(U16 CardNo,U16 ConnectNo, U16 SlaveNo, bool bSignalEnd, bool pbUnipolar, bool bGain);
I16 FNTYPE SamNet_GetADConfig(U16 CardNo,U16 ConnectNo, U16 SlaveNo, bool *pbSignalEnd, bool *pbUnipolar, bool *pbGain);
void FNTYPE SamNet_CloseCard();

I16 FNTYPE _4XMA_Init(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo);
I16 FNTYPE _4XMA_motion_done(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo);
I16 FNTYPE _4XMA_get_io_status(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, U16 *io_sts);
I16 FNTYPE _4XMA_get_ext_status(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, U32 *ext_sts);
I16 FNTYPE _4XMA_set_feedback_src(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, U16 Source);
I16 FNTYPE _4XMA_get_command(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 *pos);
I16 FNTYPE _4XMA_set_command(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 pos);
I16 FNTYPE _4XMA_get_encoder(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 *pos);
I16 FNTYPE _4XMA_set_encoder(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 pos);
I16 FNTYPE _4XMA_get_position(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 *pos);
I16 FNTYPE _4XMA_set_position(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 pos);
I16 FNTYPE _4XMA_get_error_counter(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 *counter);
I16 FNTYPE _4XMA_reset_error_counter(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo);
I16 FNTYPE _4XMA_get_current_speed(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 *speed);
I16 FNTYPE _4XMA_tv_move(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc);
I16 FNTYPE _4XMA_sv_move(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc, F64 SVacc);
I16 FNTYPE _4XMA_return_zero(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc);
I16 FNTYPE _4XMA_get_positioning_counter(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 *pos);
I16 FNTYPE _4XMA_emg_stop(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo);
I16 FNTYPE _4XMA_sd_stop(U16 CardNo, U16 ConnectNo, U16 SlaveNo, U16 AxisNo, F64 Tdec);
I16 FNTYPE _4XMA_set_servo(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 on_off);
I16 FNTYPE _4XMA_set_pls_outmode(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 pls_outmode);
I16 FNTYPE _4XMA_set_pls_iptmode(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 pls_iptmode, I16 pls_logic);
 
I16 FNTYPE _4XMA_set_alm(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 alm_logic, I16 alm_mode);
I16 FNTYPE _4XMA_set_el_logic(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 el_logic);
I16 FNTYPE _4XMA_set_emg_logic(U16 CardNo,U16 ConnectNo, U16 SlaveNo, I16 emg_logic);
I16 FNTYPE _4XMA_set_inp(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 inp_enable, I16 inp_logic);
I16 FNTYPE _4XMA_set_sd(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 enable, I16 sd_logic, I16 sd_latch, I16 sd_mode);
I16 FNTYPE _4XMA_set_erc(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 alm_el_out, I16 org_auto_out, I16 erc_logic, I16 erc_on_time);

I16 FNTYPE _4XMA_set_rst(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, U16 on_off);

I16 FNTYPE _4XMA_get_int_status(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, U32 *error_int_status, U32 *event_int_status);
I16 FNTYPE _4XMA_set_home_config(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 home_mode, I16 org_logic, I16 ez_logic, I16 ez_count, I16 erc_out);
I16 FNTYPE _4XMA_home_search(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc, F64 ORGOffset);
I16 FNTYPE _4XMA_home_move(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc);

I16 FNTYPE _4XMA_set_fa_speed(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 FA_Speed);


//functions for latch & compare 
I16 FNTYPE _4XMA_set_ltc_logic(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 ltc_logic);
I16 FNTYPE _4XMA_get_latch_data(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 LatchNo, F64 *Pos);
I16 FNTYPE _4XMA_get_compare_data(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 CompareNo, F64 *Pos);
I16 FNTYPE _4XMA_set_compare_out_logic(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 cmp_logic);
I16 FNTYPE _4XMA_set_soft_limit(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I32 PLimit, I32 NLimit);
I16 FNTYPE _4XMA_enable_soft_limit(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 Action);
I16 FNTYPE _4XMA_disable_soft_limit(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo);
I16 FNTYPE _4XMA_set_general_comparator(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 CmpSrc, I16 CmpMethod, I16 CmpAction, F64 Data);
I16 FNTYPE _4XMA_set_trigger_comparator(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 CmpSrc, I16 CmpMethod, F64 Data);
I16 FNTYPE _4XMA_build_compare_table(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 *TableArray, I16 ArraySize);
I16 FNTYPE _4XMA_set_auto_compare(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 Enable);
I16 FNTYPE _4XMA_get_compare(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, U32* TriggerCount, U32 *TriggerPoint);
I16 FNTYPE _4XMA_build_compare_function(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 Start, F64 End, F64 Interval);
I16 FNTYPE _4XMA_set_ring_count(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, I16 RingCount, U32 CountPerCycle);

I16 FNTYPE _4XMA_write_do(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, U16 value);
U16 FNTYPE _4XMA_read_di(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, bool *bValue);
I16 FNTYPE _4XMA_GetVersion(U16 CardNo,U16 ConnectNo, U16 SlaveNo, F64 *pDblVersion);

I16 FNTYPE _4XMA_start_tr_move(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _4XMA_start_ta_move(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, U16 CountSource);
I16 FNTYPE _4XMA_start_sr_move(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
I16 FNTYPE _4XMA_start_sa_move(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec,U16 CountSource);
I16 FNTYPE _4XMA_start_zero_move(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, U16 CountSource);
I16 FNTYPE _4XMA_motion_pause(U16 CardNo, U16 ConnectNo, U16 SlaveNo, U16* AxisAry, I16 AxisCount);
I16 FNTYPE _4XMA_motion_continue(U16 CardNo, U16 ConnectNo, U16 SlaveNo, U16* AxisAry, I16 AxisCount);
I16 FNTYPE _4XMA_start_tr_linear_any(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U16 *AxisArray, I16 AxisCount, F64 *DistArray, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, U16 *WaitAxisArray=0, I16 WaitAxisCount=0, bool bIsConstSpeed=false);
I16 FNTYPE _4XMA_start_sr_linear_any(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U16 *AxisArray, I16 AxisCount, F64 *DistArray, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec, U16 *WaitAxisArray=0, I16 WaitAxisCount=0, bool bIsConstSpeed=false);
I16 FNTYPE _4XMA_start_tr_arc_any(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U16 XAxisID, U16 YAxisID, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, U16 *WaitAxisArray = 0, I16 WaitAxisCount = 0);
I16 FNTYPE _4XMA_start_sr_arc_any(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U16 XAxisID, U16 YAxisID, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel, F64 MaxVel, F64 SVacc, F64 SVdec, F64 Tacc, F64 Tdec, U16 *WaitAxisArray = 0, I16 WaitAxisCount = 0);
I16 FNTYPE _4XMA_start_tr_arc_z(U16 CardNo,U16 ConnectNo, U16 SlaveNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, F64 OffsetZ, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, bool bIsWaitMotion=false);
I16 FNTYPE _4XMA_get_register_full(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, bool *full);


I16 FNTYPE _4XMA_v_change(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 NewVel, F64 Tacc);
I16 FNTYPE _4XMA_get_sts(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, U32 *sts);
I16 FNTYPE _4XMA_Reset(U16 CardNo,U16 ConnectNo, U16 SlaveNo);
I16 FNTYPE _4XMA_EEROM_Write(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 Addr,U8 Data);
I16 FNTYPE _4XMA_EEROM_Read(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U16 Addr,U8 *pData);
I16 FNTYPE _4XMA_EEROM_GetStatus(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32 *pData);
I16 FNTYPE _4XMA_Board_GetStatus(U16 CardNo,U16 ConnectNo, U16 SlaveNo, U32 *pData);
I16 FNTYPE _4XMA_cmp_v_change(U16 CardNo,U16 ConnectNo, U16 SlaveNo,U16 AxisNo, F64 Res_dist,
	F64 oldvel, F64 newvel, F64 AccTime);
I16 FNTYPE _4XMA_Start_Buff(U16 TaskNo, U16 CardNo, U16 ConnectNo, U16 SlaveNo);
I16 FNTYPE _4XMA_End_Buff(U16 TaskNo, U16 CardNo, U16 ConnectNo, U16 SlaveNo);
I16 FNTYPE _4XMA_Get_SSCNum(U16 CardNo, U16 ConnectNo, U16 SlaveNo, U16 AxisNo, U32 *pvalue);

#ifdef __cplusplus
}
#endif
