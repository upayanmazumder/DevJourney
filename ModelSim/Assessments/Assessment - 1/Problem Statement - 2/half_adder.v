module half_adder(input a,b,  output sum,carry);
  xor (sum,a,b);
  and (carry,a,b);
endmodule
module testModule();
  reg a,b;
  wire sum,carry;
  half_adder u1(a,b,sum,carry);
  initial
  begin
    a = 0;
    b = 0;
    #100
    a = 0;
    b = 1;
    #100
    a = 1;
    b = 0;
    #100
    a = 1;
    b = 1;
  end
endmodule