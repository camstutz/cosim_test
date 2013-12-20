#include <systemc.h>
#include <iostream>

#include "TestTop.hpp"

int sc_main(int argc, char* argv[]) {

  TestTop system("Testbench");

  sc_start();

  return 0;
}