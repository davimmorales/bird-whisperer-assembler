#include "general.h"

using namespace std;

FILE *file_target_code;


/* Function to convert a decinal number to binary number */
char *decimal_to_binary(int decimal, int lenght){
  int c, d, count;
  char *pointer;

  count = 0;
  pointer = (char*) malloc(32+1);

  if (pointer==NULL) {
    exit(EXIT_FAILURE);
  }

  for ( c = lenght-1; c >= 0; c--) {
    d = decimal >> c;

    if(d & 1){
      *(pointer + count) = 1 + '0';
    }else{
      *(pointer + count) = 0 + '0';
    }
    count++;
  }
  *(pointer + count) = '\0';

  return pointer;
}

void print_target_code(vector<type_instruction> &instructions_list){
  file_target_code = fopen("simpleInstructionsRam.v", "w");
  vector<type_instruction>::iterator instruction;



  for(instruction = instructions_list.begin(); instruction != instructions_list.end(); instruction++){
    fprintf(file_target_code, "\t \t HD[%d] = 32'b", instruction->line);//+4096+3*192);//for HD sectors: 2048
    switch (instruction->type) {
      case add:
        fprintf(file_target_code, "000000%s%s%s00000000000;//ADD r[%d],r[%d] to r[%d]\n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->register_b, 5),
        instruction->register_a, instruction->register_b, instruction->register_c);
      break;
      case addi:
        fprintf(file_target_code, "000001%s%s%s;//ADDi r[%d], #%d to r[%d]\n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 16),
        instruction->register_a, instruction->immediate, instruction->register_c);
      break;
      case sub:
        fprintf(file_target_code, "000010%s%s%s00000000000;//SUB r[%d],r[%d] to r[%d]\n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->register_b, 5),
        instruction->register_a, instruction->register_b, instruction->register_c);
      break;
      case subi:
        fprintf(file_target_code, "000011%s%s%s;//SUBi r[%d], #%d to r[%d]\n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 16),
        instruction->register_a, instruction->immediate, instruction->register_c);
      break;
      case times:
        fprintf(file_target_code, "000100%s%s%s00000000000;//TIMES r[%d],r[%d] to r[%d]\n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->register_b, 5),
        instruction->register_a, instruction->register_b, instruction->register_c);
      break;
      case over:
        fprintf(file_target_code, "000101%s%s%s00000000000;//DIVIDE r[%d],r[%d] to r[%d]\n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->register_b, 5),
        instruction->register_a, instruction->register_b, instruction->register_c);
      break;
      case incr:
        fprintf(file_target_code, "forgot %d\n", instruction->type);
      break;
      case decr:
        fprintf(file_target_code, "forgot %d\n", instruction->type);
      break;
      case andg:
        fprintf(file_target_code, "001000%s%s%s00000000000;//AND r[%d],r[%d] to r[%d]\n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->register_b, 5),
        instruction->register_a, instruction->register_b, instruction->register_c);
      break;
      case org:
        fprintf(file_target_code, "001001%s%s%s00000000000;//OR r[%d],r[%d] to r[%d]\n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->register_b, 5),
        instruction->register_a, instruction->register_b, instruction->register_c);
      break;
      case module:
        fprintf(file_target_code, "forgot %d\n", instruction->type);
      break;
      case xorg:
        fprintf(file_target_code, "forgot %d\n", instruction->type);
      break;
      case notg:
        fprintf(file_target_code, "001101%s%s0000000000000000;//NOT r[%d] to r[%d]\n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        instruction->register_a, instruction->register_c);
      break;
      case shiftl:
        fprintf(file_target_code, "010000%s%s%s;//shiftl r[%d] by #%d bits to r[%d]\n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 16),
      instruction->register_a, instruction->immediate, instruction->register_c);
      break;
      case shiftr:
        fprintf(file_target_code, "forgot %d\n", instruction->type);
      break;
      case pbranch:
        fprintf(file_target_code, "01111100000%s0000000000000000;//Pre Branch r[%d]\n",
        decimal_to_binary(instruction->register_a, 5),
        instruction->register_a);
      break;
      case branchz:
        fprintf(file_target_code, "010011%s;//Branch on Zero #%d\n",
        decimal_to_binary(instruction->immediate, 26),
        instruction->immediate);
      break;
      case branchn:
        fprintf(file_target_code, "010100%s;//Branch on Negative #%d\n",
        decimal_to_binary(instruction->immediate, 26),
        instruction->immediate);
      break;
      case jump:
        fprintf(file_target_code, "010101%s;//Jump to #%d\n",
        decimal_to_binary(instruction->immediate, 26),
        instruction->immediate);
      break;
      case jumpr:
        fprintf(file_target_code, "10001100000%s%s;//Jump to r[%d]\n",
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 16),
        instruction->register_a);
      break;
      case noo:
        fprintf(file_target_code, "01101100000000000000000000000000;//Nop\n");
      break;
      case preio:
        fprintf(file_target_code, "01111000000000000000000000000000;//preio\n");
      break;
      case start_system:
        fprintf(file_target_code, "10011100000000000000000000000000;//Start System\n");
      break;
      case setlt:
        fprintf(file_target_code, "010111%s%s%s00000000000;//SLT if r[%d] < r[%d], r[%d] = 1 else r[%d] = 0\n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->register_b, 5),
        instruction->register_a, instruction->register_b, instruction->register_c, instruction->register_c);
      break;
      case load:
        fprintf(file_target_code, "011000%s%s;//Load m[#%d] to r[%d]\n",
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 21),
        instruction->immediate, instruction->register_a);
      break;
      case store:
        fprintf(file_target_code, "011001%s%s;//Store r[%d] in m[#%d]\n",
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 21),
        instruction->register_a, instruction->immediate);
      break;
      case loadi:
        fprintf(file_target_code, "011010%s%s;//Loadi #%d to r[%d]\n",
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 21),
        instruction->immediate, instruction->register_a);
      break;
      case loadi_hd:
        fprintf(file_target_code, "011010%s%s%s;//Loadi #%d, #%d to r[%d]\n",
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->register_b, 10),
        decimal_to_binary(instruction->immediate, 11),
        instruction->register_b, instruction->immediate,  instruction->register_a);
      break;
      case input:
        fprintf(file_target_code, "011101%s%s;//Input to r[%d]\n",
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 21),
        instruction->register_a);
      break;
      case halt:
        fprintf(file_target_code, "01110000000000000000000000000000;//Hlt\n");
      break;
      // case poutput:
      //   fprintf(file_target_code, "011110%s%s;//Pre Output r[%d]\n",
      //   decimal_to_binary(instruction->register_a, 5),
      //   decimal_to_binary(instruction->immediate, 21),
      //   instruction->register_a);
      // break;
      case output:
        fprintf(file_target_code, "100000%s%s;//Output r[%d]\n",
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 21),
        instruction->register_a);
      break;
      case loadr:
        fprintf(file_target_code, "100001%s%s%s;//Loadr m[r[%d]] to r[%d]\n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 16),
        instruction->register_a, instruction->register_c);
      break;
      case storer:
        fprintf(file_target_code, "100010%s%s%s;//rStore r[%d] in m[r[%d]] \n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 16),
        instruction->register_c, instruction->register_a);
      break;
      case store_hd:
        fprintf(file_target_code, "100100%s%s%s;//hdStore r[%d] in m[r[%d]] \n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 16),
        instruction->register_c, instruction->register_a);
      break;
      case load_hd:
        fprintf(file_target_code, "100101%s%s%s;//LoadHD m[r[%d]] to r[%d]\n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 16),
        instruction->register_a, instruction->register_c);
      break;
      case store_i_ram:
        fprintf(file_target_code, "100110%s%s%s;//rStore r[%d] in m[r[%d]] \n",
        decimal_to_binary(instruction->register_c, 5),
        decimal_to_binary(instruction->register_a, 5),
        decimal_to_binary(instruction->immediate, 16),
        instruction->register_c, instruction->register_a);
      break;
      case load_wd:
        fprintf(file_target_code, "101000%s000000000000000000000;//Load wd to r[%d]\n",
        decimal_to_binary(instruction->register_a, 5),
        instruction->register_a);
      break;
      case load_ino:
        fprintf(file_target_code, "101010%s000000000000000000000;//Load arduino to r[%d]\n",
        decimal_to_binary(instruction->register_a, 5),
        instruction->register_a);
      break;
      case store_ino:
        fprintf(file_target_code, "101001%s000000000000000000000;//Store r[%d] to arduino\n",
        decimal_to_binary(instruction->register_a, 5),
        instruction->register_a);
      break;
      default:
        printf("Galetype Unknown: %d\n", instruction->type);
      break;
    }
  }
  fclose( file_target_code );
}
