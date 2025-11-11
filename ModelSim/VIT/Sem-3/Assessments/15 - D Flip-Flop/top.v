module d_flip_flop(input clk, input d, output reg q);
  always @(posedge clk)
    q <= d;
endmodule

module tb_d_flip_flop;
  reg clk, d;
  wire q;

  d_flip_flop dut(clk, d, q);

  initial begin
    clk = 0;
    d = 0;
    #5 d = 1;
    #10 d = 0;
    #10 d = 1;
    #20 $finish;
  end

  always #5 clk = ~clk;
endmodule

