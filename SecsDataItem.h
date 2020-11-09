#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMASECS_EXPORTS
#define AUTOMASECS_API __declspec(dllexport)
#else
#define AUTOMASECS_API __declspec(dllimport)
#endif
#include <list>
#include "TimeCounter.h"
namespace AutoLib
{
	enum SECS_DATATYPE
	{
		sdList = 0x00,
		sdBinary = 0x20,
		sdBoolean = 0x24,
		sdASCII = 0x40,
		sdJIS8 = 0x44,
		sdWChar = 0x48,
		sdI8 = 0x60,
		sdI1 = 0x64,
		sdI2 = 0x68,
		sdI4 = 0x70,
		sdF8 = 0x80,
		sdF4 = 0x90,
		sdU8 = 0xA0,
		sdU1 = 0xA4,
		sdU2 = 0xA8,
		sdU4 = 0xB0,
	};
AUTOMASECS_API class DSecsDataItem
	{
	public:
		AUTOMASECS_API DSecsDataItem(DSecsDataItem* pParent = NULL, SECS_DATATYPE DataType = SECS_DATATYPE::sdList, int DataSize = 0, byte* pData = NULL);
		AUTOMASECS_API ~DSecsDataItem();
		AUTOMASECS_API int ParserData(byte* pData,int DataSize, DSecsDataItem* pParent = NULL);
		AUTOMASECS_API void RemoveAll();
		AUTOMASECS_API SECS_DATATYPE GetDataType();
		AUTOMASECS_API CString GetDataTypeName();
		AUTOMASECS_API DSecsDataItem* AddChild(DSecsDataItem* pChild);
		AUTOMASECS_API DSecsDataItem* GetChild(int index);
		AUTOMASECS_API int GetChildenCount();
		AUTOMASECS_API CString ToSML(int Space);
		AUTOMASECS_API DSecsDataItem* GetParent();
		AUTOMASECS_API void AddData(byte* pData, int size);
		AUTOMASECS_API byte* GetDataPtr();
		AUTOMASECS_API unsigned long GetDataSize(bool bAllChild = false);
		AUTOMASECS_API unsigned long GetDataCount();
		AUTOMASECS_API variant_t GetDataValue(int index);
		AUTOMASECS_API void SetDataValue(int index, variant_t Data);
		AUTOMASECS_API void ResetDataPtr(byte* pData,unsigned long Size);
		AUTOMASECS_API int BuildSendData(byte* pSendBuf);
	private:
		CArray<DSecsDataItem*> m_Childen;
		SECS_DATATYPE m_DataType;
		unsigned long m_intDataSize;
		byte *m_pData;
		DSecsDataItem* m_pParent;
	};
	#pragma pack(push)
	#pragma pack(1)
	struct HSMS_Packet
	{
		byte Length[4];		//byte 0-3
		byte SessionID[2];	//byte 4-5(DeviceID)
		byte StreamID;		//byte 6
		byte FunctionID;	//byte 7
		byte PType;			//byte 8
		byte SType;			//byte 9
		byte UniqueID[4];	//byte 10-13
		bool bWait=false;
		CString strAlias;
		DSecsDataItem *pData=NULL;
		~HSMS_Packet();
		void SetSessionID(WORD ID);
		WORD GetSessionID();
		void SetUniqueID(DWORD ID);
		DWORD GetUniqueID();
	};
	#pragma pack(pop)
}
