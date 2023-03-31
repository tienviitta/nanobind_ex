#include "nanobind_ex/nanobind_ex.hpp"
#include <iostream>

int main(){
  int result = nanobind_ex::add_one(1);
  std::cout << "1 + 1 = " << result << std::endl;
}