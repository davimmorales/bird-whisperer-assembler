module simpleInstructionsRam(clock, address, iRAMOutput);
	 input [9:0] address;
	 input clock;
	 output [31:0] iRAMOutput;
	 integer firstClock = 0;
	 reg [31:0] instructionsRAM[18:0];

	 always @ ( posedge clock ) begin
	 	 if (firstClock==0) begin
 
	 	 bios[0] <= 32'b01101100000000000000000000000000;//Nop
	 	 bios[1] <= 32'b01101000000000000000000000000000;//Loadi #0 to r[0]
	 	 bios[2] <= 32'b01101010110000000000000000000001;//Loadi #0, #1 to r[22]
	 	 bios[3] <= 32'b01101010111000000000000000000010;//Loadi #0, #2 to r[23]
	 	 bios[4] <= 32'b01101011000000000000000000000011;//Loadi #0, #3 to r[24]
	 	 bios[5] <= 32'b10010101000101100000000000000000;//LoadHD m[r[22]] to r[8]
	 	 bios[6] <= 32'b10010101001101110000000000000000;//LoadHD m[r[23]] to r[9]
	 	 bios[7] <= 32'b10010101100110000000000000000000;//LoadHD m[r[24]] to r[12]
	 	 bios[8] <= 32'b01101000010000000000000000001111;//Loadi #15 to r[2]
	 	 bios[9] <= 32'b01101000011000000000000001000100;//Loadi #68 to r[3]
	 	 bios[10] <= 32'b01101000101000000000000000010101;//Loadi #21 to r[5]
	 	 bios[11] <= 32'b01101001010000000000000000000000;//Loadi #0 to r[10]
	 	 bios[12] <= 32'b01101001011000000000000000000001;//Loadi #1 to r[11]
	 	 bios[13] <= 32'b01101001101000000000000000000011;//Loadi #3 to r[13]
	 	 bios[14] <= 32'b10011001000010100000000000000000;//rStore r[8] in m[r[10]] 
	 	 bios[15] <= 32'b10011001001010110000000000000000;//rStore r[9] in m[r[11]] 
	 	 bios[16] <= 32'b10011001100011010000000000000000;//rStore r[12] in m[r[13]] 
	 	 bios[17] <= 32'b10011100000000000000000000000000;//Nop

	 	 firstClock <= 0;
	 	 end
	 end

	 assign iRAMOutput = instructionsRAM[address];
endmodule // simpleInstructionsRAM
