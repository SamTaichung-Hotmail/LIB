#pragma once
#ifdef SAMTOOL_EXPORTS
#define SAMTOOL_API __declspec(dllexport) 
#else
#define SAMTOOL_API __declspec(dllimport) 
#endif
#define FunType __stdcall
typedef int BOOL;
enum UNLOCK_TYPE {
	ut_COMPUTER,
	ut_ZMC_CONTROLLER,
};
#if defined(__cplusplus)
extern "C"
{
#endif // 
	SAMTOOL_API unsigned long long FunType GetUniqeID(int intMethod, void** ObjHandle);
	SAMTOOL_API unsigned int FunType UnLockLib(int intMethod,void** ObjHandle, unsigned long long UnLockCode);
	SAMTOOL_API unsigned int FunType GetUnLockLibResult();
	SAMTOOL_API unsigned long long FunType GetCanUnlockWaitTime();
	SAMTOOL_API void FunType Encrypt(unsigned char  in[8], unsigned char  out[8]);
	SAMTOOL_API void FunType Decrypt(unsigned char  in[8], unsigned char  out[8]);
	SAMTOOL_API void FunType SetEncrptKey(const unsigned char  key[8]);
	SAMTOOL_API unsigned int FunType GetXY_PointRotation(const double CX, const double CY, const double X, const double Y, const double R, double& dX, double& dY);
	SAMTOOL_API unsigned int FunType GetXYR_CCDx2(const double CX, const double CY, const double X1, const double Y1, const double X2,double Y2,
											const double TargetX1, const double TargetY1, const double TargetX2, const double TargetY2,const int AlignmentPos,
											 double& dX, double& dY, double &dR);
	SAMTOOL_API BOOL FunType FindCircleByPoints(const double *pPointAryX, const double *pPointAryY, const int PointCount, const double ResidualPercent, double &dblCenterX, double &dblCenterY, double &dblRadius);

#if defined(__cplusplus)
}
#endif // 
