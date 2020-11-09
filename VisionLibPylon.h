
#pragma once
#include "VisionLib.h"
#include <pylon/PylonIncludes.h>
using namespace Pylon;

#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
namespace AutoLib{
class MVisionLibPylon : public MVisionLib
{
public:
	AUTOMAVHC_API MVisionLibPylon();
	AUTOMAVHC_API virtual ~MVisionLibPylon();
	AUTOMAVHC_API bool Init();
	AUTOMAVHC_API CTlFactory* GetFactory();
	AUTOMAVHC_API Pylon::CDeviceInfo GetDevice(unsigned int index);
	AUTOMAVHC_API unsigned int GetDeviceCount();
protected:
	CArray<CString> CCDs;
	CTlFactory* m_pFactory;
	DeviceInfoList_t m_Devices;
};
}

