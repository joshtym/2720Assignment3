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

double PostfixExpr::evaluate(std::string expr)
{
	// Variable Declarations
	Tokenizer* tokenizeExpression;
	tokenizeExpression = new Tokenizer();
	bool operatorFound = false;
	int counter = 0;
	double tempValue1, tempValue2;
	double finalValue = 0;
	int temp;
	std::vector<std::string> tokenizedExpression;
	
	// Using the helper function, ensure the string maintains
	// validity
	checkValidity(expr);
	
	// Tokenize Expression
	tokenizedExpression = tokenizeExpression->parse(expr);
	
	// The meat of this function. Takes tokenized expression and
	// evaluates it successfully
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
			// This is feasable because we've already checked the validity of the string
			while (tokenizeExpression->crtTokenType(tokenizedExpression[temp]) != Tokenizer::Tokens::LITERAL)
				temp--;
			
			// We essentially go through until we fine an operator, then, we go backwards two numbers and
			// evaluate those two numbers with said operator. Once that is evaluated, whatever was in that
			// position is replaced by an "impossible" character, denoted 'a' in this case, so that is is
			// skipped over next time.
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
			
			// Convert back to string so that it can be placed back
			// inside the vector for use
			tokenizedExpression[counter] = std::to_string(finalValue);
		}
		counter++;
	}
	
	// Deallocate allocated memory
	delete tokenizeExpression;
	
	return finalValue;	
}

void PostfixExpr::checkValidity (std::string expr)
{
	// Variable Declarations
	bool errorAlreadyThrown = false;
	int counter = 0;
	int numOfLiterals = 0;
	int numOfOperators = 0;
	
	// Loop through the given expression and toss back an exception
	// if an invalid character is found
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
	// Continue on if we haven't already thrown an error
	if (!errorAlreadyThrown)
	{
		// Loop through and count the number of operators and literals
		// that exist in the 
		while (counter < expr.length())
		{
			if (expr[counter] == '+' || expr[counter] == '-' || 
				expr[counter] == '*' || expr[counter] == '/')
			{
				counter++;
				numOfOperators++;
			}
			else if (expr[counter] != ' ')
			{
				while (expr[counter] != ' ' && expr[counter] != '+' && 
						expr[counter] != '-' && expr[counter] != '*' && 
						expr[counter] != '/' && expr[counter] != '\n')
						{
							counter++;
							if (!(counter + 1 < expr.length()))
								break;
						}
					numOfLiterals++;
			}
			else
				counter++;
		}
		
		// In any equation, the number of operators has to be one
		// less than the number of literals or it's malformed
		if (numOfLiterals != numOfOperators + 1)
		{
			throw SyntaxError("Malformed equation. Throwing exception.");
			errorAlreadyThrown = true;
		}
	}
	counter = 0;
	// Contine onward if no error has been thrown
	if (!errorAlreadyThrown)
	{
		// Ensure that the first value is a number. If not,
		// it is malformed
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
		
		// Ensure that the last value is to be an operator. If it is
		// not, then it is malformed
		// not, then it is malformed
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
