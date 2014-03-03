// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #3
 * PostfixExpr Tester main
 * Professor: Robert  Benkoczi
 * Program Name: testPostfixExpr.cpp
 * Software Used: Geany
*/
#include "PostfixExprTestFixture.h"
#include <cppunit/ui/text/TestRunner.h>

int main()
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(PostfixExprTestFixture::suite());
	runner.run();
	
	return 0;
}
