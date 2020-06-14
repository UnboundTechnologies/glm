/// @ref gtx_projection
/// @file glm/gtx/projection.inl

namespace glm
{
	template <typename vecType>
	GLM_FUNC_QUALIFIER vecType proj(__thread__ vecType const & x, __thread__ vecType const & Normal)
	{
		return glm::dot(x, Normal) / glm::dot(Normal, Normal) * Normal;
	}
}//namespace glm
