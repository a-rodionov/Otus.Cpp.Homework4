#include "version.h"
#include "homework_4.h"
#include "print_ip.h"

#define BOOST_TEST_MODULE test_main

#include <boost/test/unit_test.hpp>
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_version)

BOOST_AUTO_TEST_CASE(test_version_valid)
{
  BOOST_CHECK( version() > version_info() );
}

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(test_suite_user_type_traits)

BOOST_AUTO_TEST_CASE(test_is_stl_container_v)
{
  BOOST_STATIC_ASSERT(false == is_stl_container_v<char>);
  BOOST_STATIC_ASSERT(false == is_stl_container_v<int>);
  BOOST_STATIC_ASSERT(false == is_stl_container_v<float>);
  BOOST_STATIC_ASSERT(false == is_stl_container_v<std::string>);
  BOOST_STATIC_ASSERT(true == is_stl_container_v<std::vector<int>>);
  BOOST_STATIC_ASSERT(true == is_stl_container_v<std::list<std::string>>);
  BOOST_STATIC_ASSERT(false == is_stl_container_v<std::tuple<int, float>>);
}

BOOST_AUTO_TEST_CASE(test_is_integral_v)
{
  BOOST_STATIC_ASSERT(true == is_integral_v<char>);
  BOOST_STATIC_ASSERT(true == is_integral_v<int>);
  BOOST_STATIC_ASSERT(false == is_integral_v<float>);
  BOOST_STATIC_ASSERT(false == is_integral_v<std::string>);
  BOOST_STATIC_ASSERT(false == is_integral_v<std::vector<int>>);
  BOOST_STATIC_ASSERT(false == is_integral_v<std::list<std::string>>);
  BOOST_STATIC_ASSERT(false == is_integral_v<std::tuple<int, float>>);
}

BOOST_AUTO_TEST_CASE(test_is_tuple_v)
{
  BOOST_STATIC_ASSERT(false == is_tuple_v<char>);
  BOOST_STATIC_ASSERT(false == is_tuple_v<int>);
  BOOST_STATIC_ASSERT(false == is_tuple_v<float>);
  BOOST_STATIC_ASSERT(false == is_tuple_v<std::string>);
  BOOST_STATIC_ASSERT(false == is_tuple_v<std::vector<int>>);
  BOOST_STATIC_ASSERT(false == is_tuple_v<std::list<std::string>>);
  BOOST_STATIC_ASSERT(true == is_tuple_v<std::tuple<>>);
  BOOST_STATIC_ASSERT(true == is_tuple_v<std::tuple<int, int>>);
  BOOST_STATIC_ASSERT(true == is_tuple_v<std::tuple<int, float>>);
}

BOOST_AUTO_TEST_CASE(test_is_all_same_v)
{
  BOOST_STATIC_ASSERT(true == is_all_same_v<>);
  BOOST_STATIC_ASSERT(true == is_all_same_v<int>);
  BOOST_STATIC_ASSERT(true == is_all_same_v<int, int>);
  BOOST_STATIC_ASSERT(false == is_all_same_v<int, char>);
  BOOST_STATIC_ASSERT(true == is_all_same_v<int, int, int>);
  BOOST_STATIC_ASSERT(false == is_all_same_v<int, int, char>);
  BOOST_STATIC_ASSERT(true == is_all_same_v<std::vector<int>, std::vector<int>, std::vector<int>>);
  BOOST_STATIC_ASSERT(false == is_all_same_v<std::vector<int>, std::vector<char>, std::vector<int>>);
}

BOOST_AUTO_TEST_CASE(test_is_homogeneous_tuple_v)
{
  BOOST_STATIC_ASSERT(true == is_homogeneous_tuple_v<std::tuple<>>);
  BOOST_STATIC_ASSERT(true == is_homogeneous_tuple_v<std::tuple<int>>);
  BOOST_STATIC_ASSERT(true == is_homogeneous_tuple_v<std::tuple<int, int>>);
  BOOST_STATIC_ASSERT(false == is_homogeneous_tuple_v<std::tuple<int, char>>);
  BOOST_STATIC_ASSERT(true == is_homogeneous_tuple_v<std::tuple<int, int, int>>);
  BOOST_STATIC_ASSERT(false == is_homogeneous_tuple_v<std::tuple<int, std::string, int>>);
}

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(test_suite_print_ip)

BOOST_AUTO_TEST_CASE(test_print_ip_integral)
{
  std::string result{
    "255\n"
    "0.0\n"
    "127.0.0.1\n"
    "123.45.67.89.101.112.131.41\n"
  };
  std::ostringstream oss;

  char char_value = -1;
  short short_value = 0;
  int int_value = 2130706433;
  long long_value = 8875824491850138409;

  print_ip(oss, char_value);
  print_ip(oss, short_value);
  print_ip(oss, int_value);
  print_ip(oss, long_value);

  BOOST_CHECK_EQUAL(oss.str(), result);
}

BOOST_AUTO_TEST_CASE(test_print_ip_string)
{
  std::string result{
    "127.0.0.1.string\n"
  };
  std::ostringstream oss;

  std::string string_value = "127.0.0.1.string";

  print_ip(oss, string_value);

  BOOST_CHECK_EQUAL(oss.str(), result);
}

BOOST_AUTO_TEST_CASE(test_print_ip_stl_container)
{
  std::string result{
    "10.8.0.1\n"
    "120.48.0.2\n"
  };
  std::ostringstream oss;

  std::vector<int> vector_value{10,8,0,1};
  std::list<int> list_value{120,48,0,2};

  print_ip(oss, vector_value);
  print_ip(oss, list_value);

  BOOST_CHECK_EQUAL(oss.str(), result);
}

BOOST_AUTO_TEST_CASE(test_print_ip_tuple)
{
  std::string result{
    "99.255.0.3\n"
  };
  std::ostringstream oss;

  auto tuple_value = std::make_tuple(99, 255,0,3);

  print_ip(oss, tuple_value);

  BOOST_CHECK_EQUAL(oss.str(), result);
}

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(test_suite_homework)

BOOST_AUTO_TEST_CASE(test_homework_4_valid)
{
  std::string result{
    "255\n"
    "0.0\n"
    "127.0.0.1\n"
    "123.45.67.89.101.112.131.41\n"
    "127.0.0.1.string\n"
    "10.8.0.1\n"
    "120.48.0.2\n"
    "99.255.0.3\n"
  };
  std::ostringstream oss;

  homework_4(oss);
  BOOST_CHECK_EQUAL(oss.str(), result);
}

BOOST_AUTO_TEST_SUITE_END()
