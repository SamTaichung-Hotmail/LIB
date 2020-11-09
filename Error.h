#pragma once
#pragma warning( disable :4091)

// MError ©R¥O¥Ø¼Ð
#include <vector>
#include "Solution.h"
#ifdef AUTOMABASE_EXPORTS
#define AUTOMABASE_API __declspec(dllexport)
#else
#define AUTOMABASE_API __declspec(dllimport)
#endif
namespace AutoLib {
	class MBase;
	AUTOMABASE_API class MError 
	{
	public:
		AUTOMABASE_API MError(MBase *pBase, CString strDescript , CString strReason = _T(""));
		AUTOMABASE_API MError(MBase *pBase, int intErrorCode , CString strReason = _T(""));
		AUTOMABASE_API virtual ~MError();
		AUTOMABASE_API void	AddSolution(MSolution *pSolution);
		int	m_intErrorCode;
		CString m_strDescript;
		CString m_strReason;
		std::vector<MSolution *> m_Solutions;
		MBase		*m_Happener;
		MBase		*m_pPara;
		MSolution	*m_pSelectedSolution;
		bool	m_isStop;
		CTime	tHappen;
	};

}//namespace AutoLib
