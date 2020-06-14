/// @ref gtx_log_base
/// @file glm/gtx/log_base.inl

namespace glm
{
	template <typename genType> 
	GLM_FUNC_QUALIFIER genType log(__thread__ genType const & x, __thread__ genType const & base)
	{
		assert(x != genType(0));
		return glm::log(x) / glm::log(base);
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<T, P> log(__thread__ vecType<T, P> const & x, __thread__ vecType<T, P> const & base)
	{
		return glm::log(x) / glm::log(base);
	}
}//namespace glm
