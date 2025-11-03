module pipo_register(input clk, input [3:0] pi, output reg [3:0] po);
  always @(posedge clk)
    po <= pi;
endmodule

module tb_pipo_register;
  reg clk;
  reg [3:0] pi;
  wire [3:0] po;

  pipo_register dut(clk, pi, po);

  initial begin
    clk = 0;
    pi = 4'b0000;
    #5 pi = 4'b1010;
    #10 pi = 4'b1100;
    #10 pi = 4'b0111;
    #20 $finish;
  end

  always #5 clk = ~clk;
endmodule
