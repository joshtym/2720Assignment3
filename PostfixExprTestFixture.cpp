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
	CPPUNIT_ASSERT(testPostfixExpr->evaluate("54.32 58.42 + 68.238 -") == 44.502);
}
