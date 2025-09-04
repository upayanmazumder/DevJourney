module magnitude_comparator(input A1, A0, B1, B0, output Y1, Y0);
   wire A_greater_B, A_equal_B;
   
   assign A_greater_B = (A1 & ~B1) | ((A1 ~^ B1) & A0 & ~B0);
   assign A_equal_B = (A1 ~^ B1) & (A0 ~^ B0);
   
   assign Y1 = A_greater_B;
   assign Y0 = A_equal_B;
endmodule

module magnitude_comparator_testbench();
    reg A1, A0, B1, B0;
    wire Y1, Y0;
    
    magnitude_comparator uut(A1, A0, B1, B0, Y1, Y0);
    
    initial begin
        A1 = 0; A0 = 0; B1 = 0; B0 = 0; #10;
        A1 = 0; A0 = 0; B1 = 0; B0 = 1; #10;
        A1 = 0; A0 = 0; B1 = 1; B0 = 0; #10;
        A1 = 0; A0 = 0; B1 = 1; B0 = 1; #10;
        A1 = 0; A0 = 1; B1 = 0; B0 = 0; #10;
        A1 = 0; A0 = 1; B1 = 0; B0 = 1; #10;
        A1 = 0; A0 = 1; B1 = 1; B0 = 0; #10;
        A1 = 0; A0 = 1; B1 = 1; B0 = 1; #10;
        A1 = 1; A0 = 0; B1 = 0; B0 = 0; #10;
        A1 = 1; A0 = 0; B1 = 0; B0 = 1; #10;
        A1 = 1; A0 = 0; B1 = 1; B0 = 0; #10;
        A1 = 1; A0 = 0; B1 = 1; B0 = 1; #10;
        A1 = 1; A0 = 1; B1 = 0; B0 = 0; #10;
        A1 = 1; A0 = 1; B1 = 0; B0 = 1; #10;
        A1 = 1; A0 = 1; B1 = 1; B0 = 0; #10;
        A1 = 1; A0 = 1; B1 = 1; B0 = 1; #10;
        $finish;
   end
endmodule	