module blink (
    input wire clk,        // 50 MHz clock input
    output reg led         // LED output
);

    // Counter for delay
    reg [24:0] counter = 0; // 25-bit counter for ~0.67s toggle at 50MHz

    always @(posedge clk) begin
        counter <= counter + 1;
        if (counter == 25_000_000) begin
            counter <= 0;
            led <= ~led; // toggle LED
        end
    end

endmodule

