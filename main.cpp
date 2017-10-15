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
	new_instruction->immediate = immediate;
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
	}else{
		instruction_type = error;
	}
	return instruction_type;
}


int main(int argc, char const *argv[]) {
	int register_a;
	int register_b;
	int register_c;
	int immediate;
	string content;
	galetype instruction_type;
	string instruction_name;
	string file_name;
	std::vector<type_instruction> instructions_list;
	int content_specifier;

	// cout << "Enter the name of the entry file: ";
	// cin >> file_name;
	file_name = "entry.txt";

	ifstream entry_file(file_name);
  if (entry_file.is_open()){
		// initialize variables
		instructions_list.clear();
		line = 0;
		while (getline(entry_file, content)) {
			std::stringstream ss(content);
			content_specifier = 0;

			// initialize variables
			register_a = 0;
			register_b = 0;
			register_c = 0;
			immediate = 0;
			while (getline(ss, content, ' ')) {
				switch (content_specifier) {
					case 0:
						instruction_name = content;
						instruction_type = translate_instruction_name(instruction_name);
						content_specifier++;
						break;
					case 1:
						register_a = stoi(content);
						content_specifier++;
						break;
					case 2:
						register_b = stoi(content);
						content_specifier++;
						break;
					case 3:
						register_c = stoi(content);
						content_specifier++;
						break;
					case 4:
						immediate = stoi(content);
						content_specifier++;
						break;
				}
			}
			insert_instruction(instructions_list, instruction_type, register_a, register_b, register_c, immediate);
		}
    entry_file.close();
  }
  else cout << "Unable to open file";

	print_target_code(instructions_list);

  return 0;
}
