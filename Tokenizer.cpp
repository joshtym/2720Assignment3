#include "Tokenizer.h"
#include <iostream>

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
	// Obvoiusly not the final result
	return Tokens::LITERAL;
}

Tokenizer::TokenValue Tokenizer::crtTokenValue(const std::string str)
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

int Tokenizer::nextToken(const std::string str, int startingPos)
{
}
