#ifndef __TOKEN_H__
#define __TOKEN_H__

enum literal {PLUS,MINUS,DIV,MUL,EOFE,LPAREN,RPAREN,INTEGER}

class Token
{
	int value;
	literal type;

public:
	Token(literal type,int value);

	literal get_type();
	int get_value();

};
#endif