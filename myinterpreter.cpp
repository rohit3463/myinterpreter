#include<iostream>
#include<cctype>
#include<string>

#define INTEGER "INTEGER"
#define PLUS "PLUS"
#define EOF "EOF"

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
public:
	Interpreter(string TextP)
	{
       this->Text = TextP;
       this->Pos = 0;
	}
	void error()
	{
		throw "Error parsing input";
		return;
	}
	Token get_next_token()
	{
		string text = this->Text;

		if(this->Pos > (text.length()-1))
		{
          return Token(EOF,'\0');
		}

		char current_char = text.at(this->Pos);

		if(isdigit(current_char))
		{
			this->Pos++;
			return Token(INTEGER,current_char);
		}
		if(current_char == '+')
		{
			this->Pos++;
            return Token(PLUS,current_char);
		}
		if(current_char == ' ')
		{    
			this->Pos++;
			this->get_next_token();
		}
		this->error();
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
	int expr()
	{
		this->current_token = this->get_next_token();

		Token left = this->current_token;
         
        this->eat(INTEGER);
        
        Token op = this->current_token;

        this->eat(PLUS);

        Token right = this->current_token;

        this->eat(INTEGER);

        int result = left.get_value() - '0' + right.get_value() - '0' ;

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