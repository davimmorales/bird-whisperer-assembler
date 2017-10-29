module simpleInstructionsRam(clock, address, iRAMOutput);
	 input [9:0] address;
	 input clock;
	 output [31:0] iRAMOutput;
	 integer firstClock = 0;
	 reg [31:0] instructionsRAM[10:0];

	 always @ ( posedge clock ) begin
	 	 if (firstClock==0) begin
 
	 	 instructionsRAM[0] <= 32'b01101100000000000000000000000000;//Nop
	 	 instructionsRAM[1] <= 32'b01101000010000000000000000101101;//Loadi #45 to r[2]
	 	 instructionsRAM[2] <= 32'b01101000011000001000000000000011;//Loadi #3, #2 to r[3]
	 	 instructionsRAM[3] <= 32'b10010000010000110000000000000000;//hdStore r[2] in m[r[3]] 
	 	 instructionsRAM[4] <= 32'b10010100101000110000000000000000;//LoadHD m[r[3]] to r[5]
	 	 instructionsRAM[5] <= 32'b10000000010000000000000000000000;//Output r[2]
	 	 instructionsRAM[6] <= 32'b10000000011000000000000000000000;//Output r[3]
	 	 instructionsRAM[7] <= 32'b10000000101000000000000000000000;//Output r[5]
	 	 instructionsRAM[8] <= 32'b01110000000000000000000000000000;//Hlt
	 	 instructionsRAM[9] <= 32'b01110000000000000000000000000000;//Hlt

	 	 firstClock <= 0;
	 	 end
	 end

	 assign iRAMOutput = instructionsRAM[address];
endmodule // simpleInstructionsRAM
