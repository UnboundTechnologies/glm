/// @ref gtx_normal
/// @file glm/gtx/normal.inl

namespace glm
{
	template <typename T, precision P> 
	GLM_FUNC_QUALIFIER tvec3<T, P> triangleNormal
	(
		__thread__ tvec3<T, P> const & p1, 
		__thread__ tvec3<T, P> const & p2, 
		__thread__ tvec3<T, P> const & p3
	)
	{
		return normalize(cross(p1 - p2, p1 - p3));
	}
}//namespace glm
