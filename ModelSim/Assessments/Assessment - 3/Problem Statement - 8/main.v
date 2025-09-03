module half_subtractor(input a, b, output diff, borrow);
  assign diff = a ^ b;
  assign borrow = ~a & b;
endmodule

module full_subtractor(input a, b, bin, output diff, bout);
  wire d1, b1, b2;
  
  half_subtractor hs1(a, b, d1, b1);
  half_subtractor hs2(d1, bin, diff, b2);
  assign bout = b1 | b2;
endmodule

module testbench();
  reg a, b, bin;
  wire diff, bout;
  
  full_subtractor fs(a, b, bin, diff, bout);
  
  initial begin
    a = 0; b = 0; bin = 0; #10;
    a = 0; b = 0; bin = 1; #10;
    a = 0; b = 1; bin = 0; #10;
    a = 0; b = 1; bin = 1; #10;
    a = 1; b = 0; bin = 0; #10;
    a = 1; b = 0; bin = 1; #10;
    a = 1; b = 1; bin = 0; #10;
    a = 1; b = 1; bin = 1; #10;
    $finish;
  end
endmodule