module full_adder(A, B, Cin, Sum, Cout);
  input A, B, Cin;
  output Sum, Cout;

  assign Sum  = A ^ B ^ Cin;
  assign Cout = (A & B) | (B & Cin) | (A & Cin);
endmodule

module test();
  reg A, B, Cin;
  wire Sum, Cout;

  full_adder U(A, B, Cin, Sum, Cout);

  initial
  begin
    A = 0; B = 0; Cin = 0; #100;
    A = 0; B = 0; Cin = 1; #100;
    A = 0; B = 1; Cin = 0; #100;
    A = 0; B = 1; Cin = 1; #100;
    A = 1; B = 0; Cin = 0; #100;
    A = 1; B = 0; Cin = 1; #100;
    A = 1; B = 1; Cin = 0; #100;
    A = 1; B = 1; Cin = 1; #100;
  end
endmodule
