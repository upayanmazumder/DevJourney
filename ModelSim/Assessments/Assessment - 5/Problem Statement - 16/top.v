module t_flip_flop(input clk, input t, output reg q);
  always @(posedge clk)
    if (t)
      q <= ~q;
    else
      q <= q;
endmodule

module tb_t_flip_flop;
  reg clk, t;
  wire q;

  t_flip_flop dut(clk, t, q);

  initial begin
    clk = 0;
    t = 0;
    #5 t = 1;
    #10 t = 0;
    #10 t = 1;
    #20 $finish;
  end

  always #5 clk = ~clk;
endmodule

