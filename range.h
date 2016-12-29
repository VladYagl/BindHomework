#ifndef RANGE_H
#define RANGE_H

#include <cstdlib>

template <size_t... Data>
struct template_array {

	template <size_t A>
	struct add {
		typedef template_array<Data..., A> result;
	};
};

template <size_t N>
struct range {
	typedef typename range<N - 1>::result::template add<N - 1>::result result;
};

template <>
struct range<0> {
	typedef template_array<> result;
};

#endif // RANGE_H
