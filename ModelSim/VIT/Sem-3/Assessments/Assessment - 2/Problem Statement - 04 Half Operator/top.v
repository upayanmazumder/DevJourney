module half_operator(X, Y, D, B, S, C);
  input X, Y;
  output D, B, S, C;
  assign S = X ^ Y;
  assign C = X & Y;
  assign D = X ^ Y;
  assign B = ~X & Y;
endmodule

module test();
  reg X, Y;
  wire D, B, S, C;
  half_operator U(X, Y, D, B, S, C);
  initial
  begin
    X = 0;
    Y = 0;
    # 100
    X = 0;
    Y = 1;
    # 100
    X = 1;
    Y = 0;
    # 100
    X = 1;
    Y = 1;
  end
endmodule
