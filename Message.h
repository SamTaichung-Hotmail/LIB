#pragma once
#pragma warning( disable :4091)

#ifdef AUTOMABASE_EXPORTS
#define AUTOMABASE_API __declspec(dllexport)
#else
#define AUTOMABASE_API __declspec(dllimport)
#endif
#include <map>
namespace AutoLib {
	class MBase;
	AUTOMABASE_API class MMessage
	{
	public:
		AUTOMABASE_API MMessage(void);
		AUTOMABASE_API virtual ~MMessage(void);
		enum MESSAGETYPE
		{
			StepLog,			//步序記錄
			ShowError,			//顯示錯誤
			ShowWarning,		//顯示警告
			ShowMessage,		//顯示訊息
			MachineComplete,	//機台程式啟動完成
			Connection,			//系統啟動完成，呼叫週邊連線
			UserMessage,		//使用者自訂Message
			ChangeLanguage,		//系統更改語言
			ChangeState,		//系統狀態改變
			ChangeType,			//更改型號通知
			EventSignal,		//事件通知
			PassWord,			//密碼驗証
			UserLogin,			//使用者登入成功
			TacTimeStart,		//計算TT開始
			TacTimeEnd,			//計算TT結束
			Expired,			//使用到期
		} MsgType;

		enum MSGIMG
		{
			Information,
			Notify,
			Warn,
			Normal,
		};

		LPVOID			m_pPara;	//設定使用要帶的物件
		int				m_index;	//設定使用者自定的index，當msg Type是UserMessage時，可用此欄自訂訊息型態
		CString			strMessage;
		MBase			*m_pFrom;
		MSGIMG			MsgLevel;
		};
}//namespace AutoLib