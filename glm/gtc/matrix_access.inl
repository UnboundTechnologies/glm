/// @ref gtc_matrix_access
/// @file glm/gtc/matrix_access.inl

namespace glm
{
	template <typename genType>
	GLM_FUNC_QUALIFIER genType row
	(
		__thread__ genType const & m,
		length_t index,
		__thread__ typename genType::row_type const & x
	)
	{
		assert(index >= 0 && index < m[0].length());

		genType Result = m;
		for(length_t i = 0; i < m.length(); ++i)
			Result[i][index] = x[i];
		return Result;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER typename genType::row_type row
	(
		__thread__ genType const & m,
		length_t index
	)
	{
		assert(index >= 0 && index < m[0].length());

		typename genType::row_type Result;
		for(length_t i = 0; i < m.length(); ++i)
			Result[i] = m[i][index];
		return Result;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER genType column
	(
		__thread__ genType const & m,
		length_t index,
		__thread__ typename genType::col_type const & x
	)
	{
		assert(index >= 0 && index < m.length());

		genType Result = m;
		Result[index] = x;
		return Result;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER typename genType::col_type column
	(
		__thread__ genType const & m,
		length_t index
	)
	{
		assert(index >= 0 && index < m.length());

		return m[index];
	}
}//namespace glm
