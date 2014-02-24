#include "TokenizerTestFixture.h"

void TokenizerTestFixture::setUp()
{
	newTokenizer = new Tokenizer();
}

void TokenizerTestFixture::tearDown()
{
	delete newTokenizer;
}
