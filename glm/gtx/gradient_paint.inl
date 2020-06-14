/// @ref gtx_gradient_paint
/// @file glm/gtx/gradient_paint.inl

namespace glm
{
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER T radialGradient
	(
		__thread__ tvec2<T, P> const & Center,
		__thread__ T const & Radius,
		__thread__ tvec2<T, P> const & Focal,
		__thread__ tvec2<T, P> const & Position
	)
	{
		tvec2<T, P> F = Focal - Center;
		tvec2<T, P> D = Position - Focal;
		T Radius2 = pow2(Radius);
		T Fx2 = pow2(F.x);
		T Fy2 = pow2(F.y);

		T Numerator = (D.x * F.x + D.y * F.y) + sqrt(Radius2 * (pow2(D.x) + pow2(D.y)) - pow2(D.x * F.y - D.y * F.x));
		T Denominator = Radius2 - (Fx2 + Fy2);
		return Numerator / Denominator;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER T linearGradient
	(
		__thread__ tvec2<T, P> const & Point0,
		__thread__ tvec2<T, P> const & Point1,
		__thread__ tvec2<T, P> const & Position
	)
	{
		tvec2<T, P> Dist = Point1 - Point0;
		return (Dist.x * (Position.x - Point0.x) + Dist.y * (Position.y - Point0.y)) / glm::dot(Dist, Dist);
	}
}//namespace glm
