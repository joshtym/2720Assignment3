#ifndef TOKENIZERTESTFIXTURE_H
#define TOKENIZERTESTFIXUTRE_H

#include "Tokenizer.h"
#include <cppunit/extensions/HelperMacros.h>

class TokenizerTestFixture : public CppUnit::TestFixture
{
	private:
		Tokenizer *tokenizerTester;
		Tokenizer *tokenizerTester2;
		
	public:
		void setUp();
		void tearDown();
		void unionHoldsCorrectValuesWhenAssigned();
		
	public:
		CPPUNIT_TEST_SUITE(TokenizerTestFixture);
		CPPUNIT_TEST(unionHoldsCorrectValuesWhenAssigned);
		CPPUNIT_TEST_SUITE_END();	
};

#endif
