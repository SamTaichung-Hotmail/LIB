#pragma once
#pragma warning( disable : 4091)

#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "Base.h"				
#include "Coordinate.h"				
namespace AutoLib{
	AUTOMALIB_API class MCCD : public MBase
	{
	public:
		enum CCDTYPE {
			ccdBaslerACA1300,
		};
		AUTOMALIB_API MCCD(MBase *pParent,CString strID, CString strName, CString strUnit);
		AUTOMALIB_API virtual ~MCCD();

		AUTOMALIB_API virtual void LoadMachineData(CADOConnection * pC, bool bAllChildsLoad);
		AUTOMALIB_API virtual void SaveMachineData(CADOConnection * pC, bool bAllChildsSave);

		AUTOMALIB_API virtual bool Calibrate(DCoordinate MX1, DCoordinate MX2, DCoordinate MY1, DCoordinate MY2,
						DCoordinate CCDX1, DCoordinate CCDX2, DCoordinate CCDY1, DCoordinate CCDY2);
		AUTOMALIB_API virtual bool Calibrate(CString strFile,CCDTYPE ccdType=ccdBaslerACA1300);
		AUTOMALIB_API virtual void SetCalibrate(DCoordinate cdCoefficient);
		AUTOMALIB_API virtual void SetWidthHeight(double dblWidth,double dblHeight);
		AUTOMALIB_API virtual void ResetCalibrate();
		AUTOMALIB_API virtual DCoordinate GetCoefficient(); //取得換算係數
		AUTOMALIB_API virtual DCoordinate GetMechanical(DCoordinate cdCCD); //取得換算到機構座標
		AUTOMALIB_API virtual DCoordinate GetCCDCoodinate(DCoordinate cdMechanical); //取得換算到CCD座標
		AUTOMALIB_API virtual CString GetDeviceID(); //取得此CCD裝置編號
		AUTOMALIB_API virtual void SetDeviceID(CString strID); //設定此CCD裝置編號
		AUTOMALIB_API virtual void SetConnectPort(int ConnectPort); //設定此CCD連線埠號(-1表示沒有連線)
		AUTOMALIB_API virtual int GetConnectPort(); //取得此CCD連線埠號(-1表示沒有連線)
		CString m_Unit; //X,Y單位名稱（mm,um)
	protected:
		int m_ConnectPort;
		CString m_strDeviceID;
		CString m_strCalibrationFile;
		DCoordinate m_cdCoefficient; //X,Y比例值及角度
		bool m_bUseCalibrateFile;
		double m_dblWidth, m_dblHeight;
		CCDTYPE m_ccdType;
	};

}//namespace AutoLib
