
#pragma once
#include "VisionBase.h"
#include "VisionImage.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
namespace AutoLib{
class MVisionImageBuffer : public MVisionBase
{
public:
	AUTOMALIB_API MVisionImageBuffer();
	AUTOMALIB_API virtual ~MVisionImageBuffer();
	AUTOMALIB_API virtual int GetBufferCount()=0;

};
}

