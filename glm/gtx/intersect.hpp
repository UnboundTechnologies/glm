/// @ref gtx_intersect
/// @file glm/gtx/intersect.hpp
///
/// @see core (dependence)
/// @see gtx_closest_point (dependence)
///
/// @defgroup gtx_intersect GLM_GTX_intersect
/// @ingroup gtx
///
/// @brief Add intersection functions
///
/// <glm/gtx/intersect.hpp> need to be included to use these functionalities.

#pragma once

// Dependency:
#if !__METAL_VERSION__
#   include <cfloat>
#   include <limits>
#endif // __METAL_VERSION__

#include "../glm.hpp"
#include "../geometric.hpp"
#include "../gtx/closest_point.hpp"
#include "../gtx/vector_query.hpp"

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_closest_point extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_intersect
	/// @{

	//! Compute the intersection of a ray and a plane.
	//! Ray direction and plane normal must be unit length.
	//! From GLM_GTX_intersect extension.
	template <typename genType>
	GLM_FUNC_DECL bool intersectRayPlane(
		__thread__ genType const & orig, __thread__ genType const & dir,
		__thread__ genType const & planeOrig, __thread__ genType const & planeNormal,
		__thread__ typename genType::value_type & intersectionDistance);

	//! Compute the intersection of a ray and a triangle.
	//! From GLM_GTX_intersect extension.
	template <typename genType>
	GLM_FUNC_DECL bool intersectRayTriangle(
		__thread__ genType const & orig, __thread__ genType const & dir,
		__thread__ genType const & vert0, __thread__ genType const & vert1, __thread__ genType const & vert2,
		__thread__ genType & baryPosition);

	//! Compute the intersection of a line and a triangle.
	//! From GLM_GTX_intersect extension.
	template <typename genType>
	GLM_FUNC_DECL bool intersectLineTriangle(
	    __thread__ genType const & orig, __thread__ genType const & dir,
	    __thread__ genType const & vert0, __thread__ genType const & vert1, __thread__ genType const & vert2,
	    __thread__ genType & position);

	//! Compute the intersection distance of a ray and a sphere. 
	//! The ray direction vector is unit length.
	//! From GLM_GTX_intersect extension.
	template <typename genType>
	GLM_FUNC_DECL bool intersectRaySphere(
	    __thread__ genType const & rayStarting, __thread__ genType const & rayNormalizedDirection,
	    __thread__ genType const & sphereCenter, typename genType::value_type const sphereRadiusSquered,
	    __thread__ typename genType::value_type & intersectionDistance);

	//! Compute the intersection of a ray and a sphere.
	//! From GLM_GTX_intersect extension.
	template <typename genType>
	GLM_FUNC_DECL bool intersectRaySphere(
	    __thread__ genType const & rayStarting, __thread__ genType const & rayNormalizedDirection,
	    __thread__ genType const & sphereCenter, const typename genType::value_type sphereRadius,
	    __thread__ genType & intersectionPosition, __thread__ genType & intersectionNormal);

	//! Compute the intersection of a line and a sphere.
	//! From GLM_GTX_intersect extension
	template <typename genType>
	GLM_FUNC_DECL bool intersectLineSphere(
	    __thread__ genType const & point0, __thread__ genType const & point1,
	    __thread__ genType const & sphereCenter, typename genType::value_type sphereRadius,
	    __thread__ genType & intersectionPosition1, __thread__ genType & intersectionNormal1,
	    __thread__ genType & intersectionPosition2 = genType(), __thread__ genType & intersectionNormal2 = genType());

	/// @}
}//namespace glm

#include "intersect.inl"
