// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #3
 * Class Implemenation
 * Professor: Robert  Benkoczi
 * Program Name: TokenizerTestFixture.cpp
 * Software Used: Geany
*/
#include "TokenizerTestFixture.h"

void TokenizerTestFixture::setUp()
{
	tokenizerTester = new Tokenizer();
	tokenizerTester2 = new Tokenizer();
}

void TokenizerTestFixture::tearDown()
{
	delete tokenizerTester;
	delete tokenizerTester2;
}

void TokenizerTestFixture::unionHoldsCorrectValuesWhenAssigned()
{
	Tokenizer::TokenValue tv1(3.6);
	Tokenizer::TokenValue tv2(Tokenizer::OperatorValue::STAR);
	CPPUNIT_ASSERT(tv1.literalVal == 3.6);
	CPPUNIT_ASSERT(tv2.opVal == Tokenizer::OperatorValue::STAR);
}

void TokenizerTestFixture::crtTokenTypeReturnsAccurateReadings()
{
	CPPUNIT_ASSERT(tokenizerTester->crtTokenType("30") == Tokenizer::Tokens::LITERAL);
	CPPUNIT_ASSERT(tokenizerTester->crtTokenType("+") == Tokenizer::Tokens::OPERATOR);
}

void TokenizerTestFixture::crtTokenValueReturnsAccurate()
{
	CPPUNIT_ASSERT(tokenizerTester->crtTokenValue("8.6").literalVal == 8.6);
	CPPUNIT_ASSERT(tokenizerTester->crtTokenValue("+").opVal == Tokenizer::OperatorValue::PLUS);
}

void TokenizerTestFixture::parseKnowsWhatFirstTokenIsInString()
{
	CPPUNIT_ASSERT(tokenizerTester->parse("10 4 +")[0] == "10");
}

void TokenizerTestFixture::nextTokenIsDeterimedAfterFirstToken()
{
	CPPUNIT_ASSERT(tokenizerTester2->parse("10 4 +")[1] == "4");
}

void TokenizerTestFixture::tokenizerSuccessfullyBreaksTokensDown()
{
	std::vector<std::string> testVector = tokenizerTester->parse("13 15 + 39 -");
	
	CPPUNIT_ASSERT(testVector[0] == "13");
	CPPUNIT_ASSERT(testVector[1] == "15");
	CPPUNIT_ASSERT(testVector[2] == "+");
	CPPUNIT_ASSERT(testVector[3] == "39");
	CPPUNIT_ASSERT(testVector[4] == "-");
}

void TokenizerTestFixture::tokenizerParsesFloatingPointCorrectly()
{
	std::vector<std::string> testVector = tokenizerTester2->parse("28.7563 2736.33802 +");
	
	CPPUNIT_ASSERT(testVector[0] == "28.7563");
	CPPUNIT_ASSERT(testVector[1] == "2736.33802");
}
