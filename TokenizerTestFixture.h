// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #3
 * Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: TokenizerTestFixture.h
 * Software Used: Geany
*/
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
		void crtTokenTypeReturnsAccurateReadings();
		void crtTokenValueReturnsAccurate();
		void parseKnowsWhatFirstTokenIsInString();
		void nextTokenIsDeterimedAfterFirstToken();
		void tokenizerSuccessfullyBreaksTokensDown();
		void tokenizerParsesFloatingPointCorrectly();
		
	public:
		CPPUNIT_TEST_SUITE(TokenizerTestFixture);
		CPPUNIT_TEST(unionHoldsCorrectValuesWhenAssigned);
		CPPUNIT_TEST(crtTokenTypeReturnsAccurateReadings);
		CPPUNIT_TEST(crtTokenValueReturnsAccurate);
		CPPUNIT_TEST(parseKnowsWhatFirstTokenIsInString);
		CPPUNIT_TEST(nextTokenIsDeterimedAfterFirstToken);
		CPPUNIT_TEST(tokenizerSuccessfullyBreaksTokensDown);
		CPPUNIT_TEST(tokenizerParsesFloatingPointCorrectly);
		CPPUNIT_TEST_SUITE_END();	
};

#endif
