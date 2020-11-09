// 下列 ifdef 區塊是建立巨集以協助從 DLL 匯出的標準方式。
// 這個 DLL 中的所有檔案都是使用命令列中所定義 PCI6045DLL_EXPORTS 符號編譯的。
//  任何使用這個 DLL 的專案都不應定義這個符號。這樣的話，原始程式檔中包含這檔案的任何其他專案
// 會將 PCI6045DLL_API 函式視為從 DLL 匯入的，而這個 DLL 則會將這個巨集定義的符號視為匯出的。
#pragma once
#include "type_def.h"

#ifdef PCI6045DLL_EXPORTS
#define FNTYPE __declspec(dllexport)
#else
#define FNTYPE __declspec(dllimport)
#endif

#define Err_NoError			0x0000
#define Err_CardNotFound	0x0001
#define Err_ParameterErr	0x0002

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

#define CmpMethod_NOCMP 0x0
#define CmpMethod_EQND	0x1 //No direction condition
#define CmpMethod_EQCW	0x2 //CW direction
#define CmpMethod_EQCCW	0x3 //CCW direction
#define CmpMethod_GT	0x4 //greater than
#define CmpMethod_LT	0x5 //Less than

#define CmpSRC_Command		0x0
#define CmpSRC_FeedBack		0x1
#define CmpSRC_Deflect		0x2
#define CmpSRC_General		0x3
#define CmpSRC_Positioning	0x4
#define CmpSRC_CurSpeed		0x5

#define CmpAct_None			0x0
#define CmpAct_ImdStop		0x1
#define CmpAct_DecStop		0x2
#define CmpAct_ChgOp		0x3

#define CmpFuncAxisCmp		0x0
#define CmpFuncPWMOut		0x1
#define CmpFuncIO_0			0x2
#define CmpFuncIO_1			0x3
//---------------Motion done return code-----------------------
#define MD_STOP				0x00
#define MD_WaitDR			0x01
#define MD_WaitCSTA			0x02
#define MD_WaitiSyn			0x03
#define MD_WaitAnotherAxis	0x04
#define MD_WaitERCTmr		0x05
#define MD_WaitDirChangTmr	0x06
#define MD_CorrectBacklash	0x07
#define MD_WaitPAPB			0x08
#define MD_FeedingFA		0x09
#define MD_FeedingFL		0x0A
#define MD_Accelerating		0x0B
#define MD_FeedingFH		0x0C
#define MD_Decelerating		0x0D
#define MD_WaitINP			0x0E
#define MD_Other			0x0F
#define ERC_OUT_TM_12us		0x00
#define ERC_OUT_TM_102us	0x01
#define ERC_OUT_TM_408us	0x02
#define ERC_OUT_TM_1K6us	0x03
#define ERC_OUT_TM_13ms		0x04
#define ERC_OUT_TM_52ms		0x05
#define ERC_OUT_TM_104ms	0x06
#define ERC_OUT_Logic_LV	0x07
#ifdef __cplusplus
extern "C" {
#endif
	typedef struct _IOCTL_805_PARAM
	{
		ULONG32 Cmd;
		HANDLE EventHandleX;
		HANDLE EventHandleY;
		HANDLE EventHandleZ;
		HANDLE EventHandleU;
	} IOCTL_805_PARAM;

I16 FNTYPE _6045_initial(I16 *existCards);
I16 FNTYPE _6045_close(void);
I16 FNTYPE _6045_motion_done(U16 CardNo, U16 AxisNo);
I16 FNTYPE _6045_get_io_status(U16 CardNo, U16 AxisNo, U16 *io_sts);
I16 FNTYPE _6045_get_ext_status(U16 CardNo,U16 AxisNo, U32 *ext_sts);
I16 FNTYPE _6045_set_feedback_src(U16 CardNo,U16 AxisNo,  U16 value);
I16 FNTYPE _6045_get_command(U16 CardNo, U16 AxisNo, F64 *pos);
I16 FNTYPE _6045_set_command(U16 CardNo, U16 AxisNo, F64 pos);
I16 FNTYPE _6045_get_encoder(U16 CardNo, U16 AxisNo, F64 *pos);
I16 FNTYPE _6045_set_encoder(U16 CardNo, U16 AxisNo, F64 pos);
I16 FNTYPE _6045_get_position(U16 CardNo, U16 AxisNo, F64 *pos);
I16 FNTYPE _6045_set_position(U16 CardNo, U16 AxisNo, F64 pos);
I16 FNTYPE _6045_get_error_counter(U16 CardNo, U16 AxisNo, I16 *error);
I16 FNTYPE _6045_reset_error_counter(U16 CardNo, U16 AxisNo);
I16 FNTYPE _6045_get_current_speed(U16 CardNo, U16 AxisNo, F64 *speed);

I16 FNTYPE _6045_tv_move(U16 CardNo, U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc);
I16 FNTYPE _6045_sv_move(U16 CardNo, U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc, F64 SVacc);
I16 FNTYPE _6045_get_positioning_counter(U16 CardNo, U16 AxisNo, F64 *pos);
I16 FNTYPE _6045_emg_stop(U16 CardNo, U16 AxisNo);
I16 FNTYPE _6045_sd_stop(U16 CardNo, U16 AxisNo,F64 Tdec);
I16 FNTYPE _6045_set_servo(U16 CardNo, U16 AxisNo, I16 on_off);
I16 FNTYPE _6045_set_pls_outmode(U16 CardNo, U16 AxisNo, I16 pls_outmode);
I16 FNTYPE _6045_set_pls_iptmode(U16 CardNo, U16 AxisNo, I16 pls_iptmode, I16 pls_logic);
I16 FNTYPE _6045_set_correction(U16 CardNo, U16 AxisNo,U16 cor_method, U16 cor_amount);
I16 FNTYPE _6045_set_alm(U16 CardNo, U16 AxisNo, I16 alm_logic, I16 alm_mode);
I16 FNTYPE _6045_set_inp(U16 CardNo, U16 AxisNo, I16 inp_enable, I16 inp_logic);
I16 FNTYPE _6045_set_sd(U16 CardNo, U16 AxisNo, I16 enable, I16 sd_logic, I16 sd_latch, I16 sd_mode);
I16 FNTYPE _6045_set_erc(U16 CardNo, U16 AxisNo, I16 alm_el_out, I16 org_auto_out, I16 erc_logic, I16 erc_on_time);

I16 FNTYPE _6045_set_rst(U16 CardNo, U16 AxisNo, I16 on_off);
I16 FNTYPE _6045_get_int_status(U16 CardNo, U16 AxisNo, U32 *error_int_status, U32 *event_int_status, BOOL clear);
I16 FNTYPE _6045_set_home_config(U16 CardNo, U16 AxisNo, I16 home_mode, I16 org_logic, I16 ez_logic, I16 ez_count);
I16 FNTYPE _6045_home_search(U16 CardNo, U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc, F64 ORGOffset);
I16 FNTYPE _6045_home_move(U16 CardNo, U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc);

I16 FNTYPE _6045_set_fa_speed(U16 CardNo, U16 AxisNo, F64 FA_Speed);

//functions for latch & compare 
I16 FNTYPE _6045_set_ltc_logic(U16 CardNo, U16 AxisNo,I16 ltc_logic);
I16 FNTYPE _6045_get_latch_data(U16 CardNo, U16 AxisNo, I16 LatchNo, F64 *Pos);
I16 FNTYPE _6045_get_compare_data(U16 CardNo, U16 AxisNo, I16 CompareNo, F64 *Pos);
I16 FNTYPE _6045_set_compare_out_logic(U16 CardNo, U16 AxisNo, I16 cmp_logic);
I16 FNTYPE _6045_set_soft_limit(U16 CardNo, U16 AxisNo, I32 PLimit, I32 NLimit);
I16 FNTYPE _6045_enable_soft_limit(U16 CardNo, U16 AxisNo, I16 Action);
I16 FNTYPE _6045_disable_soft_limit(U16 CardNo, U16 AxisNo);

I16 FNTYPE _6045_set_trigger_comparator(U16 CardNo, U16 AxisNo, I16 CmpSrc, I16 CmpMethod);
I16 FNTYPE _6045_build_compare_table(U16 CardNo, U16 AxisNo, F64 *TableArray, I32 Size, I16 Device);
I16 FNTYPE _6045_build_compare_function(U16 CardNo, U16 AxisNo, F64 Start, F64 End, F64 Interval, I16 Device);
I16 FNTYPE _6045_set_auto_compare(U16 CardNo, U16 AxisNo, I16 SelectSrc);
I16 FNTYPE _6045_get_compare(U16 CardNo, U16 AxisNo, U32* TriggerCount, U32 *TriggerPoint);

I16 FNTYPE _6045_set_ring_count(U16 CardNo, U16 AxisNo, I16 RingCount,U32 CountPerCycle);

I16 FNTYPE _6045_get_last_int_status(U16 CardNo, U16 AxisNo, U32 *error_int_status, U32 *event_int_status);
I16 FNTYPE _6045_clr_last_int_status(U16 CardNo, U16 AxisNo);


I16 FNTYPE _6045_set_int_event(U16 CardNo,HANDLE *phEvent);
I16 FNTYPE _6045_reset_int_event(U16 CardNo);
I16 FNTYPE _6045_link_interrupt(U16 CardNo,void ( __stdcall *callbackAddr)(I16 IntAxisNoInCard));

I16 FNTYPE _6045_start_tr_move(U16 CardNo, U16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
I16 FNTYPE _6045_start_ta_move(U16 CardNo, U16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, U16 CounterSource);
I16 FNTYPE _6045_start_sr_move(U16 CardNo, U16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
I16 FNTYPE _6045_start_sa_move(U16 CardNo, U16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec,U16 CounterSource);
I16 FNTYPE _6045_start_zero_move(I16 CardNo,U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, U16 CountSource);

I16 FNTYPE _6045_start_tr_linear_any(U16 CardNo, U16 *AxisArray,I16 AxisCount, F64 *DistArray, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, U16 *WaitAxisArray=NULL, I16 WaitAxisCount=0, bool bIsConstSpeed = false);
I16 FNTYPE _6045_start_sr_linear_any(U16 CardNo, U16 *AxisArray,I16 AxisCount, F64 *DistArray, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec, U16 *WaitAxisArray=NULL, I16 WaitAxisCount=0, bool bIsConstSpeed = false);

I16 FNTYPE _6045_start_tr_arc_any(U16 CardNo, U16 XAxisID, U16 YAxisID, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, U16 *WaitAxisArray=NULL, I16 WaitAxisCount=0);
I16 FNTYPE _6045_start_sr_arc_any(U16 CardNo, U16 XAxisID, U16 YAxisID, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec, U16 *AxisArray=NULL, I16 WaitAxisCount = 0);
I16 FNTYPE _6045_start_tr_arc_z(U16 CardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey, F64 Z, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, bool bIsWaitMotion = false);

I16 FNTYPE _6045_get_register_full(U16 CardNo, U16 AxisNo, bool *full);

I16 FNTYPE _6045_v_change(U16 CardNo, U16 AxisNo, F64 NewVel, F64 VCTime);
I16 FNTYPE _6045_cmp_v_change(U16 CardNo, U16 AxisNo, F64 Res_dist,F64 oldvel, F64 newvel, F64 AccTime);

I16 FNTYPE _6045_get_sts(U16 CardNo, U16 AxisNo, U32 *sts);
I16 FNTYPE _6045_ResetCard(U16 CardNo);

DWORD FNTYPE _6045_set_cmp_func(U16 CardNo, U32 IOIF1, U32 IOIF2);
DWORD FNTYPE _6045_get_cmp_func(U16 CardNo, U32 *pIOIF1, U32 *pIOIF2);
DWORD FNTYPE _6045_set_pwm(U16 CardNo, U32 Period, U32 Duty, U32 AutoOffTime);
DWORD FNTYPE _6045_get_pwm(U16 CardNo, U32* pPeriod, U32* pDuty);
DWORD FNTYPE _6045_set_timer(U16 CardNo, U32 Interval,U32 IntCount);
DWORD FNTYPE _6045_get_timer(U16 CardNo, U32 *pInterval, U32 *pIntCount);
DWORD FNTYPE _6045_set_timer_func(U16 CardNo, bool Enable, bool IntEnable);
DWORD FNTYPE _6045_set_cmp_duty(U16 CardNo, U32 IOIF1, U32 IOIF2);
DWORD FNTYPE _6045_get_cmp_duty(U16 CardNo, U32 *IOIF1, U32 *IOIF2);


DWORD FNTYPE _6045_GetVersion(U16 CardNo, F64 *pVersionValue);
DWORD FNTYPE _6045_WritePWMReg(U16 cardno, U32 regno, U32 value);
DWORD FNTYPE _6045_ReadPWMReg(U16 cardno, U32 regno, U32 *pvalue);

//================================================================================
//宣告
//DWORD FNTYPE _6045_set_pwm_line_recipe(U16 CardNo, U32 LineIndex, U32 PitchPulse, U32 MaxSpeed, U32 RefSpeed, U32 PeriodCoefUp, U32 PeriodCoefDown, U32 DutyCoef, U32 DutyCoefUp, U32 DutyCoefDown, U32 BaseDutyValue);
DWORD FNTYPE _6045_set_pwmAuto_params(U16 CardNo, U32 DepAxisNo, U32 IOIF1, U32 IOIF2, U32 UseCommandSpeed);
DWORD FNTYPE _6045_set_pwmAuto_enable(U16 CardNo, bool Enable, U32 AutoOffTime);
DWORD FNTYPE _6045_get_pwm_log_data(U16 CardNo, U32 index, U32 *posX, U32 *posY, U32 *posXCmd, U32 *posYCmd);
DWORD FNTYPE _6045_get_pwm_speed_change_log(U16 CardNo, U32 index, U32 *data);
DWORD FNTYPE _6045_get_pwm_log_data_length(U16 CardNo, U32 *data);
DWORD FNTYPE _6045_set_pwm_ref_speed_duty(U16 CardNo, F64 PitchPulse, F64 SpeedL, F64 SpeedH, F64 BaseDutyValueL, F64 BaseDutyValueH, F64 DutyCoef);

//=================Limit Config===================
I16 FNTYPE _6045_set_el_logic(U16 CardNo, U16 AxisNo, I16 el_logic);

I16 FNTYPE _6045_motion_pause(U16 CardNo, U16* AxisAry, I16 AxisCount);
I16 FNTYPE _6045_motion_continue(U16 CardNo, U16* AxisAry, I16 AxisCount);
I16 FNTYPE _6045_Get_SSCNum(U16 CardNo, U16 AxisNo, U32 *pvalue);

#ifdef __cplusplus
}
#endif