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
		AUTOMALIB_API virtual DCoordinate GetCoefficient(); //���o����Y��
		AUTOMALIB_API virtual DCoordinate GetMechanical(DCoordinate cdCCD); //���o�������c�y��
		AUTOMALIB_API virtual DCoordinate GetCCDCoodinate(DCoordinate cdMechanical); //���o�����CCD�y��
		AUTOMALIB_API virtual CString GetDeviceID(); //���o��CCD�˸m�s��
		AUTOMALIB_API virtual void SetDeviceID(CString strID); //�]�w��CCD�˸m�s��
		AUTOMALIB_API virtual void SetConnectPort(int ConnectPort); //�]�w��CCD�s�u��(-1��ܨS���s�u)
		AUTOMALIB_API virtual int GetConnectPort(); //���o��CCD�s�u��(-1��ܨS���s�u)
		CString m_Unit; //X,Y���W�١]mm,um)
	protected:
		int m_ConnectPort;
		CString m_strDeviceID;
		CString m_strCalibrationFile;
		DCoordinate m_cdCoefficient; //X,Y��ҭȤΨ���
		bool m_bUseCalibrateFile;
		double m_dblWidth, m_dblHeight;
		CCDTYPE m_ccdType;
	};

}//namespace AutoLib
