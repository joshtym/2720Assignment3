CFLAGS = -I /usr/include
CXXFLAGS = -std=c++11
LIBDIR = -L /usr/lib
LNFLAGS = -lcppunit -ldl
OBJECTS = PostfixExpr.o Tokenizer.o PostfixExprTestFixture.o testPostfixExpr.o
OBJECTS2 = TokenizerTestFixture.o testTokenizer.o

postFixTester: $(OBJECTS)
	g++ $(CXXFLAGS) $(LIBDIR) -o $@ $^ $(LNFLAGS)
	
tokenizerTester: $(OBJECTS2)
	g++ $(CXXFLAGS) $(LIBDIR) -o $@ $^ $(LNFLAGS)
	
%.o : %.cc
	g++ $(CXXFLAGS) $(CFLAGS) -c $^

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f postFixTester tokenizerTester
