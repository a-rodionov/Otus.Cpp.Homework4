cmake_minimum_required(VERSION 3.2)

# Определение PATCH_VERSION для локальной сборки и сборки на travis
set(PATCH_VERSION 1)
if($ENV{TRAVIS_BUILD_NUMBER})
  set(PATCH_VERSION $ENV{TRAVIS_BUILD_NUMBER})
endif()

project(homework4 VERSION 1.0.${PATCH_VERSION})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version_numbers.h.in version_numbers.h)

# Создание целей
add_executable(print_ip main.cpp)

add_library(print_ip_lib STATIC version.cpp homework_4.cpp)

add_executable(print_ip_test test.cpp)

# Настройка целей

# для всех целей
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wpedantic -Wall -Wextra)

target_link_libraries(print_ip print_ip_lib)

target_compile_definitions(print_ip_test PRIVATE BOOST_TEST_DYN_LINK)
target_link_libraries(print_ip_test 
  Boost::unit_test_framework
  print_ip_lib
)

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT camelot58@gmail.com)

include (CPack)

enable_testing()

add_test(test_suite_version print_ip_test)
add_test(test_suite_user_type_traits print_ip_test)
add_test(test_suite_print_ip print_ip_test)
add_test(test_suite_homework print_ip_test)
