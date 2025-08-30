module full_adder(input A, B, Cin, output S, Cout);
  assign S = A ^ B ^ Cin;
  assign Cout = (A & B) | (B & Cin) | (Cin & A);
endmodule

module adder(input [3:0] A, input [3:0] B, input Cin, output [3:0] S, output Cout);
  wire [2:0] C;
  full_adder a1(A[0], B[0], Cin, S[0], C[0]);
  full_adder a2(A[1], B[1], C[0], S[1], C[1]);
  full_adder a3(A[2], B[2], C[1], S[2], C[2]);
  full_adder a4(A[3], B[3], C[2], S[3], Cout);
endmodule


module test();
  reg [3:0] A, B;
  reg Cin;
  wire [3:0] S;
  wire Cout;

  adder uut(A, B, Cin, S, Cout);

  initial begin
    A = 4'b0000; B = 4'b0000; Cin = 1'b0; #10;
    A = 4'b0101; B = 4'b0111; Cin = 1'b0; #10;
    A = 4'b1111; B = 4'b0001; Cin = 1'b1; #10;
    A = 4'b1000; B = 4'b1000; Cin = 1'b0; #10;
    A = 4'b1001; B = 4'b0110; Cin = 1'b1; #10;
    A = 4'b1111; B = 4'b1111; Cin = 1'b1; #10;
    $finish;
  end
endmodule
