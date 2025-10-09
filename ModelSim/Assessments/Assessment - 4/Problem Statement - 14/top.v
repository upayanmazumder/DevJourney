module jk_ff (
    input J,
    input K,
    input clk,
    input rst,     // active high reset
    output reg Q
);

always @(posedge clk or posedge rst) begin
    if (rst)
        Q <= 0;
    else begin
        case ({J, K})
            2'b00: Q <= Q;     // no change
            2'b01: Q <= 0;     // reset
            2'b10: Q <= 1;     // set
            2'b11: Q <= ~Q;    // toggle
        endcase
    end
end

endmodule

module jk_ff (
    input J,
    input K,
    input clk,
    input rst,     // active high reset
    output reg Q
);

always @(posedge clk or posedge rst) begin
    if (rst)
        Q <= 0;
    else begin
        case ({J, K})
            2'b00: Q <= Q;     // no change
            2'b01: Q <= 0;     // reset
            2'b10: Q <= 1;     // set
            2'b11: Q <= ~Q;    // toggle
        endcase
    end
end

endmodule