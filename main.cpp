#include "general.h"


using namespace std;

// global variables
int line;

// functions
void insert_instruction(vector<type_instruction> &instructions_list, galetype type, int register_source_a, int register_source_b, int register_target, int immediate){
	// printf("%4d: \ttype: %d \tsource_a: %d \tsource_b: %d \ttarget: %d\n",
	// line_counter, type, register_source_a, register_source_b, register_target);

	type_instruction *new_instruction = new type_instruction;

	new_instruction->line = line;
	new_instruction->register_a = register_source_a;
	new_instruction->register_b = register_source_b;
	new_instruction->register_c = register_target;
	new_instruction->immediate = 0;
	new_instruction->type = type;

	instructions_list.push_back(*new_instruction);
	line++;

}

galetype translate_instruction_name(string instruction_name){
	galetype instruction_type;
	if (instruction_name.compare("add")==0){
		instruction_type = add;
	}else if(instruction_name.compare("addi")==0){
		instruction_type = addi;
	}else if(instruction_name.compare("sub")==0){
		instruction_type = sub;
	}else if(instruction_name.compare("subi")==0){
		instruction_type = subi;
	}else if(instruction_name.compare("times")==0){
		instruction_type = times;
	}else if(instruction_name.compare("over")==0){
		instruction_type = over;
	}else if(instruction_name.compare("incr")==0){
		instruction_type = incr;
	}else if(instruction_name.compare("decr")==0){
		instruction_type = decr;
	}else if(instruction_name.compare("and")==0){
		instruction_type = andg;
	}else if(instruction_name.compare("or")==0){
		instruction_type = org;
	}else if(instruction_name.compare("module")==0){
		instruction_type = module;
	}else if(instruction_name.compare("xor")==0){
		instruction_type = xorg;
	}else if(instruction_name.compare("not")==0){
		instruction_type = notg;
	}else if(instruction_name.compare("shiftl")==0){
		instruction_type = shiftl;
	}else if(instruction_name.compare("shiftr")==0){
		instruction_type = shiftr;
	}else if(instruction_name.compare("pbranch")==0){
		instruction_type = pbranch;
	}else if(instruction_name.compare("branchz")==0){
		instruction_type = branchz;
	}else if(instruction_name.compare("branchn")==0){
		instruction_type = branchn;
	}else if(instruction_name.compare("jump")==0){
		instruction_type = jump;
	}else if(instruction_name.compare("setlt")==0){
		instruction_type = setlt;
	}else if(instruction_name.compare("load")==0){
		instruction_type = load;
	}else if(instruction_name.compare("store")==0){
		instruction_type = store;
	}else if(instruction_name.compare("loadi")==0){
		instruction_type = loadi;
	}else if(instruction_name.compare("noo")==0){
		instruction_type = noo;
	}else if(instruction_name.compare("input")==0){
		instruction_type = input;
	}else if(instruction_name.compare("halt")==0){
		instruction_type = halt;
	}else if(instruction_name.compare("poutput")==0){
		instruction_type = poutput;
	}else if(instruction_name.compare("output")==0){
		instruction_type = output;
	}else if(instruction_name.compare("loadr")==0){
		instruction_type = loadr;
	}else if(instruction_name.compare("storer")==0){
		instruction_type = storer;
	}else if(instruction_name.compare("jumpr")==0){
		instruction_type = jumpr;
	}else if(instruction_name.compare("exit")==0){
		instruction_type = eof;
	}else if(instruction_name.compare("help")==0){
		instruction_type = help;
	}else{
		instruction_type = error;
	}
	return instruction_type;
}

void print_help(){

}


int main(int argc, char const *argv[]) {
	int register_a;
	int register_b;
	int register_c;
	int immediate;
	galetype instruction_type;
	string instruction_name;
	std::vector<type_instruction> instructions_list;

	// initialize variables
	instructions_list.clear();
	line = 0;

	while (1) {
		// initialize variables
		register_a = 0;
		register_b = 0;
		register_c = 0;
		immediate = 0;

		// enter and adequate instruction type
		cin >> instruction_name;
		instruction_type = translate_instruction_name(instruction_name);

		if (instruction_type==eof) {
			break;
		}
		switch (instruction_type) {
			case help:
				print_help();
				break;
			case error:
				cout << "Invalid instruction type. Try again!" << endl;
				break;
			case add:
			case sub:
			case times:
			case over:
			case andg:
			case org:
			case setlt:
				cout << "Enter the first operator register: ";
				cin >> register_a;
				cout << "Enter the second operator register: ";
				cin >> register_b;
				cout << "Enter the result register: ";
				cin >> register_c;
				break;
		}
		insert_instruction(instructions_list, instruction_type, register_a, register_b, register_c, immediate);
	}


  return 0;
}
