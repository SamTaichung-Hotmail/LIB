#pragma once

#define WIN32_LEAN_AND_MEAN             // 從 Windows 標頭排除不常使用的項目
// Windows 標頭檔
#include <windows.h>
#ifdef KEYPRO_EXPORTS
#define KEYPRO_API __declspec(dllexport)
#else
#define KEYPRO_API __declspec(dllimport)
#endif
KEYPRO_API int OpenKeyPro();
KEYPRO_API bool GetKeyProPath(WORD KeyProNo, char* Path,int Len);
KEYPRO_API bool NoneSecuCopyRead(WORD KeyProNo);
KEYPRO_API bool NoneSecuCopyWrite(WORD KeyProNo);
KEYPRO_API bool NoneSecuWriteBuff(WORD KeyProNo, char* Buff, int StartPos);
KEYPRO_API bool NoneSecuCheckBuff(WORD KeyProNo, char* Buff, int StartPos);
KEYPRO_API bool SecurityReadBuff(WORD KeyProNo, char* Buff, int StartPos, int Len);
KEYPRO_API bool SecurityWriteBuff(WORD KeyProNo, char* Buff, int StartPos);
KEYPRO_API bool ReadExtByteData(WORD KeyProNo, BYTE* Buff, int StartPos, int Len);
KEYPRO_API bool WriteExtByteData(WORD KeyProNo, BYTE* Buff, int StartPos, int Len);
