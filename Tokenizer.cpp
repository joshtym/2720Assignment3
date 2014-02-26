#include "Tokenizer.h"
#include <iostream>

int Tokenizer::count = 0;

void Tokenizer::parse(const std::string str)
{
				
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
