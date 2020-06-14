/// @ref gtx_extended_min_max
/// @file glm/gtx/extended_min_max.hpp
///
/// @see core (dependence)
/// @see gtx_half_float (dependence)
///
/// @defgroup gtx_extented_min_max GLM_GTX_extented_min_max
/// @ingroup gtx
///
/// Min and max functions for 3 to 4 parameters.
///
/// <glm/gtx/extented_min_max.hpp> need to be included to use these functionalities.

#pragma once

// Dependency:
#include "../glm.hpp"

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_extented_min_max extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_extented_min_max
	/// @{

	/// Return the minimum component-wise values of 3 inputs 
	/// @see gtx_extented_min_max
	template <typename T>
	GLM_FUNC_DECL T min(
		__thread__ T const & x, 
		__thread__ T const & y, 
		__thread__ T const & z);

	/// Return the minimum component-wise values of 3 inputs
	/// @see gtx_extented_min_max
	template <typename T, template <typename> class C>
	GLM_FUNC_DECL C<T> min(
		__thread__ C<T> const & x,
		__thread__ typename C<T>::T const & y,
		__thread__ typename C<T>::T const & z);

	/// Return the minimum component-wise values of 3 inputs 
	/// @see gtx_extented_min_max
	template <typename T, template <typename> class C>
	GLM_FUNC_DECL C<T> min(
		__thread__ C<T> const & x,
		__thread__ C<T> const & y,
		__thread__ C<T> const & z);

	/// Return the minimum component-wise values of 4 inputs 
	/// @see gtx_extented_min_max
	template <typename T>
	GLM_FUNC_DECL T min(
		__thread__ T const & x, 
		__thread__ T const & y, 
		__thread__ T const & z, 
		__thread__ T const & w);

	/// Return the minimum component-wise values of 4 inputs 
	/// @see gtx_extented_min_max
	template <typename T, template <typename> class C>
	GLM_FUNC_DECL C<T> min(
		__thread__ C<T> const & x,
		__thread__ typename C<T>::T const & y,
		__thread__ typename C<T>::T const & z,
		__thread__ typename C<T>::T const & w);

	/// Return the minimum component-wise values of 4 inputs
	/// @see gtx_extented_min_max
	template <typename T, template <typename> class C>
	GLM_FUNC_DECL C<T> min(
		__thread__ C<T> const & x,
		__thread__ C<T> const & y,
		__thread__ C<T> const & z,
		__thread__ C<T> const & w);

	/// Return the maximum component-wise values of 3 inputs 
	/// @see gtx_extented_min_max
	template <typename T>
	GLM_FUNC_DECL T max(
		__thread__ T const & x, 
		__thread__ T const & y, 
		__thread__ T const & z);

	/// Return the maximum component-wise values of 3 inputs
	/// @see gtx_extented_min_max
	template <typename T, template <typename> class C>
	GLM_FUNC_DECL C<T> max(
		__thread__ C<T> const & x,
		__thread__ typename C<T>::T const & y,
		__thread__ typename C<T>::T const & z);

	/// Return the maximum component-wise values of 3 inputs 
	/// @see gtx_extented_min_max
	template <typename T, template <typename> class C>
	GLM_FUNC_DECL C<T> max(
		__thread__ C<T> const & x,
		__thread__ C<T> const & y,
		__thread__ C<T> const & z);

	/// Return the maximum component-wise values of 4 inputs
	/// @see gtx_extented_min_max
	template <typename T>
	GLM_FUNC_DECL T max(
		__thread__ T const & x, 
		__thread__ T const & y, 
		__thread__ T const & z, 
		__thread__ T const & w);

	/// Return the maximum component-wise values of 4 inputs 
	/// @see gtx_extented_min_max
	template <typename T, template <typename> class C>
	GLM_FUNC_DECL C<T> max(
		__thread__ C<T> const & x,
		__thread__ typename C<T>::T const & y, 
		__thread__ typename C<T>::T const & z, 
		__thread__ typename C<T>::T const & w);

	/// Return the maximum component-wise values of 4 inputs 
	/// @see gtx_extented_min_max
	template <typename T, template <typename> class C>
	GLM_FUNC_DECL C<T> max(
		__thread__ C<T> const & x,
		__thread__ C<T> const & y,
		__thread__ C<T> const & z,
		__thread__ C<T> const & w);

	/// @}
}//namespace glm

#include "extended_min_max.inl"
