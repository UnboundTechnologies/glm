/// @ref gtx_perpendicular
/// @file glm/gtx/perpendicular.inl

namespace glm
{
	template <typename vecType> 
	GLM_FUNC_QUALIFIER vecType perp
	(
		__thread__ vecType const & x, 
		__thread__ vecType const & Normal
	)
	{
		return x - proj(x, Normal);
	}
}//namespace glm
