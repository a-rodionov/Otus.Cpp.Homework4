#pragma once

/*!
  \file user_type_traits.h
  \brief Определения метафункций, расширяющих функционал type_traits стандартной библиотеки.
*/

#include <type_traits>
#include <vector>
#include <list>
#include <tuple>

/*!
  \brief Метафункция, определяющая является ли проверяемый тип котейнером из стандартной библиотеки.
*/
template <typename T>
struct is_stl_container : std::false_type{};

template <typename ... Args>
struct is_stl_container<std::vector<Args...>> : std::true_type{};

template <typename ... Args>
struct is_stl_container<std::list<Args...>> : std::true_type{};

/*!
  \brief Шаблонная переменная для более короткой записи получения результата от метафункции is_stl_container.
*/
template <typename T>
constexpr bool is_stl_container_v = is_stl_container<T>::value;



/*!
  \brief Шаблонная переменная для более короткой записи получения результата от метафункции is_integral.
*/
template <typename T>
constexpr bool is_integral_v = std::is_integral<T>::value;



/*!
  \brief Метафункция, определяющая является ли проверяемый тип кортежем.
*/
template <typename T>
struct is_tuple : std::false_type{};

template <typename ... Args>
struct is_tuple<std::tuple<Args...>> : std::true_type{};

/*!
  \brief Шаблонная переменная для более короткой записи получения результата от метафункции is_tuple.
*/
template <typename ... Args>
constexpr bool is_tuple_v = is_tuple<Args...>::value;



/*!
  \brief Метафункция, определяющая является ли все проверяемые типы одинаковыми.
*/
template <typename ... Args>
struct is_all_same : std::true_type{};

template <typename T, typename ... Args>
struct is_all_same<T, T, Args...> : is_all_same<T, Args...>{};

template <typename T, typename U, typename ... Args>
struct is_all_same<T, U, Args...> : std::false_type{};

/*!
  \brief Шаблонная переменная для более короткой записи получения результата от метафункции is_all_same_v.
*/
template <typename ... Args>
constexpr bool is_all_same_v = is_all_same<Args...>::value;



/*!
  \brief Метафункция, определяющая является ли проверяемый тип кортежем с одинаковыми типами.
*/
template <typename T>
struct is_homogeneous_tuple : std::false_type{};

template <typename ... Args>
struct is_homogeneous_tuple<std::tuple<Args...>> : is_all_same<Args...>{};

/*!
  \brief Шаблонная переменная для более короткой записи получения результата от метафункции is_homogeneous_tuple.
*/
template <typename ... Args>
constexpr bool is_homogeneous_tuple_v = is_homogeneous_tuple<Args...>::value;
