#include "Token.h"

Token::Token(literal type,int value)
{
	this->value = value;
	this->type = type;
}

literal Token::get_type()
{
	return this->type;
}

int Token::get_value()
{
	return this->value;
}