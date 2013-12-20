#pragma once

#include <systemc.h>
#include <stdio.h>

class sink : public sc_module {
public:
  // Ports
  sc_in<bool> sum;
  sc_in<bool> carry;
  
  // Constructor
  sink(sc_module_name _n);
  SC_HAS_PROCESS(sink);

private:
  // Processes
  void printResult();
};