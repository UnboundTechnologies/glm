/// @ref gtx_vector_angle
/// @file glm/gtx/vector_angle.inl

namespace glm
{
	template <typename genType> 
	GLM_FUNC_QUALIFIER genType angle
	(
	    __thread__ genType const & x,
	    __thread__ genType const & y
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genType>::is_iec559, "'angle' only accept floating-point inputs");
		return acos(clamp(dot(x, y), genType(-1), genType(1)));
	}

	template <typename T, precision P, template <typename, precision> class vecType> 
	GLM_FUNC_QUALIFIER T angle
	(
	    __thread__ vecType<T, P> const & x,
	    __thread__ vecType<T, P> const & y
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'angle' only accept floating-point inputs");
		return acos(clamp(dot(x, y), T(-1), T(1)));
	}

	//! \todo epsilon is hard coded to 0.01
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER T orientedAngle
	(
	    __thread__ tvec2<T, P> const & x,
	    __thread__ tvec2<T, P> const & y
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'orientedAngle' only accept floating-point inputs");
		T const Angle(acos(clamp(dot(x, y), T(-1), T(1))));

		if(all(epsilonEqual(y, glm::rotate(x, Angle), T(0.0001))))
			return Angle;
		else
			return -Angle;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER T orientedAngle
	(
		__thread__ tvec3<T, P> const & x,
		__thread__ tvec3<T, P> const & y,
		__thread__ tvec3<T, P> const & ref
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'orientedAngle' only accept floating-point inputs");

		T const Angle(acos(clamp(dot(x, y), T(-1), T(1))));
		return mix(Angle, -Angle, dot(ref, cross(x, y)) < T(0));
	}
}//namespace glm
