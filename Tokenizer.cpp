// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #3
 * Class Implementation
 * Professor: Robert  Benkoczi
 * Program Name: Tokenizer.cpp
 * Software Used: Geany
*/
#include "Tokenizer.h"
#include <cmath>

std::vector<std::string> Tokenizer::parse(const std::string str)
{
	// Current Variable Declaratoins. Set both delimiters to 0
	int nextDelimiter, currentDelimiter;
	currentDelimiter = 0;
	nextDelimiter = 0;
	std::vector<std::string> expression;
	
	// Loop through until end of expression
	while (nextDelimiter < str.length() && currentDelimiter < str.length())
	{
		// Using the nextToken function, determine the value of the
		// position of the next delimiter
		nextDelimiter = nextToken(str, currentDelimiter);
		
		// Once the token is located, push it onto the vector
		expression.push_back(str.substr(currentDelimiter, nextDelimiter-currentDelimiter));
		
		// Assign currentDelimiter to start from nextDelimiter
		currentDelimiter = nextDelimiter;
		
		// Ensure that the delimiter for the next round doesn't
		// start on white space
		if (delimiterIsSpace)
			while (str[currentDelimiter] == ' ')
				currentDelimiter++;			
	}
	
	return expression;
}

Tokenizer::Tokens Tokenizer::crtTokenType(const std::string str)
{
	// Pretty self explanatory. If the value equates to one of the known
	// operators, return it as an operator. Etc. etc
	if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
		return Tokens::OPERATOR;
	else if (str[0] == '\n')
		return Tokens::THEEND;
	else if (str[0] == '0' || str[0] == '1' || str[0] == '2' || 
			  str[0] == '3' || str[0] == '4' || str[0] == '5' || 
			  str[0] == '6' || str[0] == '7' || str[0] == '8' || 
			  str[0] == '9')
		return Tokens::LITERAL;
	else
		return Tokens::UNKNOWN;
}

Tokenizer::TokenValue Tokenizer::crtTokenValue(const std::string str)
{
	// If the value is an operator, then loop through each operator
	// to determine which one it is and return that value. Ife not,
	// return a TokenValue with the converted string to double
	if (crtTokenType(str) == Tokens::OPERATOR)
	{
		if (str[0] == '+')
			return TokenValue(OperatorValue::PLUS);
		else if (str[0] == '-')
			return TokenValue(OperatorValue::MINUS);
		else if (str[0] == '*')
			return TokenValue(OperatorValue::STAR);
		else
			return TokenValue(OperatorValue::SLASH);
	}
	else if (crtTokenType(str) == Tokens::LITERAL)
		return TokenValue(convertStringToDouble(str));
	else
		return TokenValue();
	
	
}

double Tokenizer::convertStringToDouble(const std::string str)
{
	bool isFloatingPoint = false;
	
	double value = 0;
	int decimalIndex = str.length();
	int tracker = 1;
	
	for (int i = 0; i < decimalIndex; i++)
	{
		// Find the non-decimal part of the number and create it
		switch (str[i])
		{
			case '0':
				value = value * 10;
				break;
			case '1':
				value = value * 10 + 1;
				break;
			case '2':
				value = value * 10 + 2;
				break;
			case '3':
				value = value * 10 + 3;
				break;
			case '4':
				value = value * 10 + 4;
				break;
			case '5':
				value = value * 10 + 5;
				break;
			case '6':
				value = value * 10 + 6;
				break;
			case '7':
				value = value * 10 + 7;
				break;
			case '8':
				value = value * 10 + 8;
				break;
			case '9':
				value = value * 10 + 9;
			case '.':
				decimalIndex = i;
				isFloatingPoint = true;
				break;
			default:
				break;
		}
	}
	
	// Only take action if the number is a floating point. Using
	// the power function, we can ensure that the value is kept
	// accurate to what the string is
	if (isFloatingPoint)
	{
		for (int j = decimalIndex + 1; j < str.length(); j++)
		{
			switch (str[j])
			{
				case '1':
					value = value + (1 / (pow(10, tracker)));
					tracker++;
					break;
				case '2':
					value = value + (2 / (pow(10, tracker)));
					tracker++;
					break;
				case '3':
					value = value + (3 / (pow(10, tracker)));
					tracker++;
					break;
				case '4':
					value = value + (4 / (pow(10, tracker)));
					tracker++;
					break;
				case '5':
					value = value + (5 / (pow(10, tracker)));
					tracker++;
					break;
				case '6':
					value = value + (6 / (pow(10, tracker)));
					tracker++;
					break;
				case '7':
					value = value + (7 / (pow(10, tracker)));
					tracker++;
					break;
				case '8':
					value = value + (8 / (pow(10, tracker)));
					tracker++;
					break;
				case '9':
					value = value + (9 / (pow(10, tracker)));
					tracker++;
					break;
				default:
					tracker++;
					break;
			}
		}
	}
	
	return value;			
}

int Tokenizer::nextToken(const std::string str, int startingPos)
{
	bool valueIsNum, valueIsOperator;
	
	// Determine whether the value is an operator or a number
	switch(str[startingPos])
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
			valueIsNum = true;
			valueIsOperator = false;
			break;
		case '+':
		case '-':
		case '/':
		case '*':
			valueIsNum = false;
			valueIsOperator = true;
			break;
		default:
			valueIsNum = false;
			valueIsOperator = false;
			break;
	}
	
	// If it's a number, loop through until we reach a delimiter
	if (valueIsNum)
		while (str[startingPos] != ' ' && str[startingPos] != '+' && 
				str[startingPos] != '-' && str[startingPos] != '*' && 
				str[startingPos] != '/' && startingPos < str.length())
				{
					startingPos++;
				}
	else if(valueIsOperator)
		startingPos++;
	
	// Check to ensure we don't get an invalid statement
	if (startingPos < str.length() && str[startingPos] == ' ')
		delimiterIsSpace = true;
	else
		delimiterIsSpace = false;
		
	return startingPos;	
}
