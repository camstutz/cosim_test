#pragma once

#include <systemc.h>

class logic : public sc_module {
public:
  // Ports
  sc_in<bool>  val_a;
  sc_in<bool>  val_b;
  sc_out<bool> sum;
  sc_out<bool> carry;
  
  // Constructor
  logic(sc_module_name _n, char* dummy);
  SC_HAS_PROCESS(logic);

private:
  // Processes
  void calculate();

};



