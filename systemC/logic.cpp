#include "logic.hpp"

//------------------------------------------------------------------
logic::logic(sc_module_name _name, char* dummy) : 
    sc_module(_name),
    val_a("val_a"),
    val_b("val_b"),
    sum("sum"),
    carry("carry")
{

  SC_THREAD(calculate);
  sensitive << val_a << val_b;

  return;
}

//------------------------------------------------------------------
void logic::calculate(){
  
  while(1) {
    wait();
    sum.write(val_a.read() ^ val_b.read());
    carry.write(val_a.read() & val_b.read());
  }
  
  return;
}
