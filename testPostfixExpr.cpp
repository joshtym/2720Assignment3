#include "PostfixExpr.h"
#include "PostfixExprTestFixture.h"
#include <cppunit/ui/text/TestRunner.h>

int main()
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(PostfixExprTestFixture::suite());
	runner.run();
	
	return 0;
}
