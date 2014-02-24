#include "PostfixExprTestFixture.h"
#include "exceptions.h"
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
}
