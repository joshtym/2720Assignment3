#include "Tokenizer.h"
#include <iostream>

int Tokenizer::count = 0;

void Tokenizer::parse(const std::string str)
{
	int i = 0;
	double val = 0;
	bool endOfTokenReached = false;
	while (i < str.length() && !endOfTokenReached)
	{
		switch (str[i])
		{
			case '0':
				val = 10 * val + 0;
				break;
			case '1':
				val = 10 * val + 1;
				break;
			case '2':
				val = 10 * val + 2;
				break;
			case '3':
				val = 10 * val + 3;
				break;
			case '4':
				val = 10 * val + 4;
				break;
			case '5':
				val = 10 * val + 5;
				break;
			case '6':
				val = 10 * val + 6;
				break;
			case '7':
				val = 10 * val + 7;
				break;
			case '8':
				val = 10 * val + 8;
				break;
			case '9':
				val = 10 * val + 9;
				break;
			default:
				endOfTokenReached = true;
				break;
		}
		i++;
	}
	newTokenValues.literalVal = val;
}

Tokenizer::Tokens Tokenizer::crtTokenType()
{
	// Obvoiusly not the final result
	return Tokens::LITERAL;
}

Tokenizer::TokenValue Tokenizer::crtTokenValue()
{
	TokenValue tv1(8.6);
	TokenValue tv2(OperatorValue::PLUS);
	
	if (count == 0)
	{
		count++;
		return tv1;
	}
	
	return tv2;
}

void Tokenizer::nextToken()
{
}
