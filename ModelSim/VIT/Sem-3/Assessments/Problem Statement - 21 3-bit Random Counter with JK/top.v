module jk_sequence_counter (input clk,input rst,output reg [2:0] Q);
    always @(posedge clk or posedge rst) begin
        if (rst)
            Q <= 3'b000;        
        else begin
            case (Q)
                3'b000: Q <= 3'b001;  
                3'b001: Q <= 3'b010;   
                3'b010: Q <= 3'b111;   
                3'b111: Q <= 3'b000;   
            endcase
        end
    end
endmodule

module tb_jk_sequence_counter;
    reg clk, rst;
    wire [2:0] Q;   
    jk_sequence_counter uut (.clk(clk),.rst(rst),.Q(Q));    
    initial begin
        clk = 0;
        forever #5 clk = ~clk;   
    end  
    initial begin
        rst = 1;          
        #10 rst = 0;      
        #100 $finish;     
    end
endmodule