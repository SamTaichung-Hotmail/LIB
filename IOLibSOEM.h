#pragma once
#pragma warning( disable : 4091)
#include "SamNetModule.h"
#ifdef AUTOMASOEM_EXPORTS
#define AUTOMASOEM_API __declspec(dllexport)
#else
#define AUTOMASOEM_API __declspec(dllimport)
#endif
#include "IOLib.h"				
#include "CardSOEM.h"
namespace AutoLib{
	class MIO;
	AUTOMASOEM_API class MIOLibSOEM : public MIOLib
	{
	public:
		AUTOMASOEM_API MIOLibSOEM(MBase *pParent,CString strID,CString strName,MCardSOEM *pCard);
		AUTOMASOEM_API virtual ~MIOLibSOEM();
		AUTOMASOEM_API virtual bool GetValue(MIO* pIO);
		AUTOMASOEM_API virtual void SetValue(MIO* pIO, bool bValue);
	protected:
		MCardSOEM *m_pCard;
	};

}//namespace AutoLib
