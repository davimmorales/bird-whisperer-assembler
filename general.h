#ifndef _general_H_
#define _general_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

typedef enum{
    /*0 Adição  000000 &*/ add, // R[DR] <- R[SA] + R[SB]
  /*1 Adição Imediato  000001 &*/ addi, // R[DR] <- R[SA] + IM
  /*2 Subtração  000010 &*/ sub, // R[DR] <- R[SA] + \overline{R[SB]} + 1
  /*3 Subtração Imediato  000011 &*/ subi, // R[DR] <- R[SA] + \overline{IM} + 1
  /*4 Multiplicação  000100 &*/ times, // R[DR] <- R[SA] * R[SB]
  /*5 Divisão  000101 &*/ over, // R[DR] <- R[SA] / R[SB]
  /*6 Incrementa  000110 &*/ incr, // R[DR] <- R[SA] + 1
  /*7 Decrementa  000111 &*/ decr, // R[DR] <- R[SA] - 1
  /*8 And  001000 &*/ andg, // R[DR] <- R[SA] \wedge R[SB]
  /*9 Or  001001 &*/ org, // R[DR] <- R[SA] \vee R[SB]
  /*10 Resto  001010 &*/ module, // R[DR] <- R[SA] \% R[SB]
  /*11 Xor  001100 &*/ xorg, // R[DR] <- R[SA] \bigoplus R[SB]
  /*12 Not  001101 &*/ notg, // R[DR] <- \overline{R[SA]}
  /*13 Desloca Esquerda  010000 &*/ shiftl, // R[DR] <- sl (shamt)R[SA]
  /*14 Desloca Direita  010001 &*/ shiftr, // R[DR] <- sr (shamt)R[SA]
  /*15 Pré-branch  011111 &*/ pbranch, // se R[SA] = 0, FZ = 1;  se R[SA] < 0, FN = 1;
  /*16 Branch em Zero  010011 &*/ branchz, // se FZ = 1, então PC <- PC + 1 + IM e FZ = 0, então PC <- PC + 1
  /*17 Branch em Negativo  010100 &*/ branchn, // se FN = 1, então PC <- PC + IM e FN = 0, então PC <- PC + 1
  /*18 Jump  010101 &*/ jump, // PC <- IM
  /*19 Set on Less Than  010111 &*/ setlt, // se R[SA] < R[SB], então R[DR] <- 1
  /*20 Load  011000 &*/ load, // R[DR] <- M[IM]
  /*21 Store  011001 &*/ store, // M[IM] <- R[SA]
  /*22 Load Imediato  011010 &*/ loadi, // R[DR] <- IM
  /*23 Nop  011011 &*/ noo, // Sem Operação
  /*24 Entrada  011101 &*/ input, // R[DR] <- alavancas
  /*25 HLT  011100 &*/ halt, // Parar Operação
  /*26 Pré Saída  011110 &*/ poutput, // Displays <- R[SA]
  /*27 Saída  100000 &*/ output, // Displays <- R[SA]
  /*28 Load Registrador 1000001*/ loadr, // R[DR] <- M[R[SA]]
  /*29 Store Registrador 100010*/ storer, // M[R[SA]] -> R[DR]
  /*30 Jump Registrador  100011 &*/ jumpr, // PC <- R[SA]
// control types:
  eof,
  help,
  error

}galetype;

typedef struct type_instruction{
  int line;
  int register_a;
  int register_b;
  int register_c;
  int immediate;
  galetype type;
  struct type_instruction *next;
}type_instruction;

typedef struct{
    type_instruction *start;
}list_instructions;

char *decimal_to_binary(int decimal, int lenght);

int count_instructions(list_instructions *instructions_list);

void print_target_code(list_instructions *instructions_list);


#endif
