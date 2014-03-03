// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #3
 * Tokenizer Tester
 * Professor: Robert  Benkoczi
 * Program Name: testTokenizer.cpp
 * Software Used: Geany
*/
#include "TokenizerTestFixture.h"
#include <cppunit/ui/text/TestRunner.h>

int main()
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TokenizerTestFixture::suite());
	runner.run();
	
	return 0;
}
