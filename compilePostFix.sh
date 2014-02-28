#!/bin/bash
g++ -std=c++11 -c -o PostfixExpr.o PostfixExpr.cpp
g++ -std=c++11 -c -o Tokenizer.o Tokenizer.cpp
g++ -std=c++11 -c -o PostfixExprTestFixture.o PostfixExprTestFixture.cpp
g++ -std=c++11 -c -o testPostfixExpr.o testTokenizer.cpp
g++ -std=c++11 -L /usr/lib -o postfixTester PostfixExpr.o Tokenizer.o PostfixExprTestFixture.o testPostfixExpr.o -lcppunit -ldl
