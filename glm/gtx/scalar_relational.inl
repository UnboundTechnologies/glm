/// @ref gtx_scalar_relational
/// @file glm/gtx/scalar_relational.inl

namespace glm
{
	template <typename T>
	GLM_FUNC_QUALIFIER bool lessThan
	(
		__thread__ T const & x, 
		__thread__ T const & y
	)
	{
		return x < y;
	}

	template <typename T>
	GLM_FUNC_QUALIFIER bool lessThanEqual
	(
		__thread__ T const & x, 
		__thread__ T const & y
	)
	{
		return x <= y;
	}

	template <typename T>
	GLM_FUNC_QUALIFIER bool greaterThan
	(
		__thread__ T const & x, 
		__thread__ T const & y
	)
	{
		return x > y;
	}

	template <typename T>
	GLM_FUNC_QUALIFIER bool greaterThanEqual
	(
		__thread__ T const & x, 
		__thread__ T const & y
	)
	{
		return x >= y;
	}

	template <typename T>
	GLM_FUNC_QUALIFIER bool equal
	(
		__thread__ T const & x, 
		__thread__ T const & y
	)
	{
		return x == y;
	}

	template <typename T>
	GLM_FUNC_QUALIFIER bool notEqual
	(
		__thread__ T const & x, 
		__thread__ T const & y
	)
	{
		return x != y;
	}

	GLM_FUNC_QUALIFIER bool any
	(
		bool const & x
	)
	{
		return x;
	}

	GLM_FUNC_QUALIFIER bool all
	(
		bool const & x
	)
	{
		return x;
	}

	GLM_FUNC_QUALIFIER bool not_
	(
		bool const & x
	)
	{
		return !x;
	}
}//namespace glm
