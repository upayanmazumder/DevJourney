library verilog;
use verilog.vl_types.all;
entity half_subtractor is
    port(
        a               : in     vl_logic;
        b               : in     vl_logic;
        diff            : out    vl_logic;
        borr            : out    vl_logic
    );
end half_subtractor;
