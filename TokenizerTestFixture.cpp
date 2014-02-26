#include "TokenizerTestFixture.h"
#include <iostream>

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
	CPPUNIT_ASSERT(tokenizerTester->crtTokenType() == Tokenizer::Tokens::LITERAL);
}

void TokenizerTestFixture::crtTokenValueReturnsAccurate()
{
	CPPUNIT_ASSERT(tokenizerTester->crtTokenValue().literalVal == 8.6);
	CPPUNIT_ASSERT(tokenizerTester2->crtTokenValue().opVal == Tokenizer::OperatorValue::PLUS);
}

void TokenizerTestFixture::parseKnowsWhatFirstTokenIsInString()
{
	tokenizerTester->parse("10 4 +");
	CPPUNIT_ASSERT(tokenizerTester->newTokenValues.literalVal == 10);
}

void TokenizerTestFixture::nextTokenIsDeterimedAfterFirstToken()
{
	tokenizerTester->parse("10 4 +");
	CPPUNIT_ASSERT(tokenizerTester->newTokenValues.literalVal == 4);
}
