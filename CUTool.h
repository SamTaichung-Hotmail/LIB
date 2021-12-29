#pragma once
#ifdef CUTOOL_EXPORTS
#define CUTOOL_API __declspec(dllexport) 
#else
#define CUTOOL_API __declspec(dllimport) 
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
	CUTOOL_API unsigned long long FunType GetUniqeID(int intMethod, void** ObjHandle);
	CUTOOL_API unsigned int FunType UnLockLib(int intMethod, void** ObjHandle, unsigned long long UnLockCode);
	CUTOOL_API unsigned int FunType GetUnLockLibResult();
	CUTOOL_API unsigned long long FunType GetCanUnlockWaitTime();
	CUTOOL_API void FunType Encrypt(unsigned char  in[8], unsigned char  out[8]);
	CUTOOL_API void FunType Decrypt(unsigned char  in[8], unsigned char  out[8]);
	CUTOOL_API void FunType SetEncrptKey(const unsigned char  key[8]);
	CUTOOL_API unsigned int FunType GetXY_PointRotation(const double CX, const double CY, const double X, const double Y, const double R, double& dX, double& dY);
	CUTOOL_API unsigned int FunType GetXYR_CCDx2(const double CX, const double CY, const double X1, const double Y1, const double X2, double Y2,
		const double TargetX1, const double TargetY1, const double TargetX2, const double TargetY2, const int AlignmentPos,
		double& dX, double& dY, double &dR);
	CUTOOL_API BOOL FunType FindCircleByPoints(const double *pPointAryX, const double *pPointAryY, const int PointCount, const double ResidualPercent, double &dblCenterX, double &dblCenterY, double &dblRadius);
	CUTOOL_API BOOL FunType GetUVW(bool XYInverse,
		double SX1, double SX2, double SY, //X1,X2,Y在UVW平台上的安裝角度
		double dblR, 					//UVW平台中心到支點的距離
		double OffsetX, double dblOffsetY, double dblOffsetS, //這次要偏移的X,Y及角度
		double MX1, double MX2, double MY,	//目前UVW X1,X2,Y的馬達絕對值
		double *dblRetX1, double *dblRetX2, double *dblRetY); //回傳X1, X2, Y要走的絕對值

#if defined(__cplusplus)
}
#endif // 
