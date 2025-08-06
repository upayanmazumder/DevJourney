module two_level(Y, A, B, C, D);
  input A, B, C, D;
  output Y;
  wire t1, t2;
  
  and and_1(t1, A, B);
  and and_2(t2, C, D);
  
  or or_1(Y, t1, t2);
  
endmodule