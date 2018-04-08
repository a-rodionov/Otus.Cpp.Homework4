#pragma once

#include "user_type_traits.h"
#include "infix_iterator.h"
#include <array>
#include <algorithm>

template<typename T, std::enable_if_t<is_integral_v<T>, int> = 0>
auto print_ip(std::ostream& out, const T& ip)
{
  const std::array<unsigned char, sizeof(T)>* octets = reinterpret_cast<decltype(octets)>(&ip);
  std::copy(octets->crbegin(), octets->crend(), infix_ostream_iterator<int>(out, "."));
  out << "\n";
}

template<typename T, std::enable_if_t<is_stl_container_v<T>, int> = 0>
auto print_ip(std::ostream& out, const T& ip)
{
	std::copy(ip.cbegin(), ip.cend(), infix_ostream_iterator<typename T::value_type>(out, "."));
	out << "\n";
}

template<typename T, size_t ... idx>
auto print_ip_tuple(std::ostream& out, const T& ip, std::index_sequence<idx...>)
{
  ((out << (idx == 0 ? "" : ".") << std::get<idx>(ip)), ...) << "\n";
}

template<typename T, std::enable_if_t<is_homogeneous_tuple_v<T>, int> = 0>
auto print_ip(std::ostream& out, const T& ip)
{
  print_ip_tuple(out, ip, std::make_index_sequence<std::tuple_size<T>::value>{});
}

template<typename T,
        std::enable_if_t<
            !(is_integral_v<T> || is_stl_container_v<T> || is_homogeneous_tuple_v<T>)
            , int> = 0>
auto print_ip(std::ostream& out, const T& ip)
{
  out << ip << "\n";
}
