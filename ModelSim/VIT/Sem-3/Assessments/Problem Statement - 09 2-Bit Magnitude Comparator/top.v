module magnitude_comparator(input A1, A0, B1, B0, output Y1, Y0);
   wire A_greater_B, A_equal_B;
   
   assign A_greater_B = (A1 & ~B1) | ((A1 ~^ B1) & A0 & ~B0);
   assign A_equal_B = (A1 ~^ B1) & (A0 ~^ B0);
   
   assign Y1 = A_greater_B;
   assign Y0 = A_equal_B;
endmodule

module magnitude_comparator_testbench();
    reg [1:0] A, B;
    wire Y1, Y0;

    magnitude_comparator uut(A[1], A[0], B[1], B[0], Y1, Y0);

    initial begin
        A = 2'b00; B = 2'b00; #10;
        A = 2'b00; B = 2'b01; #10;
        A = 2'b00; B = 2'b10; #10;
        A = 2'b00; B = 2'b11; #10;

        A = 2'b01; B = 2'b00; #10;
        A = 2'b01; B = 2'b01; #10;
        A = 2'b01; B = 2'b10; #10;
        A = 2'b01; B = 2'b11; #10;

        A = 2'b10; B = 2'b00; #10;
        A = 2'b10; B = 2'b01; #10;
        A = 2'b10; B = 2'b10; #10;
        A = 2'b10; B = 2'b11; #10;

        A = 2'b11; B = 2'b00; #10;
        A = 2'b11; B = 2'b01; #10;
        A = 2'b11; B = 2'b10; #10;
        A = 2'b11; B = 2'b11; #10;

        $finish;
    end
endmodule

