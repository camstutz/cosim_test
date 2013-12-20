#include "TestTop.hpp"

//------------------------------------------------------------------
TestTop::TestTop(sc_module_name _name) : 
    sc_module(_name), src("Source"),
    snk("Sink"),
    log("AdderHDL", "work.logic"),
    sigValA("valA"),
    sigValB("valB"),
    sigSum("Sum"),
    sigCarry("Carry")
{

  //logic_INST = new logic("AdderHDL", "work.logic");

  src.val_a(sigValA);
  src.val_b(sigValB);
  
  log.val_a(sigValA);
  log.val_b(sigValB);
  log.sum(sigSum);
  log.carry(sigCarry);
  
  snk.sum(sigSum);
  snk.carry(sigCarry);

  return;
}
