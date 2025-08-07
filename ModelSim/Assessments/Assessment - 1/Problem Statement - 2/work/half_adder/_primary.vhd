library verilog;
use verilog.vl_types.all;
entity half_adder is
    port(
        a               : in     vl_logic;
        b               : in     vl_logic;
        sum             : out    vl_logic;
        carry           : out    vl_logic
    );
end half_adder;
