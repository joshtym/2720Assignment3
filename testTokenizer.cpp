#include "Tokenizer.h"
#include "TokenizerTestFixture.h"
#include <cppunit/ui/text/TestRunner.h>

int main()
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TokenizerTestFixture::suite());
	runner.run();
	
	return 0;
}
