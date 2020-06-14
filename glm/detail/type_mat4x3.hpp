/// @ref core
/// @file glm/detail/type_mat4x3.hpp

#pragma once

#include "../fwd.hpp"
#include "type_vec3.hpp"
#include "type_vec4.hpp"
#include "type_mat.hpp"

#if !__METAL_VERSION__
#   include <limits>
#   include <cstddef>
#endif // __METAL_VERSION__

namespace glm
{
	template <typename T, precision P = defaultp>
	struct tmat4x3
	{
		typedef tvec3<T, P> col_type;
		typedef tvec4<T, P> row_type;
		typedef tmat4x3<T, P> type;
		typedef tmat3x4<T, P> transpose_type;
		typedef T value_type;

	private:
		col_type value[4];

	public:
		// -- Constructors --

		GLM_FUNC_DECL tmat4x3() GLM_DEFAULT_CTOR;
		GLM_FUNC_DECL tmat4x3(__thread__ tmat4x3<T, P> const & m) GLM_DEFAULT;
		template <precision Q>
		GLM_FUNC_DECL tmat4x3(__thread__ tmat4x3<T, Q> const & m);

		GLM_FUNC_DECL GLM_CONSTEXPR_CTOR explicit tmat4x3(ctor);
		GLM_FUNC_DECL explicit tmat4x3(__thread__ T const & x);
		GLM_FUNC_DECL tmat4x3(
			__thread__ T const & x0, __thread__ T const & y0, __thread__ T const & z0,
			__thread__ T const & x1, __thread__ T const & y1, __thread__ T const & z1,
			__thread__ T const & x2, __thread__ T const & y2, __thread__ T const & z2,
			__thread__ T const & x3, __thread__ T const & y3, __thread__ T const & z3);
		GLM_FUNC_DECL tmat4x3(
			__thread__ col_type const & v0,
			__thread__ col_type const & v1,
			__thread__ col_type const & v2,
			__thread__ col_type const & v3);

		// -- Conversions --

		template <
			typename X1, typename Y1, typename Z1,
			typename X2, typename Y2, typename Z2,
			typename X3, typename Y3, typename Z3,
			typename X4, typename Y4, typename Z4>
		GLM_FUNC_DECL tmat4x3(
			__thread__ X1 const & x1, __thread__ Y1 const & y1, __thread__ Z1 const & z1,
			__thread__ X2 const & x2, __thread__ Y2 const & y2, __thread__ Z2 const & z2,
			__thread__ X3 const & x3, __thread__ Y3 const & y3, __thread__ Z3 const & z3,
			__thread__ X4 const & x4, __thread__ Y4 const & y4, __thread__ Z4 const & z4);

		template <typename V1, typename V2, typename V3, typename V4>
		GLM_FUNC_DECL tmat4x3(
			__thread__ tvec3<V1, P> const & v1,
			__thread__ tvec3<V2, P> const & v2,
			__thread__ tvec3<V3, P> const & v3,
			__thread__ tvec3<V4, P> const & v4);

		// -- Matrix conversions --

		template <typename U, precision Q>
		GLM_FUNC_DECL GLM_EXPLICIT tmat4x3(__thread__ tmat4x3<U, Q> const & m);

		GLM_FUNC_DECL GLM_EXPLICIT tmat4x3(__thread__ tmat2x2<T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT tmat4x3(__thread__ tmat3x3<T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT tmat4x3(__thread__ tmat4x4<T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT tmat4x3(__thread__ tmat2x3<T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT tmat4x3(__thread__ tmat3x2<T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT tmat4x3(__thread__ tmat2x4<T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT tmat4x3(__thread__ tmat4x2<T, P> const & x);
		GLM_FUNC_DECL GLM_EXPLICIT tmat4x3(__thread__ tmat3x4<T, P> const & x);

		// -- Accesses --

		typedef length_t length_type;
		GLM_FUNC_DECL static length_type length(){return 4;}

		GLM_FUNC_DECL __thread__ col_type & operator[](length_type i);
		GLM_FUNC_DECL __thread__ col_type const & operator[](length_type i) const;

		// -- Unary arithmetic operators --

		GLM_FUNC_DECL __thread__ tmat4x3<T, P> & operator=(__thread__ tmat4x3<T, P> const & m) GLM_DEFAULT;

		template <typename U>
		GLM_FUNC_DECL __thread__ tmat4x3<T, P> & operator=(__thread__ tmat4x3<U, P> const & m);
		template <typename U>
		GLM_FUNC_DECL __thread__ tmat4x3<T, P> & operator+=(U s);
		template <typename U>
		GLM_FUNC_DECL __thread__ tmat4x3<T, P> & operator+=(__thread__ tmat4x3<U, P> const & m);
		template <typename U>
		GLM_FUNC_DECL __thread__ tmat4x3<T, P> & operator-=(U s);
		template <typename U>
		GLM_FUNC_DECL __thread__ tmat4x3<T, P> & operator-=(__thread__ tmat4x3<U, P> const & m);
		template <typename U>
		GLM_FUNC_DECL __thread__ tmat4x3<T, P> & operator*=(U s);
		template <typename U>
		GLM_FUNC_DECL __thread__ tmat4x3<T, P> & operator/=(U s);

		// -- Increment and decrement operators --

		GLM_FUNC_DECL __thread__ tmat4x3<T, P> & operator++();
		GLM_FUNC_DECL __thread__ tmat4x3<T, P> & operator--();
		GLM_FUNC_DECL tmat4x3<T, P> operator++(int);
		GLM_FUNC_DECL tmat4x3<T, P> operator--(int);
	};

	// -- Unary operators --

	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x3<T, P> operator+(__thread__ tmat4x3<T, P> const & m);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x3<T, P> operator-(__thread__ tmat4x3<T, P> const & m);

	// -- Binary operators --

	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x3<T, P> operator+(__thread__ tmat4x3<T, P> const & m, __thread__ T const & s);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x3<T, P> operator+(__thread__ tmat4x3<T, P> const & m1, __thread__ tmat4x3<T, P> const & m2);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x3<T, P> operator-(__thread__ tmat4x3<T, P> const & m, __thread__ T const & s);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x3<T, P> operator-(__thread__ tmat4x3<T, P> const & m1, __thread__ tmat4x3<T, P> const & m2);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x3<T, P> operator*(__thread__ tmat4x3<T, P> const & m, __thread__ T const & s);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x3<T, P> operator*(__thread__ T const & s, __thread__ tmat4x3<T, P> const & m);

	template <typename T, precision P>
	GLM_FUNC_DECL typename tmat4x3<T, P>::col_type operator*(__thread__ tmat4x3<T, P> const & m, __thread__ typename tmat4x3<T, P>::row_type const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL typename tmat4x3<T, P>::row_type operator*(__thread__ typename tmat4x3<T, P>::col_type const & v, __thread__ tmat4x3<T, P> const & m);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x3<T, P> operator*(__thread__ tmat4x3<T, P> const & m1, __thread__ tmat2x4<T, P> const & m2);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat3x3<T, P> operator*(__thread__ tmat4x3<T, P> const & m1,	__thread__ tmat3x4<T, P> const & m2);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x3<T, P> operator*(__thread__ tmat4x3<T, P> const & m1, __thread__ tmat4x4<T, P> const & m2);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x3<T, P> operator/(__thread__ tmat4x3<T, P> const & m, __thread__ T const & s);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x3<T, P> operator/(__thread__ T const & s, __thread__ tmat4x3<T, P> const & m);

	// -- Boolean operators --

	template <typename T, precision P>
	GLM_FUNC_DECL bool operator==(__thread__ tmat4x3<T, P> const & m1, __thread__ tmat4x3<T, P> const & m2);

	template <typename T, precision P>
	GLM_FUNC_DECL bool operator!=(__thread__ tmat4x3<T, P> const & m1, __thread__ tmat4x3<T, P> const & m2);
}//namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_mat4x3.inl"
#endif //GLM_EXTERNAL_TEMPLATE
