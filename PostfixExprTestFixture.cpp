// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #3
 * Class Implementation
 * Professor: Robert  Benkoczi
 * Program Name: PostfixExprTestFixture.cpp
 * Software Used: Geany
*/
#include "PostfixExprTestFixture.h"
#include <iostream>

void PostfixExprTestFixture::setUp()
{
	testPostfixExpr = new PostfixExpr();
}

void PostfixExprTestFixture::tearDown()
{
	delete testPostfixExpr;
}

void PostfixExprTestFixture::throwsSyntaxErrorIfMalformed()
{
	testPostfixExpr->evaluate("10+4");
}

void PostfixExprTestFixture::throwsLexicalErrorIfInvalidChar()
{
	testPostfixExpr->evaluate("a+b");
}

void PostfixExprTestFixture::evaluateCorrectlyEvaluates()
{
	std::cout << "****************************************************";
	std::cout << std::endl;
	std::cout << "Note that the following test fails. I am unsure"
			  << std::endl;
	std::cout << "of why. The values are equivalent to each other" 
			  << std::endl;
	std::cout << "Here's the value evaluate(54.32 58.42 + 68.238)"
		      << std::endl;
	std::cout << testPostfixExpr->evaluate("54.32 58.42 + 68.238 -")
			  << std::endl;
	CPPUNIT_ASSERT(testPostfixExpr->evaluate("54.32 58.42 + 68.238 -") == 44.502);
}
