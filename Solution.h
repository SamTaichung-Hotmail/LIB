#pragma once
#pragma warning( disable :4091)

#ifdef AUTOMABASE_EXPORTS
#define AUTOMABASE_API __declspec(dllexport)
#else
#define AUTOMABASE_API __declspec(dllimport)
#endif
namespace AutoLib {
class MBase;
AUTOMABASE_API class MSolution
{
public:
	AUTOMABASE_API MSolution(CString strD,MBase *pP,int intState,int intStep,int intMode,MBase* pRemoveFrom=NULL);
	AUTOMABASE_API MSolution(MSolution *pSolution);
	AUTOMABASE_API virtual ~MSolution();
	AUTOMABASE_API virtual CString GetDescription();
	AUTOMABASE_API virtual void DoProcess();
protected:
	CString m_strDescription;
	MBase * m_pProcess;
	MBase * m_pRemoveErrorsFrom; //設定當選用此項目時要清除同時引發錯誤的物件及其子項所發的錯誤
	int m_State,m_Step,m_Mode;
};

}//namespace AutoLib
