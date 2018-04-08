#include "homework_4.h"
#include "print_ip.h"

void homework_4(std::ostream& out)
{
  char char_value = -1;
  short short_value = 0;
  int int_value = 2130706433;
  long long_value = 8875824491850138409;
  std::string string_value = "127.0.0.1.string";
  std::vector<int> vector_value{10,8,0,1};
  std::list<int> list_value{120,48,0,2};
  auto tuple_value = std::make_tuple(99,255,0,3);

  print_ip(out, char_value);
  print_ip(out, short_value);
  print_ip(out, int_value);
  print_ip(out, long_value);
  print_ip(out, string_value);
  print_ip(out, vector_value);
  print_ip(out, list_value);
  print_ip(out, tuple_value);
}
