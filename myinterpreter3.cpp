#include<iostream>
#include<cctype>
#include<string>
#include<sstream>

#define INTEGER "INTEGER"
#define PLUS "PLUS"
#define EOF "EOF"
#define MINUS "MINUS"

using namespace std;

class Token
{
	string type;
	char value;
public:
	Token()
	{
		this->type = "";
	}
	Token(string typeP,char valueP)
	{
      this->type = typeP;
      this->value = valueP;
	}
	char get_value()
	{
		return this->value;
	}
	string get_type()
	{
		return this->type; 
	}
};

class Interpreter
{
	string Text;
	int Pos;
	Token current_token;
	char current_char;
public:
	Interpreter(string TextP)
	{
       this->Text = TextP;
       this->Pos = 0;
       this->current_char = this->Text.at(this->Pos); 
	}
	void advance()
	{
		this->Pos++;
		if(this->Pos > this->Text.length()-1)
		{
			this->current_char = '\0';
		}
		else
		{
			this->current_char = this->Text.at(this->Pos);
		}
	}
	void skip_whitespace()
	{ 
	    while(this->current_char != '\0' && isspace(this->current_char))
	    {
	    	this->advance();
	    }

	}
	int integer()
	{
		string result = "";
		while(this->current_char != '\0' && isdigit(this->current_char))
		{
			result += this->current_char;
			this->advance();
		}
		return stoi(result);
	}
	void error()
	{
		throw "Error parsing input";
		return;
	}
	Token get_next_token()
	{

      while(this->current_char != '\0')
      {
		if(isspace(this->current_char))
		{
			this->skip_whitespace();
			continue;
		}
		
		if(isdigit(this->current_char))
		{
			return Token(INTEGER,this->integer());
		}
		if(this->current_char == '+')
		{
			this->advance();
            return Token(PLUS,(int)current_char);
		}
		if(this->current_char == '-')
		{    
			this->advance();
			return Token(MINUS,(int)current_char);
		}
	  }
	}
	void eat(string token_type)
	{
		if(this->current_token.get_type() == token_type)
		{
			this->current_token = this->get_next_token();
		}
		else
		{
			this->error();
		}
		return;
	}
	char term()
	{
      Token token = this->current_token;
      this->eat(INTEGER);
      return token.get_value();
	}
	int expr()
	{
		this->current_token = this->get_next_token();

		int result = this->term();
		
		while(this->current_token.get_type() == PLUS || this->current_token.get_type() == MINUS)
		{
           Token token = this->current_token;

           if(token.get_type() == PLUS)
           {
           	this->eat(PLUS);
           	result += this->term();
           }
           else if(token.get_type() == MINUS)
           {
           	this->eat(MINUS);
           	result -= this->term();
           }
		}

		return result;

	}
};

int main()
{
	while(1)
	{
		
			string text;
			cout<<"Calcgo> ";
			getline(cin,text,'\n');

			Interpreter interpreter(text);

            int result = interpreter.expr();

            cout<<result<<endl;
	}
	return 0;
}