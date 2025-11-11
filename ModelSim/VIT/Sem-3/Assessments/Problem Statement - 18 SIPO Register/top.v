module sipo_register(input clk, input si, output reg [3:0] po);
  always @(posedge clk)
    begin
      po[3] <= si;
      po[2] <= po[3];
      po[1] <= po[2];
      po[0] <= po[1];
    end
endmodule

module tb_sipo_register;
  reg clk, si;
  wire [3:0] po;

  sipo_register dut(clk, si, po);

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

