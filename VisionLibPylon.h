
#pragma once
#include "VisionLib.h"
#include <pylon/PylonIncludes.h>
using namespace Pylon;

#ifdef AUTOMAPYLON_EXPORTS
#define AUTOMAPYLON_API __declspec(dllexport)
#else
#define AUTOMAPYLON_API __declspec(dllimport)
#endif
namespace AutoLib{
class MVisionLibPylon : public MVisionLib
{
public:
	AUTOMAPYLON_API MVisionLibPylon();
	AUTOMAPYLON_API virtual ~MVisionLibPylon();
	AUTOMAPYLON_API bool Init();
	AUTOMAPYLON_API CTlFactory* GetFactory();
	AUTOMAPYLON_API Pylon::CDeviceInfo GetDevice(unsigned int index);
	AUTOMAPYLON_API unsigned int GetDeviceCount();
protected:
	CArray<CString> CCDs;
	CTlFactory* m_pFactory;
	DeviceInfoList_t m_Devices;
};
}

