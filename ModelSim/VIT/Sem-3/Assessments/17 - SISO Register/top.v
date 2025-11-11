module siso_register(input clk, input si, output reg so);
  reg [3:0] shift;

  always @(posedge clk)
    begin
      shift[3] <= si;
      shift[2] <= shift[3];
      shift[1] <= shift[2];
      shift[0] <= shift[1];
      so <= shift[0];
    end
endmodule

module tb_siso_register;
  reg clk, si;
  wire so;

  siso_register dut(clk, si, so);

  initial begin
    clk = 0;
    si = 0;
    #5 si = 1;
    #10 si = 0;
    #10 si = 1;
    #10 si = 1;
    #20 $finish;
  end

  always #5 clk = ~clk;
endmodule
