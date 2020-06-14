/// @ref gtx_optimum_pow
/// @file glm/gtx/optimum_pow.inl

namespace glm
{
	template <typename genType>
	GLM_FUNC_QUALIFIER genType pow2(__thread__ genType const & x)
	{
		return x * x;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER genType pow3(__thread__ genType const & x)
	{
		return x * x * x;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER genType pow4(__thread__ genType const & x)
	{
		return (x * x) * (x * x);
	}
}//namespace glm
