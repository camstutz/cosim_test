#pragma once

#include <systemc.h>

class source : public sc_module {
public:
  // Ports
  sc_out<bool> val_a;
  sc_out<bool> val_b;

  // Constructor
  source(sc_module_name _name);
  SC_HAS_PROCESS(source);

private:
  // Processes
  void createTestPattern();

};
