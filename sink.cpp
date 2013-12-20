#include "sink.hpp"

//------------------------------------------------------------------
sink::sink(sc_module_name _name) : 
    sc_module(_name),
    sum("sum"),
    carry("carry")
{

  SC_THREAD(printResult);
  sensitive << sum << carry;

  return;
}

//------------------------------------------------------------------
void sink::printResult(){
  
  std::cout << "sink: ready to receive data" << std::endl << std::endl;

  while(1) {
    wait();
    std::cout << sc_time_stamp() << ": Result is:" << sum <<
                 " - " << carry << std::endl;
  }
  
  return;
}
