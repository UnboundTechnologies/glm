/// @ref gtx_euler_angles
/// @file glm/gtx/euler_angles.inl

#include "compatibility.hpp" // glm::atan2

namespace glm
{
	template <typename T>
	GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> eulerAngleX
	(
		__thread__ T const & angleX
	)
	{
		T cosX = glm::cos(angleX);
		T sinX = glm::sin(angleX);
	
		return tmat4x4<T, defaultp>(
			T(1), T(0), T(0), T(0),
			T(0), cosX, sinX, T(0),
			T(0),-sinX, cosX, T(0),
			T(0), T(0), T(0), T(1));
	}

	template <typename T>
	GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> eulerAngleY
	(
		__thread__ T const & angleY
	)
	{
		T cosY = glm::cos(angleY);
		T sinY = glm::sin(angleY);

		return tmat4x4<T, defaultp>(
			cosY,	T(0),	-sinY,	T(0),
			T(0),	T(1),	T(0),	T(0),
			sinY,	T(0),	cosY,	T(0),
			T(0),	T(0),	T(0),	T(1));
	}

	template <typename T>
	GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> eulerAngleZ
	(
		__thread__ T const & angleZ
	)
	{
		T cosZ = glm::cos(angleZ);
		T sinZ = glm::sin(angleZ);

		return tmat4x4<T, defaultp>(
			cosZ,	sinZ,	T(0), T(0),
			-sinZ,	cosZ,	T(0), T(0),
			T(0),	T(0),	T(1), T(0),
			T(0),	T(0),	T(0), T(1));
	}

	template <typename T>
	GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> eulerAngleXY
	(
		__thread__ T const & angleX,
		__thread__ T const & angleY
	)
	{
		T cosX = glm::cos(angleX);
		T sinX = glm::sin(angleX);
		T cosY = glm::cos(angleY);
		T sinY = glm::sin(angleY);

		return tmat4x4<T, defaultp>(
			cosY,   -sinX * -sinY,  cosX * -sinY,   T(0),
			T(0),   cosX,           sinX,           T(0),
			sinY,   -sinX * cosY,   cosX * cosY,    T(0),
			T(0),   T(0),           T(0),           T(1));
	}

	template <typename T>
	GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> eulerAngleYX
	(
		__thread__ T const & angleY,
		__thread__ T const & angleX
	)
	{
		T cosX = glm::cos(angleX);
		T sinX = glm::sin(angleX);
		T cosY = glm::cos(angleY);
		T sinY = glm::sin(angleY);

		return tmat4x4<T, defaultp>(
			cosY,          0,      -sinY,    T(0),
			sinY * sinX,  cosX, cosY * sinX, T(0),
			sinY * cosX, -sinX, cosY * cosX, T(0),
			T(0),         T(0),     T(0),    T(1));
	}

	template <typename T>
	GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> eulerAngleXZ
	(
		__thread__ T const & angleX,
		__thread__ T const & angleZ
	)
	{
		return eulerAngleX(angleX) * eulerAngleZ(angleZ);
	}

	template <typename T>
	GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> eulerAngleZX
	(
		__thread__ T const & angleZ,
		__thread__ T const & angleX
	)
	{
		return eulerAngleZ(angleZ) * eulerAngleX(angleX);
	}

	template <typename T>
	GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> eulerAngleYZ
	(
		__thread__ T const & angleY,
		__thread__ T const & angleZ
	)
	{
		return eulerAngleY(angleY) * eulerAngleZ(angleZ);
	}

	template <typename T>
	GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> eulerAngleZY
	(
		__thread__ T const & angleZ,
		__thread__ T const & angleY
	)
	{
		return eulerAngleZ(angleZ) * eulerAngleY(angleY);
	}
    
    template <typename T>
    GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> eulerAngleXYZ
    (
     __thread__ T const & t1,
     __thread__ T const & t2,
     __thread__ T const & t3
     )
    {
        T c1 = glm::cos(-t1);
        T c2 = glm::cos(-t2);
        T c3 = glm::cos(-t3);
        T s1 = glm::sin(-t1);
        T s2 = glm::sin(-t2);
        T s3 = glm::sin(-t3);
        
        tmat4x4<T, defaultp> Result;
        Result[0][0] = c2 * c3;
        Result[0][1] =-c1 * s3 + s1 * s2 * c3;
        Result[0][2] = s1 * s3 + c1 * s2 * c3;
        Result[0][3] = static_cast<T>(0);
        Result[1][0] = c2 * s3;
        Result[1][1] = c1 * c3 + s1 * s2 * s3;
        Result[1][2] =-s1 * c3 + c1 * s2 * s3;
        Result[1][3] = static_cast<T>(0);
        Result[2][0] =-s2;
        Result[2][1] = s1 * c2;
        Result[2][2] = c1 * c2;
        Result[2][3] = static_cast<T>(0);
        Result[3][0] = static_cast<T>(0);
        Result[3][1] = static_cast<T>(0);
        Result[3][2] = static_cast<T>(0);
        Result[3][3] = static_cast<T>(1);
        return Result;
    }
    
	template <typename T>
	GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> eulerAngleYXZ
	(
		__thread__ T const & yaw,
		__thread__ T const & pitch,
		__thread__ T const & roll
	)
	{
		T tmp_ch = glm::cos(yaw);
		T tmp_sh = glm::sin(yaw);
		T tmp_cp = glm::cos(pitch);
		T tmp_sp = glm::sin(pitch);
		T tmp_cb = glm::cos(roll);
		T tmp_sb = glm::sin(roll);

		tmat4x4<T, defaultp> Result;
		Result[0][0] = tmp_ch * tmp_cb + tmp_sh * tmp_sp * tmp_sb;
		Result[0][1] = tmp_sb * tmp_cp;
		Result[0][2] = -tmp_sh * tmp_cb + tmp_ch * tmp_sp * tmp_sb;
		Result[0][3] = static_cast<T>(0);
		Result[1][0] = -tmp_ch * tmp_sb + tmp_sh * tmp_sp * tmp_cb;
		Result[1][1] = tmp_cb * tmp_cp;
		Result[1][2] = tmp_sb * tmp_sh + tmp_ch * tmp_sp * tmp_cb;
		Result[1][3] = static_cast<T>(0);
		Result[2][0] = tmp_sh * tmp_cp;
		Result[2][1] = -tmp_sp;
		Result[2][2] = tmp_ch * tmp_cp;
		Result[2][3] = static_cast<T>(0);
		Result[3][0] = static_cast<T>(0);
		Result[3][1] = static_cast<T>(0);
		Result[3][2] = static_cast<T>(0);
		Result[3][3] = static_cast<T>(1);
		return Result;
	}

	template <typename T>
	GLM_FUNC_QUALIFIER tmat4x4<T, defaultp> yawPitchRoll
	(
		__thread__ T const & yaw,
		__thread__ T const & pitch,
		__thread__ T const & roll
	)
	{
		T tmp_ch = glm::cos(yaw);
		T tmp_sh = glm::sin(yaw);
		T tmp_cp = glm::cos(pitch);
		T tmp_sp = glm::sin(pitch);
		T tmp_cb = glm::cos(roll);
		T tmp_sb = glm::sin(roll);

		tmat4x4<T, defaultp> Result;
		Result[0][0] = tmp_ch * tmp_cb + tmp_sh * tmp_sp * tmp_sb;
		Result[0][1] = tmp_sb * tmp_cp;
		Result[0][2] = -tmp_sh * tmp_cb + tmp_ch * tmp_sp * tmp_sb;
		Result[0][3] = static_cast<T>(0);
		Result[1][0] = -tmp_ch * tmp_sb + tmp_sh * tmp_sp * tmp_cb;
		Result[1][1] = tmp_cb * tmp_cp;
		Result[1][2] = tmp_sb * tmp_sh + tmp_ch * tmp_sp * tmp_cb;
		Result[1][3] = static_cast<T>(0);
		Result[2][0] = tmp_sh * tmp_cp;
		Result[2][1] = -tmp_sp;
		Result[2][2] = tmp_ch * tmp_cp;
		Result[2][3] = static_cast<T>(0);
		Result[3][0] = static_cast<T>(0);
		Result[3][1] = static_cast<T>(0);
		Result[3][2] = static_cast<T>(0);
		Result[3][3] = static_cast<T>(1);
		return Result;
	}

	template <typename T>
	GLM_FUNC_QUALIFIER tmat2x2<T, defaultp> orientate2
	(
		__thread__ T const & angle
	)
	{
		T c = glm::cos(angle);
		T s = glm::sin(angle);

		tmat2x2<T, defaultp> Result;
		Result[0][0] = c;
		Result[0][1] = s;
		Result[1][0] = -s;
		Result[1][1] = c;
		return Result;
	}

	template <typename T>
	GLM_FUNC_QUALIFIER tmat3x3<T, defaultp> orientate3
	(
		__thread__ T const & angle
	)
	{
		T c = glm::cos(angle);
		T s = glm::sin(angle);

		tmat3x3<T, defaultp> Result;
		Result[0][0] = c;
		Result[0][1] = s;
		Result[0][2] = 0.0f;
		Result[1][0] = -s;
		Result[1][1] = c;
		Result[1][2] = 0.0f;
		Result[2][0] = 0.0f;
		Result[2][1] = 0.0f;
		Result[2][2] = 1.0f;
		return Result;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat3x3<T, P> orientate3
	(
		__thread__ tvec3<T, P> const & angles
	)
	{
		return tmat3x3<T, P>(yawPitchRoll(angles.z, angles.x, angles.y));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> orientate4
	(
		__thread__ tvec3<T, P> const & angles
	)
	{
		return yawPitchRoll(angles.z, angles.x, angles.y);
	}
    
    template <typename T>
    GLM_FUNC_DECL void extractEulerAngleXYZ(__thread__ tmat4x4<T, defaultp> const & M,
                                            __thread__ T & t1,
                                            __thread__ T & t2,
                                            __thread__ T & t3)
    {
        float T1 = glm::atan2<T, defaultp>(M[2][1], M[2][2]);
        float C2 = glm::sqrt(M[0][0]*M[0][0] + M[1][0]*M[1][0]);
        float T2 = glm::atan2<T, defaultp>(-M[2][0], C2);
        float S1 = glm::sin(T1);
        float C1 = glm::cos(T1);
        float T3 = glm::atan2<T, defaultp>(S1*M[0][2] - C1*M[0][1], C1*M[1][1] - S1*M[1][2  ]);
        t1 = -T1;
        t2 = -T2;
        t3 = -T3;
    }
}//namespace glm
