#pragma once
#ifdef LCLIB_EXPORTS 
#define FNTYPE __declspec(dllexport)
#else
#define FNTYPE __declspec(dllimport)
#endif
enum LC_ErrorCode {
	LC_NoError,
	LC_PortNumError,
	LC_PortNotOpen,
	LC_PortOpenFail,
	LC_PortBusy,
	LC_SendFail,
	LC_RecvFail,
};
enum LC_STATE {
	ls_INIT,
	ls_IDLE,
	ls_SET_VALUE,
	ls_GET_VALUE,
	ls_GET_VERSION,
	ls_WAIT_RESULT,
};
enum LC_MODE {
	lm_NormalOff,
	lm_NormalOn,
	lm_RaiseEdge,
	lm_FallEdge,
	lm_Pos_Logic,
	lm_Neg_Logic,
};
enum LC_TIME_UNIT {
	ltu_0_1ms,
	ltu_1ms,
	ltu_10ms,
	ltu_100ms,
	ltu_1000ms,
};
enum LC_DATA_ITEM {
	ldi_Mode,
	ldi_LightValue,
	ldi_TimeUnit,
	ldi_TriggerOnTime,
};
WORD FNTYPE LC_Open(int intComport);
WORD FNTYPE LC_SetDataValue(int intComport, LC_DATA_ITEM Item, BYTE Channel, BYTE Value);
WORD FNTYPE LC_SetRequestData(int intComport, LC_DATA_ITEM Item, BYTE Channel);
WORD FNTYPE LC_SetRequestVersion(int intComport);
WORD FNTYPE LC_GetRequestData(int intComport, BYTE& Data);
WORD FNTYPE LC_GetLastErrorCode(int intComport, int& errorcode);
WORD FNTYPE LC_GetState(int intComport, LC_STATE& state);
WORD FNTYPE LC_Close(int intComport);
