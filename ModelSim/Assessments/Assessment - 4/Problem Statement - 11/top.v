module demux(
  input I,
  input [2:0] S,
  output wire [7:0] F
);
  assign F = I << S;
endmodule

module testbench();
  reg  A;
  reg [2:0] B;
  wire [7:0] C;

  demux d(A, B, C);

  initial begin
    A = 1;
    
    B = 3'b000; #100;
    B = 3'b001; #100;
    B = 3'b010; #100;
    B = 3'b011; #100;
    B = 3'b100; #100;
    B = 3'b101; #100;
    B = 3'b110; #100;
    B = 3'b111; #100;
    
    $finish;
  end
endmodule
