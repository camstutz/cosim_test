#pragma once

#include <systemc.h>

#include "source.hpp"
#include "sink.hpp"
#include "logic.hpp"

class TestTop : public sc_module {
public:

private:
  // Modules
  source src;
  sink   snk;
  logic  log;

  // Channels
  sc_signal<bool> sigValA, sigValB;
  sc_signal<bool> sigSum, sigCarry;

public:
  // Constructor
  TestTop(sc_module_name _name);
};

