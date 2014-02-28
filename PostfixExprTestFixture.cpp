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
	std::cout << "Note that the following test fails. I am unsure" << std::endl;
	std::cout << "of why. The values are equivalent to each other" << std:: endl;
	CPPUNIT_ASSERT(testPostfixExpr->evaluate("54.32 58.42 + 68.238 -") == 44.502);
}
