#pragma once
#include <windows.h>
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "IO.h"
#include "timer.h"
#include "Base.h"
#include "TimeCounter.h"
// MValve 命令目標
namespace AutoLib{ 
AUTOMALIB_API class MValve : public MBase
{
public:
	enum ValveStyle{
		CylinderValve,
		VacValve,
	};
	AUTOMALIB_API MValve(MBase *,CString strID,CString strName, int ErrorCodeBase,
		CString strOpen=_T("Open"),CString strClose=_T("Close"),
		ValveStyle vsStyle = ValveStyle::CylinderValve);
	AUTOMALIB_API virtual ~MValve();
	//--------------------------------------------------------------------
	AUTOMALIB_API virtual bool Init();
	AUTOMALIB_API virtual void ChangeLanguage();
	AUTOMALIB_API virtual void StepCycle(const double dblTime);
	AUTOMALIB_API virtual void SaveMachineData(CADOConnection * pC, bool bAllChildsSave = true);
	AUTOMALIB_API virtual void LoadMachineData(CADOConnection * pC, bool bAllChildsLoad = true);
	AUTOMALIB_API virtual void SetValveStyle(ValveStyle vsStyle) { m_vsStyle=vsStyle; }; //電磁閥型式
	AUTOMALIB_API virtual ValveStyle GetValveStyle() { return m_vsStyle; }; //傳回電磁閥型式
	AUTOMALIB_API virtual bool DoOpen() { return false; };		//實作Open動作
	AUTOMALIB_API virtual void OnOpening() {};					//Open過程中
	AUTOMALIB_API virtual bool DoClose() { return false; };		//實作Close動作
	AUTOMALIB_API virtual void OnClosing() {};					//Close過程中
	//--------------------------------------------------------------------
	enum ValveMode{
		vmNormal,	  //正常模式(成功或不成功都不會OffValve)
		vmForce,	  //強制模式(不會引發錯誤也不會OffValve)
		vmTest,		  //測試模式，結果用GetResult取得
		vmAutoOff,    //如果完成(成功或不成功)就自動關(OffValve)
		vmOKThenOff,  //如果成功就自動關(OffValve)
		vmNGThenOff,  //如果不成功就自動關(OffValve)
	};
	AUTOMALIB_API virtual bool Inverse(ValveMode vmMode=ValveMode::vmNormal); //bForce 強制開啟後不檢查SR,bTest 開啟測試,bAutoOFF 
	AUTOMALIB_API virtual bool OpenValve(ValveMode vmMode=ValveMode::vmNormal); //bForce 強制開啟後不檢查SR,bTest 開啟測試,bAutoOFF 
	AUTOMALIB_API virtual bool isOpen() { return false; };
	AUTOMALIB_API virtual bool CloseValve(ValveMode vmMode=ValveMode::vmNormal);
	AUTOMALIB_API virtual bool isClose() { return false; };
	AUTOMALIB_API virtual bool OffValve();
	AUTOMALIB_API virtual bool Repeat();
	AUTOMALIB_API virtual bool ValveOnOff(ValveMode vmMode=ValveMode::vmNormal);//當開啟真空時,再按一次會自動關閉,不會破真空 
	AUTOMALIB_API virtual bool GetAllowToPause();				//是否可以暫停動作
	AUTOMALIB_API virtual bool Pause();

	bool GetTestResult();	//傳回測試結果
	//-----------------------------------------------------------------------------------
	//m_pIOOpen:Open動作點
	//m_pIOClose:Close動作點
	//m_pIOOpenSR:Open動作到位的SR
	//m_pIOCloseSR:Close動作到位的SR
	//m_pIOOpenSWSR:Open動作中如果m_pIOOpenSWSR就把m_pIOOpenSW設為On
	//m_pIOCloseSWSR:Close動作中如果m_pIOCloseSWSR就把m_pIOCloseSW設為On
	//------------------------------------------------------------------------------------
	MTimer *m_pTMOpenTimeOut,*m_pTMCloseTimeOut,*m_pTMOpenStable,*m_pTMCloseStable;
	CTimeCounter m_tcRepeat,m_tcQuerySafeTimeOut;
	bool m_isPassOpenSensor;
	bool m_isPassCloseSensor;
	bool m_bIsVac;
	enum STEP
	{
		StartOpen,
		WaitOpen,
		WaitOpenStable,
		StartClose,
		WaitClose,
		WaitCloseStable,
		ActionFinish,
		RepeatOpen,
		RepeatWaitOpen,
		RepeatClose,
		RepeatWaitClose,
	} ;
	enum ErrorCode
	{
		ErrNoError,
		ErrOpenTimeOut,
		ErrCloseTimeOut,
		ErrNotSafe,		
		ErrOpenSensorErr,
		ErrCloseSensorErr,
	};
	CString m_strOpenStatus,m_strCloseStatus;
protected:
	MError* OnError(ErrorCode code, int RetryStep, CString strReason);
	int m_RetryStep;	
	int m_SensorTestCount;
	ValveMode m_vmMode;

	ValveStyle m_vsStyle;
	bool m_isRepeat;
	ErrorCode m_ErrorCode;
	bool m_TestResult;
};

}//namespace AutoLib