#include "PostfixExpr.h"
#include <iostream>

double PostfixExpr::evaluate(std::string expr)
{
	Tokenizer* tokenizeExpression;
	tokenizeExpression = new Tokenizer();
	bool errorAlreadyThrown = false;
	bool operatorFound = false;
	int counter = 0;
	double tempValue1, tempValue2;
	double finalValue = 0;
	
	while (counter < expr.length())
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
			case '.': 
			case ' ':
				break;
			default:
				throw LexicalError("Invalid character detected. Throwing exception.");
				errorAlreadyThrown = true;
		}	
		counter++;
	}
	
	counter = 0;
	if (!errorAlreadyThrown)
	{	
		switch(expr[counter])
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
				break;
			default:
				throw SyntaxError("Malformed equation. Throwing exception.");
				errorAlreadyThrown = true;
		}
		
		counter = expr.length() - 1;
		
		switch(expr[counter])
		{
			case '+':
			case '-':
			case '*':
			case '/':
				break;
			default:
				throw SyntaxError("Malformed equation. Throwing exception.");
		}
	}
	
	counter = 0;
	int temp;
	std::vector<std::string> tokenizedExpression;
	
	tokenizedExpression = tokenizeExpression->parse(expr);
	
	while (counter < tokenizedExpression.size())
	{
		operatorFound = false;

		if (tokenizeExpression->crtTokenType(tokenizedExpression[counter]) == Tokenizer::Tokens::OPERATOR)
			operatorFound = true;
		while (!operatorFound && counter < tokenizedExpression.size())
		{
			counter++;
			if (tokenizeExpression->crtTokenType(tokenizedExpression[counter]) == Tokenizer::Tokens::OPERATOR)
				operatorFound = true;
		}
		
		temp = counter;
		
		if (operatorFound)
		{
			while (tokenizeExpression->crtTokenType(tokenizedExpression[temp]) != Tokenizer::Tokens::LITERAL)
				temp--;
			
			tempValue1 = tokenizeExpression->crtTokenValue(tokenizedExpression[temp]).literalVal;
			tokenizedExpression[temp] = "a";
			
			while(tokenizeExpression->crtTokenType(tokenizedExpression[temp]) != Tokenizer::Tokens::LITERAL)
				temp--;
			
			tempValue2 = tokenizeExpression->crtTokenValue(tokenizedExpression[temp]).literalVal;
			tokenizedExpression[temp] = "a";
			
			if (tokenizedExpression[counter] == "+")
				finalValue = tempValue2 + tempValue1;
			else if (tokenizedExpression[counter] == "-")
				finalValue = tempValue2 - tempValue1;
			else if (tokenizedExpression[counter] == "*")
				finalValue = tempValue2 * tempValue1;
			else
				finalValue = tempValue2 / tempValue1;
			
			tokenizedExpression[counter] = std::to_string(finalValue);
		}
		counter++;
	}
	
	delete tokenizeExpression;
	
	return finalValue;	
}
