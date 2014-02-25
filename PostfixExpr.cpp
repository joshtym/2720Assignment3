#include "PostfixExpr.h"
#include <iostream>

int PostfixExpr::tester = 0;

double PostfixExpr::evaluate(std::string expr)
{
	std::cout << tester << std::endl;
	int i = 0;
	bool errorAlreadyThrown = false;
	
	while (i < expr.length() - 1)	
		i++;
		
	tester++;
	if (tester == 1)
		switch(expr[i])
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
