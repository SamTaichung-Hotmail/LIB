#pragma once
#include "VisionMatchResult.h"
#include <afxtempl.h>		//for CArray

#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
using namespace std;
namespace AutoLib {
	AUTOMALIB_API class MVisionMatchResults
	{
	public:
		AUTOMALIB_API MVisionMatchResults();
		AUTOMALIB_API ~MVisionMatchResults();
		AUTOMALIB_API MVisionMatchResult* GetResult(int index);
		AUTOMALIB_API int GetResultCount();
		AUTOMALIB_API void DeleteAll();
		AUTOMALIB_API void Add(MVisionMatchResult* pResult);
		AUTOMALIB_API void Remove(MVisionMatchResult* pResult);
	protected:
		CArray<MVisionMatchResult*> m_Results;
	};
}//namespace AutomaLib