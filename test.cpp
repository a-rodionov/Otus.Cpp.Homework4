#include "version.h"
#include "homework_4.h"
#include "print_ip.h"
#include <locale>
#include <codecvt>

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
  BOOST_STATIC_ASSERT(true == is_stl_container_v<const std::vector<int>>);
  BOOST_STATIC_ASSERT(true == is_stl_container_v<volatile std::vector<int>>);
  BOOST_STATIC_ASSERT(true == is_stl_container_v<const volatile std::vector<int>>);
  BOOST_STATIC_ASSERT(true == is_stl_container_v<std::list<std::string>>);
  BOOST_STATIC_ASSERT(true == is_stl_container_v<const std::list<std::string>>);
  BOOST_STATIC_ASSERT(true == is_stl_container_v<volatile std::list<std::string>>);
  BOOST_STATIC_ASSERT(true == is_stl_container_v<const volatile std::list<std::string>>);
  BOOST_STATIC_ASSERT(false == is_stl_container_v<std::tuple<int, float>>);
}

BOOST_AUTO_TEST_CASE(test_is_integral_v)
{
  BOOST_STATIC_ASSERT(true == is_integral_v<char>);
  BOOST_STATIC_ASSERT(true == is_integral_v<const char>);
  BOOST_STATIC_ASSERT(true == is_integral_v<volatile char>);
  BOOST_STATIC_ASSERT(true == is_integral_v<const volatile char>);
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
  BOOST_STATIC_ASSERT(true == is_tuple_v<const std::tuple<int, float>>);
  BOOST_STATIC_ASSERT(true == is_tuple_v<volatile std::tuple<int, float>>);
  BOOST_STATIC_ASSERT(true == is_tuple_v<const volatile std::tuple<int, float>>);
}

BOOST_AUTO_TEST_CASE(test_is_all_same_v)
{
  BOOST_STATIC_ASSERT(true == is_all_same_v<>);
  BOOST_STATIC_ASSERT(true == is_all_same_v<int>);
  BOOST_STATIC_ASSERT(true == is_all_same_v<int, int>);
  BOOST_STATIC_ASSERT(false == is_all_same_v<int, const int>);
  BOOST_STATIC_ASSERT(false == is_all_same_v<int, volatile int>);
  BOOST_STATIC_ASSERT(false == is_all_same_v<int, const volatile int>);
  BOOST_STATIC_ASSERT(false == is_all_same_v<int, char>);
  BOOST_STATIC_ASSERT(true == is_all_same_v<int, int, int>);
  BOOST_STATIC_ASSERT(false == is_all_same_v<int, int, char>);
  BOOST_STATIC_ASSERT(true == is_all_same_v<std::vector<int>, std::vector<int>, std::vector<int>>);
  BOOST_STATIC_ASSERT(false == is_all_same_v<std::vector<int>, std::vector<char>, std::vector<int>>);
}

BOOST_AUTO_TEST_CASE(test_is_homogeneous_tuple_v)
{
  BOOST_STATIC_ASSERT(false == is_homogeneous_tuple_v<std::tuple<>>);
  BOOST_STATIC_ASSERT(true == is_homogeneous_tuple_v<std::tuple<int>>);
  BOOST_STATIC_ASSERT(true == is_homogeneous_tuple_v<std::tuple<int, int>>);
  BOOST_STATIC_ASSERT(true == is_homogeneous_tuple_v<const std::tuple<int, int>>);
  BOOST_STATIC_ASSERT(true == is_homogeneous_tuple_v<volatile std::tuple<int, int>>);
  BOOST_STATIC_ASSERT(true == is_homogeneous_tuple_v<const volatile std::tuple<int, int>>);
  BOOST_STATIC_ASSERT(false == is_homogeneous_tuple_v<std::tuple<int, const int>>);
  BOOST_STATIC_ASSERT(false == is_homogeneous_tuple_v<std::tuple<int, volatile int>>);
  BOOST_STATIC_ASSERT(false == is_homogeneous_tuple_v<std::tuple<int, const volatile int>>);
  BOOST_STATIC_ASSERT(false == is_homogeneous_tuple_v<std::tuple<int, char>>);
  BOOST_STATIC_ASSERT(true == is_homogeneous_tuple_v<std::tuple<int, int, int>>);
  BOOST_STATIC_ASSERT(false == is_homogeneous_tuple_v<std::tuple<int, std::string, int>>);
}

BOOST_AUTO_TEST_CASE(test_is_empty_tuple_v)
{
  BOOST_STATIC_ASSERT(true == is_empty_tuple_v<std::tuple<>>);
  BOOST_STATIC_ASSERT(true == is_empty_tuple_v<const std::tuple<>>);
  BOOST_STATIC_ASSERT(true == is_empty_tuple_v<volatile std::tuple<>>);
  BOOST_STATIC_ASSERT(true == is_empty_tuple_v<const volatile std::tuple<>>);
  BOOST_STATIC_ASSERT(false == is_empty_tuple_v<int>);
  BOOST_STATIC_ASSERT(false == is_empty_tuple_v<std::vector<int>>);
  BOOST_STATIC_ASSERT(false == is_empty_tuple_v<std::string>);
  BOOST_STATIC_ASSERT(false == is_empty_tuple_v<std::tuple<int>>);
  BOOST_STATIC_ASSERT(false == is_empty_tuple_v<std::tuple<int, int>>);
}

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(test_suite_print_ip)

BOOST_AUTO_TEST_CASE(test_print_ip_integral)
{
  std::string result{
    "255\n"
    "0.0\n"
    "0.1\n"
    "127.0.0.1\n"
    "123.45.67.89.101.112.131.41\n"
  };
  std::ostringstream oss;

  char char_value{-1};
  short short_value_1{0};
  const short short_value_2{1};
  volatile short short_value_3{2};
  const volatile short short_value_4{3};
  int int_value{2130706433};
  long long_value{8875824491850138409};

  print_ip(oss, char_value);
  print_ip(oss, short_value_1);
  print_ip(oss, short_value_2);
  //print_ip(oss, short_value_3);  // compile error
  //print_ip(oss, short_value_4);  // compile error
  print_ip(oss, int_value);
  print_ip(oss, long_value);

  BOOST_CHECK_EQUAL(oss.str(), result);
}

BOOST_AUTO_TEST_CASE(test_print_ip_string)
{
  std::string result{
    "127.0.0.1.string\n"
    "127.0.0.1.const_string\n"
  };
  std::ostringstream oss;

  std::string string_value_1{"127.0.0.1.string"};
  const std::string string_value_2{"127.0.0.1.const_string"};
  volatile std::string string_value_3{"127.0.0.1.volatile_string"};
  const volatile std::string string_value_4{"127.0.0.1.const_volatile_string"};

  print_ip(oss, string_value_1);
  print_ip(oss, string_value_2);
  //print_ip(oss, string_value_3);  // compile error
  //print_ip(oss, string_value_4);  // compile error

  BOOST_CHECK_EQUAL(oss.str(), result);
}

BOOST_AUTO_TEST_CASE(test_print_ip_wstring)
{
  std::string result{
    "127.0.0.1.wstring\n"
    "127.0.0.1.const_wstring\n"
  };
  std::wostringstream woss;
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cv;

  std::wstring wstring_value_1{L"127.0.0.1.wstring"};
  const std::wstring wstring_value_2{L"127.0.0.1.const_wstring"};
  volatile std::wstring wstring_value_3{L"127.0.0.1.volatile_wstring"};
  const volatile std::wstring wstring_value_4{L"127.0.0.1.const_volatile_wstring"};

  print_ip(woss, wstring_value_1);
  print_ip(woss, wstring_value_2);
  //print_ip(woss, wstring_value_3);  // compile error
  //print_ip(woss, wstring_value_4);  // compile error

  BOOST_CHECK_EQUAL(cv.to_bytes(woss.str()), result);
}

BOOST_AUTO_TEST_CASE(test_print_ip_vector)
{
  std::string result{
    "1.2\n"
    "10.20.30.40\n"
    "100.200.300.400.500.600\n"
    "-101.202.-303.404.-505\n"
    "0.1.2.3.4.5.6.7.8.9.1\n"
    "some.strange.ip.address\n"
    "11.22.33.44\n"
    //"44.55.66.77\n"
    //"77.88.99\n"
  };
  std::ostringstream oss;

  std::vector<int> vector_value_1{};
  std::vector<int> vector_value_2{1, 2};
  std::vector<int> vector_value_3{10, 20, 30, 40};
  std::vector<int> vector_value_4{100, 200, 300, 400, 500, 600};
  std::vector<int> vector_value_5{-101, 202, -303, 404, -505};
  std::vector<float> vector_value_6{0.1, 2.3, 4.5, 6.7, 8.9, 1.0};
  std::vector<std::string> vector_value_7{"some", "strange", "ip", "address"};
  const std::vector<int> vector_value_8{11, 22, 33, 44};
  volatile std::vector<int> vector_value_9{44, 55, 66, 77};
  const volatile std::vector<int> vector_value_10{77, 88, 99};

  print_ip(oss, vector_value_1);
  print_ip(oss, vector_value_2);
  print_ip(oss, vector_value_3);
  print_ip(oss, vector_value_4);
  print_ip(oss, vector_value_5);
  print_ip(oss, vector_value_6);
  print_ip(oss, vector_value_7);
  print_ip(oss, vector_value_8);
  //print_ip(oss, vector_value_9);  // compile error
  //print_ip(oss, vector_value_10); // compile error

  BOOST_CHECK_EQUAL(oss.str(), result);
}

BOOST_AUTO_TEST_CASE(test_print_ip_list)
{
  std::string result{
    "1.2\n"
    "10.20.30.40\n"
    "100.200.300.400.500.600\n"
    "-101.202.-303.404.-505\n"
    "0.1.2.3.4.5.6.7.8.9.1\n"
    "some.strange.ip.address\n"
    "11.22.33.44\n"
    //"44.55.66.77\n"
    //"77.88.99\n"
  };
  std::ostringstream oss;

  std::list<int> list_value_1{};
  std::list<int> list_value_2{1, 2};
  std::list<int> list_value_3{10, 20, 30, 40};
  std::list<int> list_value_4{100, 200, 300, 400, 500, 600};
  std::list<int> list_value_5{-101, 202, -303, 404, -505};
  std::list<float> list_value_6{0.1, 2.3, 4.5, 6.7, 8.9, 1.0};
  std::list<std::string> list_value_7{"some", "strange", "ip", "address"};
  const std::list<int> list_value_8{11, 22, 33, 44};
  volatile std::list<int> list_value_9{44, 55, 66, 77};
  const volatile std::list<int> list_value_10{77, 88, 99};

  print_ip(oss, list_value_1);
  print_ip(oss, list_value_2);
  print_ip(oss, list_value_3);
  print_ip(oss, list_value_4);
  print_ip(oss, list_value_5);
  print_ip(oss, list_value_6);
  print_ip(oss, list_value_7);
  print_ip(oss, list_value_8);
  //print_ip(oss, list_value_9);  // compile error
  //print_ip(oss, list_value_10); // compile error

  BOOST_CHECK_EQUAL(oss.str(), result);
}

BOOST_AUTO_TEST_CASE(test_print_ip_tuple)
{
  std::string result{
    "99.255.0.3\n"
    "99.255.333.3.4\n"
  };
  std::ostringstream oss;

  auto tuple_value_1 = std::make_tuple();
  auto tuple_value_2 = std::make_tuple(99, 255, 0, 3);
  const auto tuple_value_3 = std::make_tuple(99, 255, 333, 3, 4);
  volatile auto tuple_value_4 = std::make_tuple(99, 255, 0, 3, 5);
  const volatile auto tuple_value_5 = std::make_tuple(99, 255, 0, 3, 6);
  auto tuple_value_6 = std::make_tuple(99, 255, 0, "3");

  print_ip(oss, tuple_value_1);
  print_ip(oss, tuple_value_2);
  print_ip(oss, tuple_value_3);
  //print_ip(oss, tuple_value_4);  // compile error
  //print_ip(oss, tuple_value_5);  // compile error
  //print_ip(oss, tuple_value_6);  // compile error

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
