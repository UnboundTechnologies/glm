/// @ref gtx_vector_query
/// @file glm/gtx/vector_query.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_vector_query GLM_GTX_vector_query
/// @ingroup gtx
///
/// @brief Query informations of vector types
///
/// <glm/gtx/vector_query.hpp> need to be included to use these functionalities.

#pragma once

// Dependency:
#include "../glm.hpp"

#if !__METAL_VERSION__
#   include <cfloat>
#   include <limits>
#endif // __METAL_VERSION__

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_vector_query extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_vector_query
	/// @{

	//! Check whether two vectors are collinears.
	/// @see gtx_vector_query extensions.
	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_DECL bool areCollinear(__thread__ vecType<T, P> const & v0, __thread__ vecType<T, P> const & v1, __thread__ T const & epsilon);
		
	//! Check whether two vectors are orthogonals.
	/// @see gtx_vector_query extensions.
	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_DECL bool areOrthogonal(__thread__ vecType<T, P> const & v0, __thread__ vecType<T, P> const & v1, __thread__ T const & epsilon);

	//! Check whether a vector is normalized.
	/// @see gtx_vector_query extensions.
	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_DECL bool isNormalized(__thread__ vecType<T, P> const & v, __thread__ T const & epsilon);
		
	//! Check whether a vector is null.
	/// @see gtx_vector_query extensions.
	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_DECL bool isNull(__thread__ vecType<T, P> const & v, __thread__ T const & epsilon);

	//! Check whether a each component of a vector is null.
	/// @see gtx_vector_query extensions.
	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_DECL vecType<bool, P> isCompNull(__thread__ vecType<T, P> const & v, __thread__ T const & epsilon);

	//! Check whether two vectors are orthonormal.
	/// @see gtx_vector_query extensions.
	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_DECL bool areOrthonormal(__thread__ vecType<T, P> const & v0, __thread__ vecType<T, P> const & v1, __thread__ T const & epsilon);

	/// @}
}// namespace glm

#include "vector_query.inl"
