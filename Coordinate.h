#pragma once
#pragma warning( disable : 4091 4005)
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#define PI 3.14159265358979323846
namespace AutoLib {
	AUTOMALIB_API class DCoordinate
	{
	public:
		enum RotationType {
			RotationXY,
			RotationYZ,
			RotationXZ,
		};
		enum AngleType {
			AngleXY,
			AngleYZ,
			AngleXZ,
		};
		AUTOMALIB_API DCoordinate(double px = 0, double py = 0, double pz = 0, double ps = 0);
		AUTOMALIB_API ~DCoordinate(void);
		AUTOMALIB_API double GetLength(const DCoordinate &p);
		AUTOMALIB_API double GetAngle(const DCoordinate &p,AngleType RT = AngleType::AngleXY);
		AUTOMALIB_API DCoordinate operator+(const DCoordinate &p);
		AUTOMALIB_API DCoordinate operator*(const DCoordinate &p);
		AUTOMALIB_API DCoordinate operator/(const DCoordinate &p);
		AUTOMALIB_API DCoordinate operator+(const double &p);
		AUTOMALIB_API DCoordinate operator*(const double &p);
		AUTOMALIB_API DCoordinate operator/(const double &p);
		AUTOMALIB_API DCoordinate operator+=(const DCoordinate &p);
		AUTOMALIB_API DCoordinate operator-(const DCoordinate &p);
		AUTOMALIB_API DCoordinate operator-=(const DCoordinate &p);
		AUTOMALIB_API DCoordinate operator+=(const double &p);
		AUTOMALIB_API DCoordinate operator-(const double &p);
		AUTOMALIB_API DCoordinate operator-=(const double &p);
		AUTOMALIB_API DCoordinate Rotation(const double dblAngle,DCoordinate &RotationCenter, RotationType RT=RotationType::RotationXY);
		AUTOMALIB_API void Zero(){x=0;y=0;s=0;z=0;};
		double x,y,z,s;
	};
}//namespace AutomaLib