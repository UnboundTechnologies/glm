/// @ref gtx_range
/// @file glm/gtx/range.hpp
/// @author Joshua Moerman
///
/// @defgroup gtx_range GLM_GTX_range
/// @ingroup gtx
///
/// @brief Defines begin and end for vectors and matrices. Useful for range-based for loop.
/// The range is defined over the elements, not over columns or rows (e.g. mat4 has 16 elements).
///
/// <glm/gtx/range.hpp> need to be included to use these functionalities.

#pragma once

// Dependencies
#include "../detail/setup.hpp"

#if !GLM_HAS_RANGE_FOR
#	error "GLM_GTX_range requires C++11 suppport or 'range for'"
#endif

#include "../gtc/type_ptr.hpp"
#include "../gtc/vec1.hpp"

namespace glm
{
	/// @addtogroup gtx_range
	/// @{

	template <typename T, precision P>
	inline length_t components(__thread__ tvec1<T, P> const & v)
	{
		return v.length();
	}
	
	template <typename T, precision P>
	inline length_t components(__thread__ tvec2<T, P> const & v)
	{
		return v.length();
	}
	
	template <typename T, precision P>
	inline length_t components(__thread__ tvec3<T, P> const & v)
	{
		return v.length();
	}
	
	template <typename T, precision P>
	inline length_t components(__thread__ tvec4<T, P> const & v)
	{
		return v.length();
	}
	
	template <typename genType>
	inline length_t components(__thread__ genType const & m)
	{
		return m.length() * m[0].length();
	}
	
	template <typename genType>
	inline __thread__ typename genType::value_type const * begin(__thread__ genType const & v)
	{
		return value_ptr(v);
	}

	template <typename genType>
	inline __thread__ typename genType::value_type const * end(__thread__ genType const & v)
	{
		return begin(v) + components(v);
	}

	template <typename genType>
	inline __thread__ typename genType::value_type * begin(__thread__ genType& v)
	{
		return value_ptr(v);
	}

	template <typename genType>
	inline __thread__ typename genType::value_type * end(__thread__ genType& v)
	{
		return begin(v) + components(v);
	}

	/// @}
}//namespace glm
