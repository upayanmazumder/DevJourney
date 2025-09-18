module mux(input [7:0]I, input [0:2]S, output reg F);
  always @(S)
  begin
    case(S)
      3'b000 : F = I[0];
      3'b001 : F = I[0];
      3'b010 : F = I[0];
      3'b011 : F = I[0];
      3'b100 : F = I[0];
      3'b101 : F = I[0];
      3'b110 : F = I[0];
      3'b111 : F = I[0];
    endcase
  end
endmodule

module testbench();
  reg [7:0]I;
  reg [0:2]S;
  wire F;
  mux m(I, S, F);
  initial
    begin
      I = 8'b00000000; S = 3'b001; #100
      I = 8'b11111111; S = 3'b111; #100
      I = 8'b01000010; S = 3'b101; #100
      I = 8'b10101010; S = 3'b111; #100
    $finish;
  end
endmodule 