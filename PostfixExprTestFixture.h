#ifndef POSTFIXEXPRTESTFIXTURE_H
#define POSTFIXEXPRTESTFIXTURE_H

#include "PostfixExpr.h"
#include <cppunit/extensions/HelperMacros.h>

class PostfixExprTestFixture : public CppUnit::TestFixture
{
	private:
		PostfixExpr *testPostfixExpr;
		
	public:
		void setUp();
		void tearDown();
		void throwsSyntaxErrorIfMalformed();
		void throwsLexicalErrorIfInvalidChar();
		void evaluateCorrectlyEvaluates();
	
	public:
		CPPUNIT_TEST_SUITE(PostfixExprTestFixture);
		CPPUNIT_TEST_EXCEPTION(throwsSyntaxErrorIfMalformed, SyntaxError);
		CPPUNIT_TEST_EXCEPTION(throwsLexicalErrorIfInvalidChar, LexicalError);
		CPPUNIT_TEST(evaluateCorrectlyEvaluates);
		CPPUNIT_TEST_SUITE_END();
		
};

#endif
