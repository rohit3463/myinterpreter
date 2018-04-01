#include <iostream>
#include "Interpreter.h"

int main(){
	std:: string input;
	int result;
	while(1){
		std::cout<<"Calcgo> ";
		getline(std::cin, input, '\n');

		if(input == "exit" || input=="quit") {
			std::cout<<"Bye!\n";
			return 0;
		}

		Lexer lexer(input);
		Parser parser(lexer);
		Interpreter interpreter(parser);
		int result = interpreter.interpret();

		std::cout<<result<<std::endl;
	}

	return 0;
}