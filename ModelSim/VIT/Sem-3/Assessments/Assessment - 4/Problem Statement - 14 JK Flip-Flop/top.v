module jk_ff (
    input clk,
    input j,
    input k,
    input reset,
    output reg q,
    output qbar
);

    assign qbar = ~q;

    always @(posedge clk or negedge reset) begin
        if (!reset)
            q <= 1'b0; 
        else begin
            case ({j, k})
                2'b00: q <= q;         
                2'b01: q <= 1'b0;      
                2'b10: q <= 1'b1;      
                2'b11: q <= ~q;        
            endcase
        end
    end
endmodule


module tb_jk_ff;

    reg clk;
    reg j, k;
    reg reset;
    wire q, qbar;

    jk_ff uut (
        .clk(clk),
        .j(j),
        .k(k),
        .reset(reset),
        .q(q),
        .qbar(qbar)
    );

    
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    
    initial begin
        reset = 0; j = 0; k = 0; #10;
        reset = 1; #10;

        j = 0; k = 0; #10;
        j = 0; k = 1; #10;
        j = 1; k = 0; #10;
        j = 1; k = 1; #10;
        j = 1; k = 1; #10;
        j = 1; k = 1; #10;

        reset = 0; #10;
        reset = 1; #10;

        #20; 
    end

endmodule
