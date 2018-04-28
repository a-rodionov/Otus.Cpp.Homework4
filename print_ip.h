#pragma once

/*!
  \file print_ip.h
  \brief Определения шаблонных функций печати ip адреса.
*/

#include "user_type_traits.h"
#include "infix_iterator.h"
#include <array>
#include <algorithm>

/*!
  \brief Шаблонная функция печати ip адреса, заданного любым целочисленным типом.
  \param[in,out] out Поток вывода.
  \param[in] ip IP адрес.
*/
template<typename U, typename T, std::enable_if_t<is_integral_v<T>, int> = 0>
auto print_ip(U& out, const T& ip)
{
  const std::array<unsigned char, sizeof(T)>* octets = reinterpret_cast<decltype(octets)>(&ip);
  std::copy(std::crbegin(*octets), std::crend(*octets), infix_ostream_iterator<int>(out, "."));
  out << "\n";
}

/*!
  \brief Шаблонная функция печати ip адреса, заданного контейнером из стандартной библиотеки.
  \param[in,out] out Поток вывода.
  \param[in] ip IP адрес.
*/
template<typename U, typename T, std::enable_if_t<is_stl_container_v<T>, int> = 0>
auto print_ip(U& out, const T& ip)
{
  if(ip.empty())
    return;
  std::copy(std::cbegin(ip), std::cend(ip), infix_ostream_iterator<typename T::value_type>(out, "."));
  out << "\n";
}

/*!
  \brief Шаблонная функция печати кортежа.
  \param[in,out] out Поток вывода.
  \param[in] ip Кортеж для печати.
  \param[in] std::index_sequence<idx...> Тип с последовательностью индексов для кортежа.
*/
template<typename U, typename T, size_t ... idx>
auto print_ip_tuple(U& out, const T& ip, std::index_sequence<idx...>)
{
  ((out << (idx == 0 ? "" : ".") << std::get<idx>(ip)), ...) << "\n";
}

/*!
  \brief Шаблонная функция печати ip адреса, заданного кортежем с одинаковыми типами.
  \param[in,out] out Потока вывода.
  \param[in] ip IP адрес.
*/
template<typename U, typename T, std::enable_if_t<is_homogeneous_tuple_v<T>, int> = 0>
auto print_ip(U& out, const T& ip)
{
  print_ip_tuple(out, ip, std::make_index_sequence<std::tuple_size<T>::value>{});
}

/*!
  \brief Шаблонная функция печати ip адреса, заданного пустым кортежем. Определена для
  устранения ошибк компиляции функции печати ip адреса, заданного кортежем с одинаковыми типами.
  \param[in,out] out Потока вывода.
  \param[in] ip IP адрес.
*/
template<typename U, typename T, std::enable_if_t<is_empty_tuple_v<T>, int> = 0>
auto print_ip(U& out, const T& ip)
{}

/*!
  \brief Шаблонная функция печати ip адреса, не заданного: любым целочисленным типом;
  контейнером из стандартной библиотеки; кортежем с одинаковыми типами.
  \param[in,out] out Поток вывода.
  \param[in] ip IP адрес.
*/
template<typename U, typename T,
        std::enable_if_t<
            !(is_integral_v<T> || is_stl_container_v<T> || is_tuple_v<T>)
            , int> = 0>
auto print_ip(U& out, const T& ip)
{
  out << ip << "\n";
}
