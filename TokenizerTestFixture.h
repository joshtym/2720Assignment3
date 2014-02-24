#ifndef TOKENIZERTESTFIXTURE_H
#define TOKENIZERTESTFIXUTRE_H

#include "Tokenizer.h"
#include <cppunit/extensions/HelperMacros.h>

class TokenizerTestFixture : public CppUnit::TestFixture
{
	private:
		Tokenizer *newTokenizer;
	public:
		CPPUNIT_TEST_SUITE(TokenizerTestFixture);
		CPPUNIT_TEST_SUITE_END();
		
	public:
		void setUp();
		void tearDown();
		
};

#endif
