/// @ref gtx_extended_min_max
/// @file glm/gtx/extended_min_max.inl

namespace glm
{
	template <typename T>
	GLM_FUNC_QUALIFIER T min(
		__thread__ T const & x, 
		__thread__ T const & y, 
		__thread__ T const & z)
	{
		return glm::min(glm::min(x, y), z);
	}

	template <typename T, template <typename> class C>
	GLM_FUNC_QUALIFIER C<T> min
	(
		__thread__ C<T> const & x,
		__thread__ typename C<T>::T const & y,
		__thread__ typename C<T>::T const & z
	)
	{
		return glm::min(glm::min(x, y), z);
	}

	template <typename T, template <typename> class C>
	GLM_FUNC_QUALIFIER C<T> min
	(
		__thread__ C<T> const & x,
		__thread__ C<T> const & y,
		__thread__ C<T> const & z
	)
	{
		return glm::min(glm::min(x, y), z);
	}

	template <typename T>
	GLM_FUNC_QUALIFIER T min
	(
		__thread__ T const & x, 
		__thread__ T const & y, 
		__thread__ T const & z, 
		__thread__ T const & w
	)
	{
		return glm::min(glm::min(x, y), glm::min(z, w));
	}

	template <typename T, template <typename> class C>
	GLM_FUNC_QUALIFIER C<T> min
	(
		__thread__ C<T> const & x,
		__thread__ typename C<T>::T const & y,
		__thread__ typename C<T>::T const & z,
		__thread__ typename C<T>::T const & w
	)
	{
		return glm::min(glm::min(x, y), glm::min(z, w));
	}

	template <typename T, template <typename> class C>
	GLM_FUNC_QUALIFIER C<T> min
	(
		__thread__ C<T> const & x,
		__thread__ C<T> const & y,
		__thread__ C<T> const & z,
		__thread__ C<T> const & w
	)
	{
		return glm::min(glm::min(x, y), glm::min(z, w));
	}

	template <typename T>
	GLM_FUNC_QUALIFIER T max(
		__thread__ T const & x, 
		__thread__ T const & y, 
		__thread__ T const & z)
	{
		return glm::max(glm::max(x, y), z);
	}

	template <typename T, template <typename> class C>
	GLM_FUNC_QUALIFIER C<T> max
	(
		__thread__ C<T> const & x,
		__thread__ typename C<T>::T const & y,
		__thread__ typename C<T>::T const & z
	)
	{
		return glm::max(glm::max(x, y), z);
	}

	template <typename T, template <typename> class C>
	GLM_FUNC_QUALIFIER C<T> max
	(
		__thread__ C<T> const & x,
		__thread__ C<T> const & y,
		__thread__ C<T> const & z
	)
	{
		return glm::max(glm::max(x, y), z);
	}

	template <typename T>
	GLM_FUNC_QUALIFIER T max
	(
		__thread__ T const & x, 
		__thread__ T const & y, 
		__thread__ T const & z, 
		__thread__ T const & w
	)
	{
		return glm::max(glm::max(x, y), glm::max(z, w));
	}

	template <typename T, template <typename> class C>
	GLM_FUNC_QUALIFIER C<T> max
	(
		__thread__ C<T> const & x,
		__thread__ typename C<T>::T const & y,
		__thread__ typename C<T>::T const & z,
		__thread__ typename C<T>::T const & w
	)
	{
		return glm::max(glm::max(x, y), glm::max(z, w));
	}

	template <typename T, template <typename> class C>
	GLM_FUNC_QUALIFIER C<T> max
	(
		__thread__ C<T> const & x,
		__thread__ C<T> const & y,
		__thread__ C<T> const & z,
		__thread__ C<T> const & w
	)
	{
		return glm::max(glm::max(x, y), glm::max(z, w));
	}

}//namespace glm
