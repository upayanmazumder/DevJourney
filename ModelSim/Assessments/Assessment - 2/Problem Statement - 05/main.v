module half_adder(input a, b, output s, c);
  assign s = a ^ b;
  assign c = a & b;
endmodule

module full_adder(input a, b, cin, output sum, cout);
  wire s1, c1, c2;
  half_adder ha1(.a(a), .b(b), .s(s1), .c(c1));
  half_adder ha2(.a(s1), .b(cin), .s(sum), .c(c2));
  assign cout = c1 | c2;
endmodule

module full_adder_tb;
  reg a, b, cin;
  wire sum, cout;
  full_adder dut(.a(a), .b(b), .cin(cin), .sum(sum), .cout(cout));
  initial
  begin
    a = 0; b = 0; cin = 0;
    # 10
    a = 0; b = 0; cin = 1;
    # 10
    a = 0; b = 1; cin = 0;
    # 10
    a = 0; b = 1; cin = 1;
    # 10
    a = 1; b = 0; cin = 0;
    # 10
    a = 1; b = 0; cin = 1;
    # 10
    a = 1; b = 1; cin = 0;
    # 10
    a = 1; b = 1; cin = 1;
    # 10
    $finish;
  end
endmodule
    