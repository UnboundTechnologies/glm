/// @ref gtx_intersect
/// @file glm/gtx/intersect.inl

namespace glm
{
	template <typename genType>
	GLM_FUNC_QUALIFIER bool intersectRayPlane
	(
	    __thread__ genType const & orig, __thread__ genType const & dir,
	    __thread__ genType const & planeOrig, __thread__ genType const & planeNormal,
	    __thread__ typename genType::value_type & intersectionDistance
	)
	{
		typename genType::value_type d = glm::dot(dir, planeNormal);
		typename genType::value_type Epsilon = std::numeric_limits<typename genType::value_type>::epsilon();

		if(d < -Epsilon)
		{
			intersectionDistance = glm::dot(planeOrig - orig, planeNormal) / d;
			return true;
		}

		return false;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER bool intersectRayTriangle
	(
	    __thread__ genType const & orig, __thread__ genType const & dir,
	    __thread__ genType const & v0, __thread__ genType const & v1, __thread__ genType const & v2,
	    __thread__ genType & baryPosition
	)
	{
		genType e1 = v1 - v0;
		genType e2 = v2 - v0;

		genType p = glm::cross(dir, e2);

		typename genType::value_type a = glm::dot(e1, p);

		typename genType::value_type Epsilon = std::numeric_limits<typename genType::value_type>::epsilon();
		if(a < Epsilon && a > -Epsilon)
			return false;

		typename genType::value_type f = typename genType::value_type(1.0f) / a;

		genType s = orig - v0;
		baryPosition.x = f * glm::dot(s, p);
		if(baryPosition.x < typename genType::value_type(0.0f))
			return false;
		if(baryPosition.x > typename genType::value_type(1.0f))
			return false;

		genType q = glm::cross(s, e1);
		baryPosition.y = f * glm::dot(dir, q);
		if(baryPosition.y < typename genType::value_type(0.0f))
			return false;
		if(baryPosition.y + baryPosition.x > typename genType::value_type(1.0f))
			return false;

		baryPosition.z = f * glm::dot(e2, q);

		return baryPosition.z >= typename genType::value_type(0.0f);
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER bool intersectLineTriangle
	(
	    __thread__ genType const & orig, __thread__ genType const & dir,
	    __thread__ genType const & vert0, __thread__ genType const & vert1, __thread__ genType const & vert2,
	    __thread__ genType & position
	)
	{
		typename genType::value_type Epsilon = std::numeric_limits<typename genType::value_type>::epsilon();

		genType edge1 = vert1 - vert0;
		genType edge2 = vert2 - vert0;

		genType pvec = cross(dir, edge2);

		float det = dot(edge1, pvec);

		if (det > -Epsilon && det < Epsilon)
			return false;
		float inv_det = typename genType::value_type(1) / det;

		genType tvec = orig - vert0;

		position.y = dot(tvec, pvec) * inv_det;
		if (position.y < typename genType::value_type(0) || position.y > typename genType::value_type(1))
			return false;

		genType qvec = cross(tvec, edge1);

		position.z = dot(dir, qvec) * inv_det;
		if (position.z < typename genType::value_type(0) || position.y + position.z > typename genType::value_type(1))
			return false;

		position.x = dot(edge2, qvec) * inv_det;

		return true;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER bool intersectRaySphere
	(
	    __thread__ genType const & rayStarting, __thread__ genType const & rayNormalizedDirection,
	    __thread__ genType const & sphereCenter, const typename genType::value_type sphereRadiusSquered,
	    __thread__ typename genType::value_type & intersectionDistance
	)
	{
		typename genType::value_type Epsilon = std::numeric_limits<typename genType::value_type>::epsilon();
		genType diff = sphereCenter - rayStarting;
		typename genType::value_type t0 = dot(diff, rayNormalizedDirection);
		typename genType::value_type dSquared = dot(diff, diff) - t0 * t0;
		if( dSquared > sphereRadiusSquered )
		{
			return false;
		}
		typename genType::value_type t1 = sqrt( sphereRadiusSquered - dSquared );
		intersectionDistance = t0 > t1 + Epsilon ? t0 - t1 : t0 + t1;
		return intersectionDistance > Epsilon;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER bool intersectRaySphere
	(
	    __thread__ genType const & rayStarting, __thread__ genType const & rayNormalizedDirection,
	    __thread__ genType const & sphereCenter, const typename genType::value_type sphereRadius,
	    __thread__ genType & intersectionPosition, __thread__ genType & intersectionNormal
	)
	{
		typename genType::value_type distance;
		if( intersectRaySphere( rayStarting, rayNormalizedDirection, sphereCenter, sphereRadius * sphereRadius, distance ) )
		{
			intersectionPosition = rayStarting + rayNormalizedDirection * distance;
			intersectionNormal = (intersectionPosition - sphereCenter) / sphereRadius;
			return true;
		}
		return false;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER bool intersectLineSphere
	(
	    __thread__ genType const & point0, __thread__ genType const & point1,
	    __thread__ genType const & sphereCenter, typename genType::value_type sphereRadius,
	    __thread__ genType & intersectionPoint1, __thread__ genType & intersectionNormal1, 
	    __thread__ genType & intersectionPoint2, __thread__ genType & intersectionNormal2
	)
	{
		typename genType::value_type Epsilon = std::numeric_limits<typename genType::value_type>::epsilon();
		genType dir = normalize(point1 - point0);
		genType diff = sphereCenter - point0;
		typename genType::value_type t0 = dot(diff, dir);
		typename genType::value_type dSquared = dot(diff, diff) - t0 * t0;
		if( dSquared > sphereRadius * sphereRadius )
		{
			return false;
		}
		typename genType::value_type t1 = sqrt( sphereRadius * sphereRadius - dSquared );
		if( t0 < t1 + Epsilon )
			t1 = -t1;
		intersectionPoint1 = point0 + dir * (t0 - t1);
		intersectionNormal1 = (intersectionPoint1 - sphereCenter) / sphereRadius;
		intersectionPoint2 = point0 + dir * (t0 + t1);
		intersectionNormal2 = (intersectionPoint2 - sphereCenter) / sphereRadius;
		return true;
	}
}//namespace glm
