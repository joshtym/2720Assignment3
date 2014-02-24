#ifndef POSTFIXEXPRTESTFIXTURE_H
#define POSTFIXEXPRTESTFIXTURE_H

#include "PostfixExpr.h"
#include <cppunit/extensions/HelperMacros.h>

class PostfixExprTestFixture : public CppUnit::TestFixture
{
	private:
	
	public:
		CPPUNIT_TEST_SUITE(PostfixExprTestFixture);
		CPPUNIT_TEST_SUIT_END();
		
	public:
		void setUp();
		void tearDown();
		
};

#endif
