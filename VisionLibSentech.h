
#pragma once
#include "VisionLib.h"
#include "STCamD.h"
#ifdef _M_X64
#pragma comment(lib,"StCamD64.lib")
#else
#pragma comment(lib,"StCamD32.lib")
#endif 
#ifdef _M_X64
	#ifdef _DEBUG
	#pragma comment(lib,"AutomaVHC64D.lib")
	#pragma comment(lib,"AutomaLib64D.lib")
	#else
	#pragma comment(lib,"AutomaVHC64.lib")
	#pragma comment(lib,"AutomaLib64.lib")
#endif
#else
	#ifdef _DEBUG
		#pragma comment(lib,"AutomaVHC32D.lib")
		#pragma comment(lib,"AutomaLib32D.lib")
	#else
		#pragma comment(lib,"AutomaVHC32.lib")
		#pragma comment(lib,"AutomaLib32.lib")
	#endif
#endif 


#ifdef AUTOMASENTECH_EXPORTS
#define AUTOMASENTECH_API __declspec(dllexport)
#else
#define AUTOMASENTECH_API __declspec(dllimport)
#endif
namespace AutoLib{
class MVisionLibSenTech : public MVisionLib
{
public:
	AUTOMASENTECH_API MVisionLibSenTech();
	AUTOMASENTECH_API virtual ~MVisionLibSenTech();
	AUTOMASENTECH_API bool Init();
	AUTOMASENTECH_API unsigned int GetDeviceCount();
protected:
	CArray<CString> CCDs;
};
}

