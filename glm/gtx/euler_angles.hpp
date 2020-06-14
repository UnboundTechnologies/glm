/// @ref gtx_euler_angles
/// @file glm/gtx/euler_angles.hpp
///
/// @see core (dependence)
/// @see gtc_half_float (dependence)
///
/// @defgroup gtx_euler_angles GLM_GTX_euler_angles
/// @ingroup gtx
///
/// @brief Build matrices from Euler angles.
///
/// <glm/gtx/euler_angles.hpp> need to be included to use these functionalities.

#pragma once

// Dependency:
#include "../glm.hpp"

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_euler_angles extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_euler_angles
	/// @{

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from an euler angle X.
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> eulerAngleX(
		__thread__ T const & angleX);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from an euler angle Y.
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> eulerAngleY(
		__thread__ T const & angleY);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from an euler angle Z.
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> eulerAngleZ(
		__thread__ T const & angleZ);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (X * Y).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> eulerAngleXY(
		__thread__ T const & angleX,
		__thread__ T const & angleY);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Y * X).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> eulerAngleYX(
		__thread__ T const & angleY,
		__thread__ T const & angleX);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (X * Z).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> eulerAngleXZ(
		__thread__ T const & angleX,
		__thread__ T const & angleZ);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Z * X).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> eulerAngleZX(
		__thread__ T const & angle,
		__thread__ T const & angleX);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Y * Z).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> eulerAngleYZ(
		__thread__ T const & angleY,
		__thread__ T const & angleZ);

	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Z * Y).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> eulerAngleZY(
		__thread__ T const & angleZ,
		__thread__ T const & angleY);

    /// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (X * Y * Z).
    /// @see gtx_euler_angles
    template <typename T>
    GLM_FUNC_DECL tmat4x4<T, defaultp> eulerAngleXYZ(
        __thread__ T const & t1,
        __thread__ T const & t2,
        __thread__ T const & t3);
    
	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Y * X * Z).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> eulerAngleYXZ(
		__thread__ T const & yaw,
		__thread__ T const & pitch,
		__thread__ T const & roll);
    
	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Y * X * Z).
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL tmat4x4<T, defaultp> yawPitchRoll(
		__thread__ T const & yaw,
		__thread__ T const & pitch,
		__thread__ T const & roll);

	/// Creates a 2D 2 * 2 rotation matrix from an euler angle.
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL tmat2x2<T, defaultp> orientate2(__thread__ T const & angle);

	/// Creates a 2D 4 * 4 homogeneous rotation matrix from an euler angle.
	/// @see gtx_euler_angles
	template <typename T>
	GLM_FUNC_DECL tmat3x3<T, defaultp> orientate3(__thread__ T const & angle);

	/// Creates a 3D 3 * 3 rotation matrix from euler angles (Y * X * Z). 
	/// @see gtx_euler_angles
	template <typename T, precision P>
	GLM_FUNC_DECL tmat3x3<T, P> orientate3(__thread__ tvec3<T, P> const & angles);
		
	/// Creates a 3D 4 * 4 homogeneous rotation matrix from euler angles (Y * X * Z).
	/// @see gtx_euler_angles
	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x4<T, P> orientate4(__thread__ tvec3<T, P> const & angles);

    /// Extracts the (X * Y * Z) Euler angles from the rotation matrix M
    /// @see gtx_euler_angles
    template <typename T>
    GLM_FUNC_DECL void extractEulerAngleXYZ(__thread__ tmat4x4<T, defaultp> const & M,
                                            __thread__ T & t1,
                                            __thread__ T & t2,
                                            __thread__ T & t3);
    
	/// @}
}//namespace glm

#include "euler_angles.inl"
