module d_ff(input clk, rst, d, output reg q);
  always @(posedge clk or posedge rst) begin
    if (rst)
      q <= 0;   // reset
    else
      q <= d;
  end
endmodule

module jk_ff(input clk, rst, j, k, output reg q);
  always @(posedge clk or posedge rst) begin
    if (rst)
      q <= 0;
    else begin
      case ({j, k})
        2'b00: q <= q;    // no change
        2'b01: q <= 0;    // reset
        2'b10: q <= 1;    // set
        2'b11: q <= ~q;   // toggle  
      endcase
    end
  end
endmodule

module t_ff(input clk, rst, t, output reg q);
  always @(posedge clk or posedge rst) begin
    if (rst)
      q <= 0;     // reset
    else if (t)
      q <= ~q;    // toggle
    else
      q <= q;     //hold
  end
endmodule

module tb_dff;
  reg clk, reset, d;
  wire q;

  d_ff dut(clk, reset, d, q);  // instantiate

  initial begin
    clk = 0;
    forever #5 clk = ~clk;  // 10ns period
  end

  initial begin
    reset = 1; d = 0;
    #10 reset = 0;

    #10 d = 1;
    #10 d = 0;
    #10 d = 1;
    #10 d = 1;
    #10 d = 0;

    #20;
  end
endmodule

module tb_jkff;
  reg clk, reset, j, k;
  wire q;

  jk_ff dut(clk, reset, j, k, q);

  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end

  initial begin
    reset = 1; j = 0; k = 0;
    #10 reset = 0;

    #10 j = 0; k = 0;  // hold
    #10 j = 0; k = 1;  // reset
    #10 j = 1; k = 0;  // set
    #10 j = 1; k = 1;  // toggle
    #10 j = 1; k = 1;  // toggle again

    #20;
  end
endmodule

module tb_tff;
  reg clk, reset, t;
  wire q;

  t_ff dut(clk, reset, t, q);

  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end

  initial begin
    reset = 1; t = 0;
    #10 reset = 0;

    #10 t = 0;  // hold
    #10 t = 1;  // toggle
    #10 t = 1;  // toggle
    #10 t = 0;  // hold
    #10 t = 1;  // toggle

    #20;
  end
endmodule


  
