/// @ref core
/// @file glm/detail/func_integer.inl

#include "type_vec2.hpp"
#include "type_vec3.hpp"
#include "type_vec4.hpp"
#include "type_int.hpp"
#include "_vectorize.hpp"

#if(GLM_ARCH & GLM_ARCH_X86 && GLM_COMPILER & GLM_COMPILER_VC)
#	include <intrin.h>
#	pragma intrinsic(_BitScanReverse)
#endif//(GLM_ARCH & GLM_ARCH_X86 && GLM_COMPILER & GLM_COMPILER_VC)

#if !__METAL_VERSION__
#   include <limits>
#endif // __METAL_VERSION__

#if !GLM_HAS_EXTENDED_INTEGER_TYPE
#	if GLM_COMPILER & GLM_COMPILER_GCC
#		pragma GCC diagnostic ignored "-Wlong-long"
#	endif
#	if (GLM_COMPILER & GLM_COMPILER_CLANG)
#		pragma clang diagnostic ignored "-Wc++11-long-long"
#	endif
#endif

namespace glm{
namespace detail
{
	template <typename T>
	GLM_FUNC_QUALIFIER T mask(T Bits)
	{
		return Bits >= sizeof(T) * 8 ? ~static_cast<T>(0) : (static_cast<T>(1) << Bits) - static_cast<T>(1);
	}

	template <typename T, glm::precision P, template <typename, glm::precision> class vecType, bool Aligned, bool EXEC>
	struct compute_bitfieldReverseStep
	{
		GLM_FUNC_QUALIFIER static vecType<T, P> call(__thread__ vecType<T, P> const & v, T, T)
		{
			return v;
		}
	};

	template <typename T, glm::precision P, template <typename, glm::precision> class vecType, bool Aligned>
	struct compute_bitfieldReverseStep<T, P, vecType, Aligned, true>
	{
		GLM_FUNC_QUALIFIER static vecType<T, P> call(__thread__ vecType<T, P> const & v, T Mask, T Shift)
		{
			return (v & Mask) << Shift | (v & (~Mask)) >> Shift;
		}
	};

	template <typename T, glm::precision P, template <typename, glm::precision> class vecType, bool Aligned, bool EXEC>
	struct compute_bitfieldBitCountStep
	{
		GLM_FUNC_QUALIFIER static vecType<T, P> call(__thread__ vecType<T, P> const & v, T, T)
		{
			return v;
		}
	};

	template <typename T, glm::precision P, template <typename, glm::precision> class vecType, bool Aligned>
	struct compute_bitfieldBitCountStep<T, P, vecType, Aligned, true>
	{
		GLM_FUNC_QUALIFIER static vecType<T, P> call(__thread__ vecType<T, P> const & v, T Mask, T Shift)
		{
			return (v & Mask) + ((v >> Shift) & Mask);
		}
	};

	template <typename genIUType, size_t Bits>
	struct compute_findLSB
	{
		GLM_FUNC_QUALIFIER static int call(genIUType Value)
		{
			if(Value == 0)
				return -1;

			return glm::bitCount(~Value & (Value - static_cast<genIUType>(1)));
		}
	};

#	if GLM_HAS_BITSCAN_WINDOWS
		template <typename genIUType>
		struct compute_findLSB<genIUType, 32>
		{
			GLM_FUNC_QUALIFIER static int call(genIUType Value)
			{
				unsigned long Result(0);
				unsigned char IsNotNull = _BitScanForward(&Result, *reinterpret_cast<unsigned long*>(&Value));
				return IsNotNull ? int(Result) : -1;
			}
		};

#		if !((GLM_COMPILER & GLM_COMPILER_VC) && (GLM_MODEL == GLM_MODEL_32))
		template <typename genIUType>
		struct compute_findLSB<genIUType, 64>
		{
			GLM_FUNC_QUALIFIER static int call(genIUType Value)
			{
				unsigned long Result(0);
				unsigned char IsNotNull = _BitScanForward64(&Result, *reinterpret_cast<unsigned __int64*>(&Value));
				return IsNotNull ? int(Result) : -1;
			}
		};
#		endif
#	endif//GLM_HAS_BITSCAN_WINDOWS

	template <typename T, glm::precision P, template <class, glm::precision> class vecType, bool EXEC = true>
	struct compute_findMSB_step_vec
	{
		GLM_FUNC_QUALIFIER static vecType<T, P> call(__thread__ vecType<T, P> const & x, T Shift)
		{
			return x | (x >> Shift);
		}
	};

	template <typename T, glm::precision P, template <typename, glm::precision> class vecType>
	struct compute_findMSB_step_vec<T, P, vecType, false>
	{
		GLM_FUNC_QUALIFIER static vecType<T, P> call(__thread__ vecType<T, P> const & x, T)
		{
			return x;
		}
	};

	template <typename T, glm::precision P, template <typename, glm::precision> class vecType, int>
	struct compute_findMSB_vec
	{
		GLM_FUNC_QUALIFIER static vecType<int, P> call(__thread__ vecType<T, P> const & vec)
		{
			vecType<T, P> x(vec);
			x = compute_findMSB_step_vec<T, P, vecType, sizeof(T) * 8 >=  8>::call(x, static_cast<T>( 1));
			x = compute_findMSB_step_vec<T, P, vecType, sizeof(T) * 8 >=  8>::call(x, static_cast<T>( 2));
			x = compute_findMSB_step_vec<T, P, vecType, sizeof(T) * 8 >=  8>::call(x, static_cast<T>( 4));
			x = compute_findMSB_step_vec<T, P, vecType, sizeof(T) * 8 >= 16>::call(x, static_cast<T>( 8));
			x = compute_findMSB_step_vec<T, P, vecType, sizeof(T) * 8 >= 32>::call(x, static_cast<T>(16));
			x = compute_findMSB_step_vec<T, P, vecType, sizeof(T) * 8 >= 64>::call(x, static_cast<T>(32));
			return vecType<int, P>(sizeof(T) * 8 - 1) - glm::bitCount(~x);
		}
	};

#	if GLM_HAS_BITSCAN_WINDOWS
		template <typename genIUType>
		GLM_FUNC_QUALIFIER int compute_findMSB_32(genIUType Value)
		{
			unsigned long Result(0);
			unsigned char IsNotNull = _BitScanReverse(&Result, *reinterpret_cast<unsigned long*>(&Value));
			return IsNotNull ? int(Result) : -1;
		}

		template <typename T, glm::precision P, template<typename, glm::precision> class vecType>
		struct compute_findMSB_vec<T, P, vecType, 32>
		{
			GLM_FUNC_QUALIFIER static vecType<int, P> call(__thread__ vecType<T, P> const & x)
			{
				return detail::functor1<int, T, P, vecType>::call(compute_findMSB_32, x);
			}
		};

#		if !((GLM_COMPILER & GLM_COMPILER_VC) && (GLM_MODEL == GLM_MODEL_32))
		template <typename genIUType>
		GLM_FUNC_QUALIFIER int compute_findMSB_64(genIUType Value)
		{
			unsigned long Result(0);
			unsigned char IsNotNull = _BitScanReverse64(&Result, *reinterpret_cast<unsigned __int64*>(&Value));
			return IsNotNull ? int(Result) : -1;
		}

		template <typename T, glm::precision P, template <class, glm::precision> class vecType>
		struct compute_findMSB_vec<T, P, vecType, 64>
		{
			GLM_FUNC_QUALIFIER static vecType<int, P> call(__thread__ vecType<T, P> const & x)
			{
				return detail::functor1<int, T, P, vecType>::call(compute_findMSB_64, x);
			}
		};
#		endif
#	endif//GLM_HAS_BITSCAN_WINDOWS
}//namespace detail

	// uaddCarry
	GLM_FUNC_QUALIFIER uint uaddCarry(__thread__ uint const & x, __thread__ uint const & y, __thread__ uint & Carry)
	{
		uint64 const Value64(static_cast<uint64>(x) + static_cast<uint64>(y));
		uint64 const Max32((static_cast<uint64>(1) << static_cast<uint64>(32)) - static_cast<uint64>(1));
		Carry = Value64 > Max32 ? 1u : 0u;
		return static_cast<uint32>(Value64 % (Max32 + static_cast<uint64>(1)));
	}

	template <precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<uint, P> uaddCarry(__thread__ vecType<uint, P> const & x, __thread__ vecType<uint, P> const & y, __thread__ vecType<uint, P> & Carry)
	{
		vecType<uint64, P> Value64(vecType<uint64, P>(x) + vecType<uint64, P>(y));
		vecType<uint64, P> Max32((static_cast<uint64>(1) << static_cast<uint64>(32)) - static_cast<uint64>(1));
		Carry = mix(vecType<uint32, P>(0), vecType<uint32, P>(1), greaterThan(Value64, Max32));
		return vecType<uint32,P>(Value64 % (Max32 + static_cast<uint64>(1)));
	}

	// usubBorrow
	GLM_FUNC_QUALIFIER uint usubBorrow(__thread__ uint const & x, __thread__ uint const & y, __thread__ uint & Borrow)
	{
		GLM_STATIC_ASSERT(sizeof(uint) == sizeof(uint32), "uint and uint32 size mismatch");

		Borrow = x >= y ? static_cast<uint32>(0) : static_cast<uint32>(1);
		if(y >= x)
			return y - x;
		else
			return static_cast<uint32>((static_cast<int64>(1) << static_cast<int64>(32)) + (static_cast<int64>(y) - static_cast<int64>(x)));
	}

	template <precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<uint, P> usubBorrow(__thread__ vecType<uint, P> const & x, __thread__ vecType<uint, P> const & y, __thread__ vecType<uint, P> & Borrow)
	{
		Borrow = mix(vecType<uint, P>(1), vecType<uint, P>(0), greaterThanEqual(x, y));
		vecType<uint, P> const YgeX(y - x);
		vecType<uint, P> const XgeY(vecType<uint32, P>((static_cast<int64>(1) << static_cast<int64>(32)) + (vecType<int64, P>(y) - vecType<int64, P>(x))));
		return mix(XgeY, YgeX, greaterThanEqual(y, x));
	}

	// umulExtended
	GLM_FUNC_QUALIFIER void umulExtended(__thread__ uint const & x, __thread__ uint const & y, __thread__ uint & msb, __thread__ uint & lsb)
	{
		GLM_STATIC_ASSERT(sizeof(uint) == sizeof(uint32), "uint and uint32 size mismatch");

		uint64 Value64 = static_cast<uint64>(x) * static_cast<uint64>(y);
		msb = static_cast<uint>(Value64 >> static_cast<uint64>(32));
		lsb = static_cast<uint>(Value64);
	}

	template <precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER void umulExtended(__thread__ vecType<uint, P> const & x, __thread__ vecType<uint, P> const & y, __thread__ vecType<uint, P> & msb, __thread__ vecType<uint, P> & lsb)
	{
		GLM_STATIC_ASSERT(sizeof(uint) == sizeof(uint32), "uint and uint32 size mismatch");

		vecType<uint64, P> Value64(vecType<uint64, P>(x) * vecType<uint64, P>(y));
		msb = vecType<uint32, P>(Value64 >> static_cast<uint64>(32));
		lsb = vecType<uint32, P>(Value64);
	}

	// imulExtended
	GLM_FUNC_QUALIFIER void imulExtended(int x, int y, __thread__ int & msb, __thread__ int & lsb)
	{
		GLM_STATIC_ASSERT(sizeof(int) == sizeof(int32), "int and int32 size mismatch");

		int64 Value64 = static_cast<int64>(x) * static_cast<int64>(y);
		msb = static_cast<int>(Value64 >> static_cast<int64>(32));
		lsb = static_cast<int>(Value64);
	}

	template <precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER void imulExtended(__thread__ vecType<int, P> const & x, __thread__ vecType<int, P> const & y, __thread__ vecType<int, P> & msb, __thread__ vecType<int, P> & lsb)
	{
		GLM_STATIC_ASSERT(sizeof(int) == sizeof(int32), "int and int32 size mismatch");

		vecType<int64, P> Value64(vecType<int64, P>(x) * vecType<int64, P>(y));
		lsb = vecType<int32, P>(Value64 & static_cast<int64>(0xFFFFFFFF));
		msb = vecType<int32, P>((Value64 >> static_cast<int64>(32)) & static_cast<int64>(0xFFFFFFFF));
	}

	// bitfieldExtract
	template <typename genIUType>
	GLM_FUNC_QUALIFIER genIUType bitfieldExtract(genIUType Value, int Offset, int Bits)
	{
		return bitfieldExtract(tvec1<genIUType>(Value), Offset, Bits).x;
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<T, P> bitfieldExtract(__thread__ vecType<T, P> const & Value, int Offset, int Bits)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'bitfieldExtract' only accept integer inputs");

		return (Value >> static_cast<T>(Offset)) & static_cast<T>(detail::mask(Bits));
	}

	// bitfieldInsert
	template <typename genIUType>
	GLM_FUNC_QUALIFIER genIUType bitfieldInsert(__thread__ genIUType const & Base, __thread__ genIUType const & Insert, int Offset, int Bits)
	{
		return bitfieldInsert(tvec1<genIUType>(Base), tvec1<genIUType>(Insert), Offset, Bits).x;
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<T, P> bitfieldInsert(__thread__ vecType<T, P> const & Base, __thread__ vecType<T, P> const & Insert, int Offset, int Bits)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'bitfieldInsert' only accept integer values");

		T const Mask = static_cast<T>(detail::mask(Bits) << Offset);
		return (Base & ~Mask) | (Insert & Mask);
	}

	// bitfieldReverse
	template <typename genType>
	GLM_FUNC_QUALIFIER genType bitfieldReverse(genType x)
	{
		return bitfieldReverse(glm::tvec1<genType, glm::defaultp>(x)).x;
	}

	template <typename T, glm::precision P, template <typename, glm::precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<T, P> bitfieldReverse(__thread__ vecType<T, P> const & v)
	{
		vecType<T, P> x(v);
		x = detail::compute_bitfieldReverseStep<T, P, vecType, detail::is_aligned<P>::value, sizeof(T) * 8>=  2>::call(x, T(0x5555555555555555ull), static_cast<T>( 1));
		x = detail::compute_bitfieldReverseStep<T, P, vecType, detail::is_aligned<P>::value, sizeof(T) * 8>=  4>::call(x, T(0x3333333333333333ull), static_cast<T>( 2));
		x = detail::compute_bitfieldReverseStep<T, P, vecType, detail::is_aligned<P>::value, sizeof(T) * 8>=  8>::call(x, T(0x0F0F0F0F0F0F0F0Full), static_cast<T>( 4));
		x = detail::compute_bitfieldReverseStep<T, P, vecType, detail::is_aligned<P>::value, sizeof(T) * 8>= 16>::call(x, T(0x00FF00FF00FF00FFull), static_cast<T>( 8));
		x = detail::compute_bitfieldReverseStep<T, P, vecType, detail::is_aligned<P>::value, sizeof(T) * 8>= 32>::call(x, T(0x0000FFFF0000FFFFull), static_cast<T>(16));
		x = detail::compute_bitfieldReverseStep<T, P, vecType, detail::is_aligned<P>::value, sizeof(T) * 8>= 64>::call(x, T(0x00000000FFFFFFFFull), static_cast<T>(32));
		return x;
	}

	// bitCount
	template <typename genType>
	GLM_FUNC_QUALIFIER int bitCount(genType x)
	{
		return bitCount(glm::tvec1<genType, glm::defaultp>(x)).x;
	}

	template <typename T, glm::precision P, template <typename, glm::precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<int, P> bitCount(__thread__ vecType<T, P> const & v)
	{
		vecType<typename detail::make_unsigned<T>::type, P> x(*reinterpret_cast<__thread__ vecType<typename detail::make_unsigned<T>::type, P> const *>(&v));
		x = detail::compute_bitfieldBitCountStep<typename detail::make_unsigned<T>::type, P, vecType, detail::is_aligned<P>::value, sizeof(T) * 8>=  2>::call(x, typename detail::make_unsigned<T>::type(0x5555555555555555ull), typename detail::make_unsigned<T>::type( 1));
		x = detail::compute_bitfieldBitCountStep<typename detail::make_unsigned<T>::type, P, vecType, detail::is_aligned<P>::value, sizeof(T) * 8>=  4>::call(x, typename detail::make_unsigned<T>::type(0x3333333333333333ull), typename detail::make_unsigned<T>::type( 2));
		x = detail::compute_bitfieldBitCountStep<typename detail::make_unsigned<T>::type, P, vecType, detail::is_aligned<P>::value, sizeof(T) * 8>=  8>::call(x, typename detail::make_unsigned<T>::type(0x0F0F0F0F0F0F0F0Full), typename detail::make_unsigned<T>::type( 4));
		x = detail::compute_bitfieldBitCountStep<typename detail::make_unsigned<T>::type, P, vecType, detail::is_aligned<P>::value, sizeof(T) * 8>= 16>::call(x, typename detail::make_unsigned<T>::type(0x00FF00FF00FF00FFull), typename detail::make_unsigned<T>::type( 8));
		x = detail::compute_bitfieldBitCountStep<typename detail::make_unsigned<T>::type, P, vecType, detail::is_aligned<P>::value, sizeof(T) * 8>= 32>::call(x, typename detail::make_unsigned<T>::type(0x0000FFFF0000FFFFull), typename detail::make_unsigned<T>::type(16));
		x = detail::compute_bitfieldBitCountStep<typename detail::make_unsigned<T>::type, P, vecType, detail::is_aligned<P>::value, sizeof(T) * 8>= 64>::call(x, typename detail::make_unsigned<T>::type(0x00000000FFFFFFFFull), typename detail::make_unsigned<T>::type(32));
		return vecType<int, P>(x);
	}

	// findLSB
	template <typename genIUType>
	GLM_FUNC_QUALIFIER int findLSB(genIUType Value)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genIUType>::is_integer, "'findLSB' only accept integer values");

		return detail::compute_findLSB<genIUType, sizeof(genIUType) * 8>::call(Value);
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<int, P> findLSB(__thread__ vecType<T, P> const & x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'findLSB' only accept integer values");

		return detail::functor1<int, T, P, vecType>::call(findLSB, x);
	}

	// findMSB
	template <typename genIUType>
	GLM_FUNC_QUALIFIER int findMSB(genIUType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genIUType>::is_integer, "'findMSB' only accept integer values");

		return findMSB(tvec1<genIUType>(x)).x;
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<int, P> findMSB(__thread__ vecType<T, P> const & x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'findMSB' only accept integer values");

		return detail::compute_findMSB_vec<T, P, vecType, sizeof(T) * 8>::call(x);
	}
}//namespace glm

#if GLM_ARCH != GLM_ARCH_PURE && GLM_HAS_UNRESTRICTED_UNIONS
#	include "func_integer_simd.inl"
#endif

