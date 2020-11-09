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
	MBase * m_pRemoveErrorsFrom; //�]�w���Φ����خɭn�M���P�ɤ޵o���~������Ψ�l���ҵo�����~
	int m_State,m_Step,m_Mode;
};

}//namespace AutoLib
