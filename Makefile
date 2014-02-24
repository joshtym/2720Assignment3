CFLAGS = =I /usr/include -std=c++11
LIBDIR = -L /usr/lib
LNFLAGS = -lcppunit -ldl
OBJECTS = PostfixExpr.o PostfixExprTestFixture.o testPostfixExpr.o

postFixTester: $(OBJECTS)
	g++ $(LIBDIR) -o $@ $^ $(LNFLAGS)
	
%.o : %.cc
	g++ $(CFLAGS) -c $^

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f postFixTester
