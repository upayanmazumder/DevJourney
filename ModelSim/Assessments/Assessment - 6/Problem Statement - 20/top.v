module counter_2bit (input wire clk,input wire reset,output reg [1:0] Q);
    always @(posedge clk or posedge reset) begin
        if (reset)
            Q <= 2'b00;
        else begin
            case (Q)
                2'b00: Q <= 2'b01;
                2'b01: Q <= 2'b10;
                2'b10: Q <= 2'b11;
                2'b11: Q <= 2'b00;
            endcase
        end
    end
endmodule

module tb_counter_2bit;
    reg clk;
    reg reset;
    wire [1:0] Q;

    counter_2bit uut (.clk(clk),.reset(reset),.Q(Q));
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end
    initial begin
        reset = 1;
        #10;
        reset = 0;
        #100;
        $finish;
    end
endmodule
