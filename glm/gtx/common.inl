/// @ref gtx_common
/// @file glm/gtx/common.inl

#include <cmath>

namespace glm{
namespace detail
{
	template <typename T, precision P, template <class, precision> class vecType, bool isFloat = true>
	struct compute_fmod
	{
		GLM_FUNC_QUALIFIER static vecType<T, P> call(__thread__ vecType<T, P> const & a, __thread__ vecType<T, P> const & b)
		{
			return detail::functor2<T, P, vecType>::call(std::fmod, a, b);
		}
	};

	template <typename T, precision P, template <class, precision> class vecType>
	struct compute_fmod<T, P, vecType, false>
	{
		GLM_FUNC_QUALIFIER static vecType<T, P> call(__thread__ vecType<T, P> const & a, __thread__ vecType<T, P> const & b)
		{
			return a % b;
		}
	};
}//namespace detail

	template <typename T> 
	GLM_FUNC_QUALIFIER bool isdenormal(__thread__ T const & x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isdenormal' only accept floating-point inputs");

#		if GLM_HAS_CXX11_STL
			return std::fpclassify(x) == FP_SUBNORMAL;
#		else
			return x != static_cast<T>(0) && std::fabs(x) < std::numeric_limits<T>::min();
#		endif
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER typename tvec1<T, P>::bool_type isdenormal
	(
		tvec1<T, P> const & x
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isdenormal' only accept floating-point inputs");

		return typename tvec1<T, P>::bool_type(
			isdenormal(x.x));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER typename tvec2<T, P>::bool_type isdenormal
	(
	    __thread__ tvec2<T, P> const & x
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isdenormal' only accept floating-point inputs");

		return typename tvec2<T, P>::bool_type(
			isdenormal(x.x),
			isdenormal(x.y));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER typename tvec3<T, P>::bool_type isdenormal
	(
		__thread__ tvec3<T, P> const & x
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isdenormal' only accept floating-point inputs");

		return typename tvec3<T, P>::bool_type(
			isdenormal(x.x),
			isdenormal(x.y),
			isdenormal(x.z));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER typename tvec4<T, P>::bool_type isdenormal
	(
	    __thread__ tvec4<T, P> const & x
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isdenormal' only accept floating-point inputs");

		return typename tvec4<T, P>::bool_type(
			isdenormal(x.x),
			isdenormal(x.y),
			isdenormal(x.z),
			isdenormal(x.w));
	}

	// fmod
	template <typename genType>
	GLM_FUNC_QUALIFIER genType fmod(genType x, genType y)
	{
		return fmod(tvec1<genType>(x), y).x;
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<T, P> fmod(__thread__ vecType<T, P> const & x, T y)
	{
		return detail::compute_fmod<T, P, vecType, std::numeric_limits<T>::is_iec559>::call(x, vecType<T, P>(y));
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<T, P> fmod(__thread__ vecType<T, P> const & x, __thread__ vecType<T, P> const & y)
	{
		return detail::compute_fmod<T, P, vecType, std::numeric_limits<T>::is_iec559>::call(x, y);
	}
}//namespace glm
