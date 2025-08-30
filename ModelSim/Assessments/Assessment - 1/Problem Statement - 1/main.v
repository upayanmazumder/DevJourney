module ALL_GATES(A, B, Y_AND, Y_OR, Y_NOR, Y_NAND, Y_NOT);
  input A, B;
  output Y_AND, Y_OR, Y_NOR, Y_NAND, Y_NOT;
  and(Y_AND, A, B);
  or(Y_OR, A, B);
  not(Y_NOT, A);
  nor(Y_NOR, A, B);
  nand(Y_NAND, A, B);
endmodule
