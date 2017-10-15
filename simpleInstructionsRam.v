module simpleInstructionsRam(clock, address, iRAMOutput);
	 input [9:0] address;
	 input clock;
	 output [31:0] iRAMOutput;
	 integer firstClock = 0;
	 reg [31:0] instructionsRAM[3:0];

	 always @ ( posedge clock ) begin
	 	 if (firstClock==0) begin
 
	 	 instructionsRAM[0] = 32'b00000000101000100010000000000000;//ADD r[2],r[4] to r[5]
	 	 instructionsRAM[1] = 32'b00001000101000100001100000000000;//SUB r[2],r[3] to r[5]
	 	 instructionsRAM[2] = 32'b00001100100000100000000000000100;//SUBi r[2], #4 to r[4]

	 	 firstClock <= 0;
	 	 end
	 end

	 assign iRAMOutput = instructionsRAM[address];
endmodule // simpleInstructionsRAM
