#ifndef __PARSER_H__
#define __PARSER_H__

#include "Lexer.h"

class Tree
{
public:
	Token token;
	Tree *left,*right;

	Tree(Token arg);

	Tree(Tree *left,Token arg,Tree *right);
};

class Parser
{
	Lexer lexer;

	Token current_token;

public:
	Parser(Lexer arg);

	void error();

	void eat(literal type);

	Tree *term();

	Tree *factor();

	Tree *expr();

	Tree *parse();
};

#endif