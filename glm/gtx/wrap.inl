/// @ref gtx_wrap
/// @file glm/gtx/wrap.inl

namespace glm
{
	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<T, P> clamp(__thread__ vecType<T, P> const& Texcoord)
	{
		return glm::clamp(Texcoord, vecType<T, P>(0), vecType<T, P>(1));
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER genType clamp(__thread__ genType const & Texcoord)
	{
		return clamp(tvec1<genType, defaultp>(Texcoord)).x;
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<T, P> repeat(__thread__ vecType<T, P> const& Texcoord)
	{
		return glm::fract(Texcoord);
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER genType repeat(__thread__ genType const & Texcoord)
	{
		return repeat(tvec1<genType, defaultp>(Texcoord)).x;
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<T, P> mirrorClamp(__thread__ vecType<T, P> const& Texcoord)
	{
		return glm::fract(glm::abs(Texcoord));
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER genType mirrorClamp(__thread__ genType const & Texcoord)
	{
		return mirrorClamp(tvec1<genType, defaultp>(Texcoord)).x;
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<T, P> mirrorRepeat(__thread__ vecType<T, P> const& Texcoord)
	{
		vecType<T, P> const Abs = glm::abs(Texcoord);
		vecType<T, P> const Clamp = glm::mod(glm::floor(Abs), vecType<T, P>(2));
		vecType<T, P> const Floor = glm::floor(Abs);
		vecType<T, P> const Rest = Abs - Floor;
		vecType<T, P> const Mirror = Clamp + Rest;
		return mix(Rest, vecType<T, P>(1) - Rest, glm::greaterThanEqual(Mirror, vecType<T, P>(1)));
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER genType mirrorRepeat(__thread__ genType const& Texcoord)
	{
		return mirrorRepeat(tvec1<genType, defaultp>(Texcoord)).x;
	}
}//namespace glm
