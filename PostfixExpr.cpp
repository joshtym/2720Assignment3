#include "PostfixExpr.h"
#include <iostream>

double PostfixExpr::evaluate(std::string expr)
{
	bool errorAlreadyThrown = false;
	int counter = 0;
	while (counter < expr.length() - 1)
	{
		switch (expr[counter])
		{
			case '0': 
			case '1': 
			case '2': 
			case '3': 
			case '4': 
			case '5': 
			case '6': 
			case '7': 
			case '8': 
			case '9': 
			case '+': 
			case '-': 
			case '*': 
			case '/': 
			case ' ':
				break;
			default:
				throw LexicalError("Invalid character detected. Throwing exception.");
				errorAlreadyThrown = true;
		}	
		counter++;
	}
		
	if (!errorAlreadyThrown)
		switch(expr[counter])
		{
			case '+':
				break;
			case '*':
				break;
			case '-':
				break;
			case '/':
				break;
			default:
				throw SyntaxError("Malformed equation. Throwing exception.");
		}	
}
