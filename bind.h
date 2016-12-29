#ifndef BIND_H
#define BIND_H

#include "range.h"
#include <tuple>
#include <cstdlib>

template <size_t N>
struct placeholder {};

template <typename T, typename ... Args>
auto convert_argument(T value, Args&& ... args) {
	return value;
}

template <size_t N, typename ... Args>
auto convert_argument(placeholder<N>, Args&& ... args) {
	return std::get<N>(std::forward_as_tuple(args...));
}

template <typename F, typename ... Args>
struct bind_t;

template <typename F, typename ... BindArgs, typename ... Args>
auto convert_arguments(bind_t<F, BindArgs...> bind_func, Args&& ... args) {
	return bind_func(std::forward<BindArgs>(args)...);
}

template <typename F, typename ... BindArgs>
struct bind_t {
	bind_t(F func, BindArgs&& ... args) :
		func(std::move(func)), bind_args(std::forward<BindArgs>(args)...) {}

	template <typename ... Args>
	auto operator()(Args const& ... args) const {
		return call(typename range<sizeof...(BindArgs)>::result(), args...);
	}

private:
	F func;
	std::tuple<BindArgs...> bind_args;

	template <size_t ... Indexes, typename ... Args>
	auto call(template_array<Indexes...>, Args const& ... args) const {
		return func(convert_argument(std::get<Indexes>(bind_args), args...)...);
	}
};

placeholder<0> _1;
placeholder<1> _2;
placeholder<2> _3;
placeholder<3> _4;

template <typename F, typename ... Args>
bind_t<F, Args ...> bind(F func, Args ... args) {
	return bind_t<F, Args ...>(std::move(func), std::move(args) ...);
}

#endif // BIND_H
