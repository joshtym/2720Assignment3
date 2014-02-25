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
