#pragma once

#include <type_traits>
#include <vector>
#include <list>
#include <tuple>

template <typename T>
struct is_stl_container : std::false_type{};

template <typename ... Args>
struct is_stl_container<std::vector<Args...>> : std::true_type{};

template <typename ... Args>
struct is_stl_container<std::list<Args...>> : std::true_type{};

template <typename T>
constexpr bool is_stl_container_v = is_stl_container<T>::value;



template <typename T>
constexpr bool is_integral_v = std::is_integral<T>::value;



template <typename T>
struct is_tuple : std::false_type{};

template <typename ... Args>
struct is_tuple<std::tuple<Args...>> : std::true_type{};

template <typename ... Args>
constexpr bool is_tuple_v = is_tuple<Args...>::value;



template <typename ... Args>
struct is_all_same : std::true_type{};

template <typename T, typename ... Args>
struct is_all_same<T, T, Args...> : is_all_same<T, Args...>{};

template <typename T, typename U, typename ... Args>
struct is_all_same<T, U, Args...> : std::false_type{};

template <typename ... Args>
constexpr bool is_all_same_v = is_all_same<Args...>::value;



template <typename T>
struct is_homogeneous_tuple : std::false_type{};

template <typename ... Args>
struct is_homogeneous_tuple<std::tuple<Args...>> : is_all_same<Args...>{};

template <typename ... Args>
constexpr bool is_homogeneous_tuple_v = is_homogeneous_tuple<Args...>::value;
