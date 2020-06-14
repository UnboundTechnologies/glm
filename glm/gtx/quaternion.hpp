/// @ref gtx_quaternion
/// @file glm/gtx/quaternion.hpp
///
/// @see core (dependence)
/// @see gtx_extented_min_max (dependence)
///
/// @defgroup gtx_quaternion GLM_GTX_quaternion
/// @ingroup gtx
///
/// @brief Extented quaternion types and functions
///
/// <glm/gtx/quaternion.hpp> need to be included to use these functionalities.

#pragma once

// Dependency:
#include "../glm.hpp"
#include "../gtc/constants.hpp"
#include "../gtc/quaternion.hpp"
#include "../gtx/norm.hpp"

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_quaternion extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_quaternion
	/// @{

	/// Compute a cross product between a quaternion and a vector.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tvec3<T, P> cross(
	    __thread__ tquat<T, P> const & q,
		__thread__ tvec3<T, P> const & v);

	//! Compute a cross product between a vector and a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tvec3<T, P> cross(
		__thread__ tvec3<T, P> const & v,
	    __thread__ tquat<T, P> const & q);

	//! Compute a point on a path according squad equation. 
	//! q1 and q2 are control points; s1 and s2 are intermediate control points.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tquat<T, P> squad(
	    __thread__ tquat<T, P> const & q1,
	    __thread__ tquat<T, P> const & q2,
	    __thread__ tquat<T, P> const & s1,
	    __thread__ tquat<T, P> const & s2,
		__thread__ T const & h);

	//! Returns an intermediate control point for squad interpolation.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tquat<T, P> intermediate(
	    __thread__ tquat<T, P> const & prev,
	    __thread__ tquat<T, P> const & curr,
	    __thread__ tquat<T, P> const & next);

	//! Returns a exp of a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tquat<T, P> exp(
	    __thread__ tquat<T, P> const & q);

	//! Returns a log of a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tquat<T, P> log(
	    __thread__ tquat<T, P> const & q);

	/// Returns x raised to the y power.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tquat<T, P> pow(
	    __thread__ tquat<T, P> const & x,
		__thread__ T const & y);

	//! Returns quarternion square root.
	///
	/// @see gtx_quaternion
	//template<typename T, precision P>
	//tquat<T, P> sqrt(
	//    __thread__ tquat<T, P> const & q);

	//! Rotates a 3 components vector by a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tvec3<T, P> rotate(
	    __thread__ tquat<T, P> const & q,
		__thread__ tvec3<T, P> const & v);

	/// Rotates a 4 components vector by a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tvec4<T, P> rotate(
	    __thread__ tquat<T, P> const & q,
	    __thread__ tvec4<T, P> const & v);

	/// Extract the real component of a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL T extractRealComponent(
	    __thread__ tquat<T, P> const & q);

	/// Converts a quaternion to a 3 * 3 matrix.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tmat3x3<T, P> toMat3(
	    __thread__ tquat<T, P> const & x){return mat3_cast(x);}

	/// Converts a quaternion to a 4 * 4 matrix.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tmat4x4<T, P> toMat4(
	    __thread__ tquat<T, P> const & x){return mat4_cast(x);}

	/// Converts a 3 * 3 matrix to a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tquat<T, P> toQuat(
		__thread__ tmat3x3<T, P> const & x){return quat_cast(x);}

	/// Converts a 4 * 4 matrix to a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tquat<T, P> toQuat(
		__thread__ tmat4x4<T, P> const & x){return quat_cast(x);}

	/// Quaternion interpolation using the rotation short path.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tquat<T, P> shortMix(
	    __thread__ tquat<T, P> const & x,
	    __thread__ tquat<T, P> const & y,
		__thread__ T const & a);

	/// Quaternion normalized linear interpolation.
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tquat<T, P> fastMix(
	    __thread__ tquat<T, P> const & x,
	    __thread__ tquat<T, P> const & y,
		__thread__ T const & a);

	/// Compute the rotation between two vectors.
	/// param orig vector, needs to be normalized
	/// param dest vector, needs to be normalized
	///
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL tquat<T, P> rotation(
		__thread__ tvec3<T, P> const & orig, 
		__thread__ tvec3<T, P> const & dest);

	/// Returns the squared length of x.
	/// 
	/// @see gtx_quaternion
	template<typename T, precision P>
	GLM_FUNC_DECL T length2(__thread__ tquat<T, P> const & q);

	/// @}
}//namespace glm

#include "quaternion.inl"
