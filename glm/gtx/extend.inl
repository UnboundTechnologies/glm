/// @ref gtx_extend
/// @file glm/gtx/extend.inl

namespace glm
{
	template <typename genType>
	GLM_FUNC_QUALIFIER genType extend
	(
		__thread__ genType const & Origin,
		__thread__ genType const & Source,
		__thread__ genType const & Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec2<T, P> extend
	(
		__thread__ tvec2<T, P> const & Origin,
		__thread__ tvec2<T, P> const & Source,
		__thread__ T const & Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec3<T, P> extend
	(
		__thread__ tvec3<T, P> const & Origin,
		__thread__ tvec3<T, P> const & Source,
		__thread__ T const & Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec4<T, P> extend
	(
		__thread__ tvec4<T, P> const & Origin,
		__thread__ tvec4<T, P> const & Source,
		__thread__ T const & Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}
}//namespace glm
