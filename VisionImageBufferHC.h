
#pragma once
#include "VisionImage.h"
#pragma component(mintypeinfo, on)
#ifdef _M_X64
#import "C:\Program Files\MVTec\HALCON-12.0\bin\x64-win64\halconx.dll" no_namespace \
	high_property_prefixes("get","put","putref")
#else
#import "C:\Program Files\MVTec\HALCON-12.0\bin\x86sse2-win32\halconx.dll" no_namespace \
	high_property_prefixes("get","put","putref")
#endif
#pragma component(mintypeinfo, off)
#include "Halcon.h"

#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
namespace AutoLib{
class MVisionImageBufferHC : public MVisionBase
{
public:
	AUTOMAVHC_API MVisionImageBufferHC();
	AUTOMAVHC_API virtual ~MVisionImageBufferHC();

	IHImageXPtr m_hImage;
};
}

