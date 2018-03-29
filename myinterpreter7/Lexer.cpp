#include <stdexcept>
#include <cctype>
#include <string>
#include "Token.h"
#include "Lexer.h"

Lexer::Lexer(std::string text)
{
	this->text = text;
	this->pos = 0;
	this->current_char = this->text.at(this->pos);
}

void Lexer::error()
{
	throw std::invalid_argument("Error parsing input");
}

void Lexer::advance()
{
	this->pos++;
	if(this->pos > this->text.length()-1)
		this->current_char = '\0';
	else
		this->current_char = this->text.at(this->pos);
}

void Lexer::skip_whitespace()
{
	while(this->current_char!='\0' && this->current_char == ' ')
	{
		this->advance();
	}
}

int Lexer::get_integer()
{	
	std::string result="";
	while(this->current_char!='\0' && isdigit(this->current_char))
	{
		result += this->current;
		this->advance();
	}
	return stoi(result);
}

Token Lexer::get_next_token()
{
	while(this->current_char() != '\0')
	{
		if(isspace(this->current_char))
		{
			this->skip_whitespace();
			continue;
		}
		if(this->current_char == '+')
		{
			this->advance();
			return Token(PLUS,(int)'+');
		}
		if(this->current_char == '-')
		{
			this->advance();
			return Token(MINUS,(int)'-');
		}
		if(this->current_char == '/')
		{
			this->advance();
			return Token(DIV,(int)'/');
		}
		if(this->current_char == '*')
		{
			this->advance();
			return Token(MUL,(int)'*');
		}
		if(this->current_char == '(')
		{
			this->advance();
			return Token(LPAREN,(int)'(');
		}
		if(this->current_char == ')')
		{
			this->advance();
			return Token(RPAREN,(int)')');
		}

		this->error();
	}
	return Token(EOFE,(int)'\0')
}