#pragma once
#pragma warning( disable : 4091 4244)
#ifdef AUTOMASECS_EXPORTS
#define AUTOMASECS_API __declspec(dllexport)
#else
#define AUTOMASECS_API __declspec(dllimport)
#endif
#include "HSMS.h"
#include "ParserSML.h" 
#include "TimeCounter.h"
#include "SecsDataItem.h"
namespace AutoLib
{
AUTOMASECS_API class MSecs2 :public MHSMS
{

public:
	enum SML_ERROR {
		seNoError,
		seNeedRight,
		seNeedLeft,
		seTypeDefError,
		seParametersError,
	};
	enum STEP {

	};
	AUTOMASECS_API MSecs2(MUnit *pParent, CString strID, CString strName, int ErrorCodeBase = -1);
	~MSecs2();
	AUTOMASECS_API void Cycle(const double dblTime);
	AUTOMASECS_API void RemoveAll();
	AUTOMASECS_API void AddPacket(HSMS_Packet *pPacket);
	AUTOMASECS_API void DeletePacket(int index);
	AUTOMASECS_API int GetPacketCount();
	AUTOMASECS_API HSMS_Packet * GetPacket(int index);
	AUTOMASECS_API SML_ERROR ReadSML(CString strFile);
private:
	CArray<HSMS_Packet*> m_Packets;
	CArray<ExpressSML*> m_Expresses;
};

}
