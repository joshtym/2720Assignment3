CFLAGS = -I /usr/include -std=c++11
LIBDIR = -L /usr/lib
LNFLAGS = -lcppunit -ldl
OBJECTS = PostfixExpr.o PostfixExprTestFixture.o testPostfixExpr.o
OBJECTS2 = TokenizerTestFixture.o testTokenizer.o

postFixTester: $(OBJECTS)
	g++ -std=c++11 $(LIBDIR) -o $@ $^ $(LNFLAGS)
	
tokenizerTester: $(OBJECTS2)
	g++ -std=c++11 $(LIBDIR) -o $@ $^ $(LNFLAGS)
	
%.o : %.cc
	g++ -std=c++11 $(CFLAGS) -c $^

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f postFixTester tokenizerTester
