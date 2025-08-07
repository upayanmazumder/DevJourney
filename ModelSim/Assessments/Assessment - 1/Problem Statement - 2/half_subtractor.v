module half_subtractor(input a,b,  output diff,borr);
  wire nota;
  not (nota,a);
  xor (diff,a,b);
  and (borr,nota,b);
  
endmodule
module testModule2();
  reg a,b;
  wire diff,borr;
  half_subtractor u2(a,b,diff,borr);
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

