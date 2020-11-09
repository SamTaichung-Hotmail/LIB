#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMASOEM_EXPORTS
#define AUTOMASOEM_API __declspec(dllexport)
#else
#define AUTOMASOEM_API __declspec(dllimport)
#endif

// MCard
#include "Card.h"		

namespace AutoLib {
	AUTOMASOEM_API class MCardSOEM : public MCard
	{
	public:
		AUTOMASOEM_API MCardSOEM(MBase* pParent, CString strID, CString strName);
		AUTOMASOEM_API ~MCardSOEM();
		AUTOMASOEM_API bool Open();
		AUTOMASOEM_API void Close();
		AUTOMASOEM_API int GetNetCount();
		AUTOMASOEM_API CString GetNetLinkName(int index);
		AUTOMASOEM_API void SetNetDevice(CString strDeviceLinkName);
		AUTOMASOEM_API CString GetNetDevice();
		AUTOMASOEM_API UINT16 GetECATState();
		AUTOMASOEM_API void SetECATState(UINT16 State);
		AUTOMASOEM_API void WriteIOOutData(UINT16 SlaveID, UINT16 Offset, UINT8 Data);
		AUTOMASOEM_API UINT8 ReadIOOutData(UINT16 SlaveID, UINT16 Offset);
		AUTOMASOEM_API UINT8 ReadIOInData(UINT16 SlaveID, UINT16 Offset);
	protected:
		CString m_strDeviceLinkName;
	};

}//namespace AutoLib
