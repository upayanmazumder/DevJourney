module decoder_3x8 (
    input [2:0] in,
    output reg [7:0] out
);

always @(*) begin
    case (in)
        3'b000: out = 8'b00000001;
        3'b001: out = 8'b00000010;
        3'b010: out = 8'b00000100;
        3'b011: out = 8'b00001000;
        3'b100: out = 8'b00010000;
        3'b101: out = 8'b00100000;
        3'b110: out = 8'b01000000;
        3'b111: out = 8'b10000000;
        default: out = 8'b00000000;
    endcase
end

endmodule

module tb_decoder_3x8;
    reg [2:0] in;
    wire [7:0] out;

    decoder_3x8 uut (
        .in(in),
        .out(out)
    );

    initial begin
        // Apply all possible 3-bit inputs
        in = 3'b000; #10;
        in = 3'b001; #10;
        in = 3'b010; #10;
        in = 3'b011; #10;
        in = 3'b100; #10;
        in = 3'b101; #10;
        in = 3'b110; #10;
        in = 3'b111; #10;

        #10;
        $finish;
    end

endmodule