#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__
#include "Parser.h"

class Interpreter {
	Parser parser;
public:
	Interpreter(Parser arg);

	int visit(Tree *t);
	
	int visit_BinOp(Tree *t, literal type);
	int visit_Num(Tree *t);
	
	int interpret();
};

#endif