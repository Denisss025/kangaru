#pragma once

namespace kgr {

namespace detail {

template <typename... Types>
struct TypesList;

template <typename T, typename... Tail>
struct TypesList<T, Tail...> {
	using type = T;
	using tail_t = TypesList<Tail...>;

	static constexpr auto size = sizeof...(Tail);
};

template <> struct TypesList<> {};

template <unsigned n, typename List>
struct TypeElement {
	using type = typename TypeElement<n-1, typename List::tail_t>::type;
};

template <typename List>
struct TypeElement<0, List> {
	using type = typename List::type;
};

template <unsigned index, typename List>
using TypeElement_t = typename TypeElement<index, List>::type;

}  // namespace detail
}  // namespace kgr

