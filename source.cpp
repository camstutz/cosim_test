#include "source.hpp"

//------------------------------------------------------------------
source::source(sc_module_name _name) : 
    sc_module(_name),
    val_a("val_a"),
    val_b("val_b")
{
  SC_THREAD(createTestPattern);
  return;
}

//------------------------------------------------------------------
void source::createTestPattern() {

  val_a.write(0);
  val_b.write(0);

  wait(10, SC_NS);
  val_a.write(1);
  val_b.write(0);
  std::cout << sc_time_stamp() << ": Value A: 1, Value B: 0" << std::endl;
  
  wait(10, SC_NS);
  val_a.write(0);
  val_b.write(1);
  std::cout << sc_time_stamp() << ": Value A: 0, Value B: 1" << std::endl;
  
  wait(10, SC_NS);
  val_a.write(1);
  val_b.write(1);
  std::cout << sc_time_stamp() << ": Value A: 1, Value B: 1" << std::endl;
  
  wait(10, SC_NS);
  val_a.write(0);
  val_b.write(0);
  std::cout << sc_time_stamp() << ": Value A: 0, Value B: 0" << std::endl;

  wait(50, SC_NS);  
    
  return;
}
