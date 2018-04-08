#include "homework_4.h"

int main(int argc, char const *argv[])
{
  try
  {
    homework_4(std::cout);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}