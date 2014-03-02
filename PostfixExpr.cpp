// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #3
 * Class Implementation
 * Professor: Robert  Benkoczi
 * Program Name: PostfixExpr.cpp
 * Software Used: Geany
*/
#include "PostfixExpr.h"
#include <iostream>

double PostfixExpr::evaluate(std::string expr)
{
	Tokenizer* tokenizeExpression;
	tokenizeExpression = new Tokenizer();
	bool operatorFound = false;
	int counter = 0;
	double tempValue1, tempValue2;
	double finalValue = 0;
	int temp;
	std::vector<std::string> tokenizedExpression;
	
	checkValidity(expr);
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

void PostfixExpr::checkValidity (std::string expr)
{
	bool errorAlreadyThrown = false;
	int counter = 0;
	int numOfLiterals = 0;
	int numOfOperators = 0;
	
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
				break;
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
				break;
		}	
		counter++;
	}
	
	counter = 0;
	
	if (!errorAlreadyThrown)
	{
		while (counter < expr.length())
		{
			if (expr[counter] == '+' || expr[counter] == '-' || expr[counter] == '*' || expr[counter] == '/')
			{
				counter++;
				numOfOperators++;
			}
			else if (expr[counter] != ' ')
			{
				while (expr[counter] != ' ' && expr[counter] != '+' && expr[counter] != '-' && expr[counter] != '*' && expr[counter] != '/')
					counter++;
				numOfLiterals++;
			}
			else
				counter++;
		}
		
		if (numOfLiterals != numOfOperators + 1)
		{
			throw SyntaxError("Malformed equation. Throwing exception.");
			errorAlreadyThrown = true;
		}
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
}
