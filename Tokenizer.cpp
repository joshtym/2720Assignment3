#include "Tokenizer.h"
#include <iostream>
#include <cmath>

int Tokenizer::count = 0;

std::vector<std::string> Tokenizer::parse(const std::string str)
{
	int nextDelimiter, currentDelimiter;
	currentDelimiter = 0;
	std::vector<std::string> expression;
	
	bool endOfTokenReached = false;
	while (nextDelimiter < str.length())
	{
		nextDelimiter = nextToken(str, currentDelimitor);
		expressoin.push_back(str.substr(currentDelimitor, nextDelimiter-currentDelimiter));
		currentDelimiter = nextDelimiter;
		
	}
}

Tokenizer::Tokens Tokenizer::crtTokenType(const std::string str)
{
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
	else if (crtTokenType(str) == Tokens::UNKNOWN);
		return TokenValue();
	else
		return TokenValue();
	
	
}

double Tokenizer::convertStringToDouble(const std::string str)
{
	isFloatingPoint = false;
	
	double value = 0;
	int decimalIndex = str.length();
	int tracker = 1;
	
	for (int i = 0; i < decimalIndex; i++)
	{
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
				isFloatingNumber = true;
				break;
			default:
				break;
		}
	}
	
	if (isFloatingNumber)
	{
		for (int j = decimalIndex + 1; j < str.length(); j++)
		{
			switch (str[i])
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
	
	return value;			
}

int Tokenizer::nextToken(const std::string str, int startingPos)
{
}
