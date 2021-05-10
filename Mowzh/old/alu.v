module ALU_8(
    code,
    a,
    b,
    out,
    carry,
    zero
);    

input [2:0]  code;
input [7:0]  a;
input [7:0]  b;

output reg [15:0] out = 16'b0;
output reg  carry = 1'b0;
output reg  zero = 1'b0;   

parameter  [2:0] ADD = 3'b000;
parameter  [2:0] SUB = 3'b001;
parameter  [2:0] MUL = 3'b010;
parameter  [2:0] AND = 3'b011;
parameter  [2:0] OR = 3'b100;
parameter  [2:0] NAND = 3'b101;
parameter  [2:0] NOR = 3'b110;
parameter  [2:0] XOR = 3'b111;

always @ (code or a or b)
begin
 case (code)

 ADD: begin
   out = a + b;
   carry  = out[8];
   zero  = (out == 16'b0);
  end

 SUB: begin
   out = a - b;
   carry  = out[8];
   zero  = (out == 16'b0);
  end

 MUL: begin
   out = a * b;
   zero  = (out == 16'b0);
  end

 AND: begin
   out = a & b;
   zero  = (out == 16'b0);
  end

 OR:  begin
    out = a | b;
    zero  = (out == 16'b0);
   end

 NAND: begin
   out = ~(a & b);
   zero  = (out == 16'b0);
  end

 NOR: begin
   out = ~(a | b);
   zero  = (out == 16'b0);
  end

 XOR: begin
   out = a ^ b;
   zero  = (out == 16'b0);
  end

 default: begin
   out = 16'b0;
   carry  = 1'b0;
   zero  = 1'b0;
  end

 endcase

end

endmodule



module ALU_8_TEST;

 reg [2:0] code;
 reg [7:0] a;
 reg [7:0] b;


 wire [15:0] out;
 wire carry;
 wire zero;
 reg [2:0] count = 3'd0;

 ALU_8   (
  .code(code), 
  .a(a), 
  .b(b), 
  .out(out), 
  .carry(carry), 
  .zero(zero)
  );

 initial begin
  code   = 3'b0;
  a = 8'd0;
  b = 8'd0;

  #100;    
  a = 8'hAA;
  b = 8'h55;  
  for (count = 0; count < 8; count = count + 1'b1) 
  begin
   code = count;
   #20;

  end
 end     

endmodule