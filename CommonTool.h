#pragma once
#ifdef COMMONTOOL_EXPORTS
#define COMMONTOOL_API __declspec(dllexport)
#else
#define COMMONTOOL_API __declspec(dllimport)
#endif
#define FunType __stdcall

COMMONTOOL_API unsigned long long FunType GetUID();
