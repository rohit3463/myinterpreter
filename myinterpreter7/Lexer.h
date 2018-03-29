#ifndef __LEXER_H__
#define __LEXER_H__

class Lexer
{
	std::string text;
	int pos;
	char current_char;

public:
	Lexer(std::string text);
	void error();

	void skip_whitespace();

	int get_integer();

	void advance();

	Token get_next_token();
};

#endif