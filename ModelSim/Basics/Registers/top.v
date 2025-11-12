// =======================================
// SHIFT REGISTERS COLLECTION
// SISO, SIPO, PIPO + Testbenches
// =======================================

// ---------- SISO (Serial In Serial Out) ----------
module siso(input clk, input reset, input din, output qout);
  reg [3:0] shift;

  always @(posedge clk or posedge reset) begin
    if (reset)
      shift <= 4'b0000;
    else
      shift <= {shift[2:0], din};
  end

  assign qout = shift[3];
endmodule


// ---------- SIPO (Serial In Parallel Out) ----------
module sipo(input clk, input reset, input din, output [3:0] q);
  reg [3:0] shift;

  always @(posedge clk or posedge reset) begin
    if (reset)
      shift <= 4'b0000;
    else
      shift <= {shift[2:0], din};
  end

  assign q = shift;
endmodule


// ---------- PIPO (Parallel In Parallel Out) ----------
module pipo(input clk, input reset, input [3:0] din, output reg [3:0] q);
  always @(posedge clk or posedge reset) begin
    if (reset)
      q <= 4'b0000;
    else
      q <= din;
  end
endmodule


// =======================================
// TESTBENCH SECTION
// =======================================

// ---------- TB for SISO ----------
module tb_siso;
  reg clk, reset, din;
  wire qout;

  siso dut(clk, reset, din, qout);

  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end

  initial begin
    reset = 1; din = 0;
    #10 reset = 0;

    #10 din = 1;
    #10 din = 0;
    #10 din = 1;
    #10 din = 1;
    #10 din = 0;

    #20;
  end
endmodule


// ---------- TB for SIPO ----------
module tb_sipo;
  reg clk, reset, din;
  wire [3:0] q;

  sipo dut(clk, reset, din, q);

  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end

  initial begin
    reset = 1; din = 0;
    #10 reset = 0;

    #10 din = 1;
    #10 din = 0;
    #10 din = 1;
    #10 din = 1;
    #10 din = 0;

    #20;
  end
endmodule


// ---------- TB for PIPO ----------
module tb_pipo;
  reg clk, reset;
  reg [3:0] din;
  wire [3:0] q;

  pipo dut(clk, reset, din, q);

  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end

  initial begin
    reset = 1; din = 4'b0000;
    #10 reset = 0;

    #10 din = 4'b1010;
    #10 din = 4'b1111;
    #10 din = 4'b0101;
    #10 din = 4'b0011;

    #20;
  end
endmodule
