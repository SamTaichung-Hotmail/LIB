
#pragma once
#include <windows.h>
#include "Base.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
// MVisionBase ©R¥O¥Ø¼Ð
namespace AutoLib{
AUTOMALIB_API class MVisionLib
{
public:
	AUTOMALIB_API MVisionLib();
	AUTOMALIB_API virtual ~MVisionLib();
	AUTOMALIB_API virtual unsigned int GetDeviceCount();
};
}

