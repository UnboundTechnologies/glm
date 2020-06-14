/// @ref gtx_matrix_major_storage
/// @file glm/gtx/matrix_major_storage.hpp
///
/// @see core (dependence)
/// @see gtx_extented_min_max (dependence)
///
/// @defgroup gtx_matrix_major_storage GLM_GTX_matrix_major_storage
/// @ingroup gtx
///
/// @brief Build matrices with specific matrix order, row or column
///
/// <glm/gtx/matrix_major_storage.hpp> need to be included to use these functionalities.

#pragma once

// Dependency:
#include "../glm.hpp"

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_matrix_major_storage extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_matrix_major_storage
	/// @{

	//! Build a row major matrix from row vectors.
	//! From GLM_GTX_matrix_major_storage extension.
	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> rowMajor2(
	    __thread__ tvec2<T, P> const & v1, 
	    __thread__ tvec2<T, P> const & v2);
		
	//! Build a row major matrix from other matrix.
	//! From GLM_GTX_matrix_major_storage extension.
	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> rowMajor2(
		__thread__ tmat2x2<T, P> const & m);

	//! Build a row major matrix from row vectors.
	//! From GLM_GTX_matrix_major_storage extension.
	template <typename T, precision P>
	GLM_FUNC_DECL tmat3x3<T, P> rowMajor3(
		__thread__ tvec3<T, P> const & v1, 
		__thread__ tvec3<T, P> const & v2, 
		__thread__ tvec3<T, P> const & v3);

	//! Build a row major matrix from other matrix.
	//! From GLM_GTX_matrix_major_storage extension.
	template <typename T, precision P>
	GLM_FUNC_DECL tmat3x3<T, P> rowMajor3(
		__thread__ tmat3x3<T, P> const & m);

	//! Build a row major matrix from row vectors.
	//! From GLM_GTX_matrix_major_storage extension.
	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x4<T, P> rowMajor4(
	    __thread__ tvec4<T, P> const & v1, 
	    __thread__ tvec4<T, P> const & v2,
	    __thread__ tvec4<T, P> const & v3, 
	    __thread__ tvec4<T, P> const & v4);

	//! Build a row major matrix from other matrix.
	//! From GLM_GTX_matrix_major_storage extension.
	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x4<T, P> rowMajor4(
		__thread__ tmat4x4<T, P> const & m);

	//! Build a column major matrix from column vectors.
	//! From GLM_GTX_matrix_major_storage extension.
	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> colMajor2(
	    __thread__ tvec2<T, P> const & v1, 
	    __thread__ tvec2<T, P> const & v2);
		
	//! Build a column major matrix from other matrix.
	//! From GLM_GTX_matrix_major_storage extension.
	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> colMajor2(
		__thread__ tmat2x2<T, P> const & m);

	//! Build a column major matrix from column vectors.
	//! From GLM_GTX_matrix_major_storage extension.
	template <typename T, precision P>
	GLM_FUNC_DECL tmat3x3<T, P> colMajor3(
		__thread__ tvec3<T, P> const & v1, 
		__thread__ tvec3<T, P> const & v2, 
		__thread__ tvec3<T, P> const & v3);
		
	//! Build a column major matrix from other matrix.
	//! From GLM_GTX_matrix_major_storage extension.
	template <typename T, precision P>
	GLM_FUNC_DECL tmat3x3<T, P> colMajor3(
		__thread__ tmat3x3<T, P> const & m);
		
	//! Build a column major matrix from column vectors.
	//! From GLM_GTX_matrix_major_storage extension.
	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x4<T, P> colMajor4(
	    __thread__ tvec4<T, P> const & v1, 
	    __thread__ tvec4<T, P> const & v2, 
	    __thread__ tvec4<T, P> const & v3, 
	    __thread__ tvec4<T, P> const & v4);
				
	//! Build a column major matrix from other matrix.
	//! From GLM_GTX_matrix_major_storage extension.
	template <typename T, precision P> 
	GLM_FUNC_DECL tmat4x4<T, P> colMajor4(
		__thread__ tmat4x4<T, P> const & m);

	/// @}
}//namespace glm

#include "matrix_major_storage.inl"
