/// @ref gtx_handed_coordinate_space
/// @file glm/gtx/handed_coordinate_space.inl

namespace glm
{
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER bool rightHanded
	(
		__thread__ tvec3<T, P> const & tangent,
		__thread__ tvec3<T, P> const & binormal,
		__thread__ tvec3<T, P> const & normal
	)
	{
		return dot(cross(normal, tangent), binormal) > T(0);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER bool leftHanded
	(
		__thread__ tvec3<T, P> const & tangent,
		__thread__ tvec3<T, P> const & binormal,
		__thread__ tvec3<T, P> const & normal
	)
	{
		return dot(cross(normal, tangent), binormal) < T(0);
	}
}//namespace glm
