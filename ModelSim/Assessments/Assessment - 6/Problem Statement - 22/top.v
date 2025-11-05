module Moore_Sequence_Detector(input clk, input reset, input data_in, output reg detected);
  parameter S0 = 2'b00,
  S1 = 2'b01,
  S2 = 2'b10,
  S3 = 2'b11;
  reg [1:0] current_state, next_state;
  always @(posedge clk or posedge reset) begin
    if (reset == 1) begin
      current_state <= S0;
    end else begin
      current_state <= next_state;
    end
  end
  always @(current_state or data_in) begin
    case (current_state)
      S0: begin
        if (data_in == 1)
          next_state = S1;
        else
          next_state = S0;
      end
      S1: begin
        if (data_in == 0)
          next_state = S2;
        else
          next_state = S1;
      end
      S2: begin
        if (data_in == 1)
          next_state = S3;
        else
          next_state = S0;
      end
      S3: begin
        if (data_in == 0)
          next_state = S2;
        else
          next_state = S1;
      end
      default: begin
        next_state = S0;
      end
    endcase
  end
  always @(current_state) begin
    case (current_state)
      S0: detected = 0;
      S1: detected = 0;
      S2: detected = 0;
      S3: detected = 1;
      default: detected = 0;
    endcase
  end
endmodule

module TB_Moore_Sequence_Detector;
  reg clk;
  reg reset;
  reg data_in;
  wire detected;
  Moore_Sequence_Detector DUT(.clk(clk), .reset(reset), .data_in(data_in), .detected(detected));
  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end
  initial begin
    reset = 1;
    data_in = 0;
    #15;
    reset = 0;
    #10;
    data_in = 1; #10;
    data_in = 0; #10;
    data_in = 1; #10;
    data_in = 1; #10;
    data_in = 0; #10;
    data_in = 1; #10;
    data_in = 1; #10;
    data_in = 0; #10;
    data_in = 1; #10;
    #20;
    $display("Simulation finished");
    $finish;
  end
endmodule
    
    