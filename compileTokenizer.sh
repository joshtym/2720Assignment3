#!/bin/bash
g++ -std=c++11 -c -o Tokenizer.o Tokenizer.cpp
g++ -std=c++11 -c -o TokenizerTestFixture.o TokenizerTestFixture.cpp
g++ -std=c++11 -c -o testTokenizer.o testTokenizer.cpp
g++ -std=c++11 -std=c++11 -L /usr/lib -o tokenizerTester Tokenizer.o TokenizerTestFixture.o testTokenizer.o -lcppunit -ldl
