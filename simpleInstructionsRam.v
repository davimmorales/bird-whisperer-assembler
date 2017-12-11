module simpleInstructionsRam(clock, address, iRAMOutput);
	 input [9:0] address;
	 input clock;
	 output [31:0] iRAMOutput;
	 integer firstClock = 0;
	 reg [31:0] instructionsRAM[82:0];

	 always @ ( posedge clock ) begin
	 	 if (firstClock==0) begin
 
	 	 instructionsRAM[0] <= 32'b01101100000000000000000000000000;//Nop
	 	 instructionsRAM[1] <= 32'b01101000000000000000000000000000;//Loadi #0 to r[0]
	 	 instructionsRAM[2] <= 32'b01110110101000000000000000000000;//Input to r[21]
	 	 instructionsRAM[3] <= 32'b01100110101000000000000000000101;//Store r[21] in m[#5]
	 	 instructionsRAM[4] <= 32'b01101010101000000100000000000000;//Loadi #1, #0 to r[21]
	 	 instructionsRAM[5] <= 32'b01100110101000000000000000000100;//Store r[21] in m[#4]
	 	 instructionsRAM[6] <= 32'b01100010101000000000000000000100;//Load m[#4] to r[21]
	 	 instructionsRAM[7] <= 32'b10010110110101010000000000000000;//LoadHD m[r[21]] to r[22]
	 	 instructionsRAM[8] <= 32'b01011110111000001011000000000000;//SLT if r[0] < r[22], r[23] = 1 else r[23] = 0
	 	 instructionsRAM[9] <= 32'b01111100000101110000000000000000;//Pre Branch r[23]
	 	 instructionsRAM[10] <= 32'b01001100000000000000000000001011;//Branch on Zero #11
	 	 instructionsRAM[11] <= 32'b01100010111000000000000000000101;//Load m[#5] to r[23]
	 	 instructionsRAM[12] <= 32'b01011111000101101011100000000000;//SLT if r[22] < r[23], r[24] = 1 else r[24] = 0
	 	 instructionsRAM[13] <= 32'b01011111001101111011000000000000;//SLT if r[23] < r[22], r[25] = 1 else r[25] = 0
	 	 instructionsRAM[14] <= 32'b00100111000110001100100000000000;//OR r[24],r[25] to r[24]
	 	 instructionsRAM[15] <= 32'b00110111000110000000000000000000;//NOT r[24] to r[24]
	 	 instructionsRAM[16] <= 32'b01111100000110000000000000000000;//Pre Branch r[24]
	 	 instructionsRAM[17] <= 32'b01001100000000000000000000000001;//Branch on Zero #1
	 	 instructionsRAM[18] <= 32'b01010100000000000000000000010110;//Jump to #22
	 	 instructionsRAM[19] <= 32'b01100010101000000000000000000100;//Load m[#4] to r[21]
	 	 instructionsRAM[20] <= 32'b00000110101101010000000000100000;//ADDi r[21], #32 to r[21]
	 	 instructionsRAM[21] <= 32'b01010100000000000000000000000101;//Jump to #5
	 	 instructionsRAM[22] <= 32'b01100110101000000000000000000100;//Store r[21] in m[#4]
	 	 instructionsRAM[23] <= 32'b01100010101000000000000000000100;//Load m[#4] to r[21]
	 	 instructionsRAM[24] <= 32'b00000110101101010000000000000110;//ADDi r[21], #6 to r[21]
	 	 instructionsRAM[25] <= 32'b10010011100101010000000000000000;//hdStore r[28] in m[r[21]] 
	 	 instructionsRAM[26] <= 32'b00000110101101010000000000000110;//ADDi r[21], #6 to r[21]
	 	 instructionsRAM[27] <= 32'b10010000000101010000000000000000;//hdStore r[0] in m[r[21]] 
	 	 instructionsRAM[28] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[29] <= 32'b10010000001101010000000000000000;//hdStore r[1] in m[r[21]] 
	 	 instructionsRAM[30] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[31] <= 32'b10010000010101010000000000000000;//hdStore r[2] in m[r[21]] 
	 	 instructionsRAM[32] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[33] <= 32'b10010000011101010000000000000000;//hdStore r[3] in m[r[21]] 
	 	 instructionsRAM[34] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[35] <= 32'b10010000100101010000000000000000;//hdStore r[4] in m[r[21]] 
	 	 instructionsRAM[36] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[37] <= 32'b10010000101101010000000000000000;//hdStore r[5] in m[r[21]] 
	 	 instructionsRAM[38] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[39] <= 32'b10010000110101010000000000000000;//hdStore r[6] in m[r[21]] 
	 	 instructionsRAM[40] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[41] <= 32'b10010000111101010000000000000000;//hdStore r[7] in m[r[21]] 
	 	 instructionsRAM[42] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[43] <= 32'b10010001000101010000000000000000;//hdStore r[8] in m[r[21]] 
	 	 instructionsRAM[44] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[45] <= 32'b10010001001101010000000000000000;//hdStore r[9] in m[r[21]] 
	 	 instructionsRAM[46] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[47] <= 32'b10010001010101010000000000000000;//hdStore r[10] in m[r[21]] 
	 	 instructionsRAM[48] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[49] <= 32'b10010001011101010000000000000000;//hdStore r[11] in m[r[21]] 
	 	 instructionsRAM[50] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[51] <= 32'b10010001100101010000000000000000;//hdStore r[12] in m[r[21]] 
	 	 instructionsRAM[52] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[53] <= 32'b10010001101101010000000000000000;//hdStore r[13] in m[r[21]] 
	 	 instructionsRAM[54] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[55] <= 32'b10010001110101010000000000000000;//hdStore r[14] in m[r[21]] 
	 	 instructionsRAM[56] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[57] <= 32'b10010001111101010000000000000000;//hdStore r[15] in m[r[21]] 
	 	 instructionsRAM[58] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[59] <= 32'b10010010000101010000000000000000;//hdStore r[16] in m[r[21]] 
	 	 instructionsRAM[60] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[61] <= 32'b10010010001101010000000000000000;//hdStore r[17] in m[r[21]] 
	 	 instructionsRAM[62] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[63] <= 32'b10010010010101010000000000000000;//hdStore r[18] in m[r[21]] 
	 	 instructionsRAM[64] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[65] <= 32'b10010010011101010000000000000000;//hdStore r[19] in m[r[21]] 
	 	 instructionsRAM[66] <= 32'b01110110101000000000000000000000;//Input to r[21]
	 	 instructionsRAM[67] <= 32'b00000110101101010000000000001100;//ADDi r[21], #12 to r[21]
	 	 instructionsRAM[68] <= 32'b01101010111000000100000001100000;//Loadi #1, #96 to r[23]
	 	 instructionsRAM[69] <= 32'b01101100000000000000000000000000;//Nop
	 	 instructionsRAM[70] <= 32'b01011111000101011011100000000000;//SLT if r[21] < r[23], r[24] = 1 else r[24] = 0
	 	 instructionsRAM[71] <= 32'b01111100000110000000000000000000;//Pre Branch r[24]
	 	 instructionsRAM[72] <= 32'b01001100000000000000000000000100;//Branch on Zero #4
	 	 instructionsRAM[73] <= 32'b10010110110101010000000000000000;//LoadHD m[r[21]] to r[22]
	 	 instructionsRAM[74] <= 32'b10000010110000000000000000000000;//Output r[22]
	 	 instructionsRAM[75] <= 32'b00000110101101010000000000000001;//ADDi r[21], #1 to r[21]
	 	 instructionsRAM[76] <= 32'b01010100000000000000000001000110;//Jump to #70
	 	 instructionsRAM[77] <= 32'b01100010101000000000000000000100;//Load m[#4] to r[21]
	 	 instructionsRAM[78] <= 32'b00000110101101010000000000000110;//ADDi r[21], #6 to r[21]
	 	 instructionsRAM[79] <= 32'b10010110101101010000000000000000;//LoadHD m[r[21]] to r[21]
	 	 instructionsRAM[80] <= 32'b10000010101000000000000000000000;//Output r[21]
	 	 instructionsRAM[81] <= 32'b01110000000000000000000000000000;//Hlt

	 	 firstClock <= 0;
	 	 end
	 end

	 assign iRAMOutput = instructionsRAM[address];
endmodule // simpleInstructionsRAM
