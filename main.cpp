#include "general.h"


using namespace std;

//insertion function for variables
// void insert_variable(list_variables *variables_list, int index, int index_array, kind_variable kind, char id[], char scope[]){
// 	type_variable *p = variables_list->start;
// 	type_variable *new_variable = malloc(sizeof(type_variable));
//
// 	new_variable->index = index;
// 	new_variable->index_array = index_array;
// 	new_variable->kind = kind;
// 	strcpy(new_variable->scope, scope);
// 	strcpy(new_variable->id, id);
//
// 	if(p==NULL){
// 		variables_list->start = new_variable;
// 		variables_list->start->next = NULL;
// 	}
// 	else{
// 		while(p->next!=NULL){
// 			p = p->next;
// 		}
// 		p->next = new_variable;
// 		p->next->next = NULL;
// 	}
// }

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


int main(int argc, char const *argv[]) {
	int line;
	line = 0;
	std::vector<type_instruction> instructions_list;
	instructions_list.clear();
	galetype instruction_type;
	string instruction_name;


	while (1) {
		cin >> instruction_name;
		instruction_type = translate_instruction_name(instruction_name);

		if (instruction_type==eof) {
			break;
		}
	}


  return 0;
}
