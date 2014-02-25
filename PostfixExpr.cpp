#include "PostfixExpr.h"
#include <iostream>

double PostfixExpr::evaluate(std::string expr)
{
	std::cout << "Test" << std::endl;
	int i = 0;
	
	while (i < expr.length() - 1)
		i++;
	
	switch(expr[i])
	{
		case '+':
			break;
		case '*':
			break;
		case '-':
			break;
		case ')':
			break;
		default:
			throw SyntaxError("Malformed equation. Throwing exception.");
	}
}
