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
	
