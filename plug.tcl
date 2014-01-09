if { $argc != 2  } {
  echo "Error: The plug.tcl script requires a module name and type of module (systemc/vhdl) to plug in"
  echo "For example, plug.tcl adder vhdl"
} else {
  if { ![string compare $2 "systemc"] } {
    echo "Loading SystemC module"

    file copy -force ./systemC/$1.cpp .
    file copy -force ./systemC/$1.hpp .

    vlib work
    sccom -g $1.cpp

    sccom -g source.cpp
    sccom -g sink.cpp
    sccom -g TestTop.cpp
    sccom -g cosim_test.cpp
    sccom -link
    
    vsim work.sc_main

  } else { if { ![string compare $2 "vhdl"] } {
    echo "Loading VHDL module"
    
    file copy -force ./vhdl/$1.vhdl .

    vlib work
    vcom -93 $1.vhdl
    scgenmod $1 > $1.hpp
    file delete $1.cpp

    sccom -g source.cpp
    sccom -g sink.cpp
    sccom -g TestTop.cpp
    sccom -g cosim_test.cpp
    sccom -link

    vsim work.sc_main

  } else {
      echo "Error: The second argument needs to be either 'systemc' or 'vhdl'"
  } }
}
