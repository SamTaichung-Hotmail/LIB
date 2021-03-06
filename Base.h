#pragma once
#include <map>
#include "Error.h"
#include "StringProvider.h"
#include "ADOConnection.h"
#include "ADORecordset.h"
#include "Message.h"
#ifdef AUTOMABASE_EXPORTS
#define AUTOMABASE_API __declspec(dllexport)
#else
#define AUTOMABASE_API __declspec(dllimport)
#endif
static bool m_bKeyProCheckSuccess = false;
namespace AutoLib{
AUTOMABASE_API class MBase
{
public:
	AUTOMABASE_API MBase(MBase *pParent,CString strID, CString strName, int ErrorCodeBase=-1);					//英文名字同ID
	//----------------------------------------------------------------------------------------
	enum STATE{			//物件狀態
		INIT,			//初始中
		IDLE,			//停止中
		ACTION,			//動作中
		HOME,			//復歸中
		ERRHAPPEN,		//錯誤中
		EMSTOP,			//急停中
		PAUSE,			//暫停中
	};

	enum MODE{		//物件操作模式
		BASE,			//基楚元件
		AUTO,			//自動
		SEMIAUTO,		//半自動
		MANUAL,			//手動
		MAINTAIN,		//維護
	};

	//----------------------------------------------------------------------------------------
	AUTOMABASE_API virtual ~MBase();					//解構
	AUTOMABASE_API virtual bool Init();				//機構初始化,當讀完Machine Data後應該要初始化機構
	AUTOMABASE_API virtual void ErrorRegister(int intErrorCode,CString strDescripe);				//錯誤註冊
	AUTOMABASE_API virtual void ErrorHappen(MError * pError);				//錯誤異常丟出
	AUTOMABASE_API virtual void ErrorProcess(STATE state, int intStep, int intMode);			//錯誤處理
	AUTOMABASE_API int GetErrorCodeBase();			//取得此物件的錯誤碼基底
	AUTOMABASE_API virtual bool QuerySafe(MBase * pFrom,int intState,int intStep,int intMode,CString *pstrReason=NULL);
																			//往上層查詢動作安全
	AUTOMABASE_API virtual void AddSolution(MSolution *pS);
	AUTOMABASE_API virtual void AddSolutionsTo(MError * pError);				//把上層Solution加給Error
	AUTOMABASE_API virtual void RemoveSolutions();							//清除上層Slution
	AUTOMABASE_API virtual void Cycle(const double dblTime);					//系統Cycle
	AUTOMABASE_API virtual void StepCycle(const double dblTime){};			//Step執行，由各層實作
	AUTOMABASE_API virtual bool DoStep(int intStep);							//開始執行Step，由各層實作
	AUTOMABASE_API virtual bool DoHome(int intStep);							//開始執行Home，由各層實作
	AUTOMABASE_API virtual bool isIDLE();													//物件及其子物件是否動作完成
	AUTOMABASE_API virtual void EStop(const bool isES);						//急停通知
	AUTOMABASE_API virtual void SystemAlarm(const bool isSystemAlarm);			//系統性警報通知
	AUTOMABASE_API virtual void InterLock(const bool isInterLock);

	AUTOMABASE_API virtual void Stop();
	AUTOMABASE_API virtual void CycleStop();
	AUTOMABASE_API virtual void CycleContinue();
	AUTOMABASE_API virtual bool GetAllowToPause();							//是否可以暫停動作
	AUTOMABASE_API virtual bool Pause();										//暫停動作
	AUTOMABASE_API virtual bool isPause();										//是否暫停中
	AUTOMABASE_API virtual bool Idle();										//結束動作
	AUTOMABASE_API virtual void Continue();									//Continue動作
	AUTOMABASE_API virtual void ChangeLanguage();							//語言切換通知
	AUTOMABASE_API virtual void ShowMessage(MBase * pFrom,CString strMsg,MMessage::MSGIMG img=MMessage::MSGIMG::Information);
	AUTOMABASE_API virtual void ShowMessage(MMessage* pMsg); //傳送訊息及
	AUTOMABASE_API virtual void LoadRecipeData(CADOConnection * pC,bool bAllChildsLoad=true);
	AUTOMABASE_API virtual void SaveRecipeData(CADOConnection * pC, bool bAllChildsSave = true);
	AUTOMABASE_API virtual void LoadMachineData(CADOConnection * p_C, bool bAllChildsLoad = true);
	AUTOMABASE_API virtual void SaveMachineData(CADOConnection * p_C, bool bAllChildsSave = true);
	AUTOMABASE_API virtual CString GetStateName();					//取得目前此物件的狀態名稱
	AUTOMABASE_API virtual CString GetStepName();					//取得目前此物件的步序名稱
	AUTOMABASE_API virtual CString GetModeName();					//取得目前此物件的模式名稱
	AUTOMABASE_API virtual bool GetErrorHappen(); //此機構(含其子項)是否處於錯誤狀態中
	AUTOMABASE_API virtual CString GetFullName();
	AUTOMABASE_API virtual void SetRecordLog(bool bLog);	//設定Log記錄器
	AUTOMABASE_API virtual void WriteTextRecord(CString strFile,CString strText);

	AUTOMABASE_API MBase* AddChild(MBase * p_C);	//加入下層物件
	AUTOMABASE_API bool   DelChild(CString ID);	//刪除下層物件
	AUTOMABASE_API MBase* GetChild(CString ID);	//取得下層物件
	AUTOMABASE_API MBase* GetTopParent();		//取得最上層物件(一般是Machine)
	AUTOMABASE_API MBase* GetParent();			//取得此物件上層物件
	AUTOMABASE_API void ReleaseChilds();			//delete所有下層物件(一般是解構時用)
	AUTOMABASE_API CStringProvider* GetStringProvider();	//取得文字庫物件
	AUTOMABASE_API bool isSystemAlarm();
	AUTOMABASE_API void OnMachineErrorStatusChange(const bool bErrorHappen);
	CString m_ID;								//參數存檔的代號
	CString m_strName;							//此機構名稱
	int m_Step;									//此物件目前執行動作的步序號碼
	std::map<CString,MBase *> m_Childs;			//此物件的子物件集合
	STATE m_State;								//此物件的狀態
	MODE m_Mode;								//此物件目前執行動作的模式
protected:
	MBase * m_pParent;								//此物件之上層物件
	int m_ErrorCodeBase;						//此物件的錯誤碼基底
	bool m_bLog;								//動作是否記錄到LOG檔
	STATE m_PauseState;							//此物件暫停時的狀態
	bool m_isInterLock,m_isEStop,m_bSystemAlarm;				//鎖定,急停,系統報警 Latch用的變數
	CString m_strStepName;						//目前執行步驟的名稱
	CStringProvider* m_pStringProvider;			//字串索引用物件:主要是翻不同國文字用
	std::vector<MSolution *> m_ParentSolutions; //上層加入的Solution集合
	bool m_bRecordLog;
	CString m_strRecordMsg;
	bool m_bMachineErrorHappen;
};
}//namespace AutoLib

