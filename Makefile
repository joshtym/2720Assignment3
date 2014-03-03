GXX = /opt/centos/devtoolset-1.1/root/usr/bin/g++
CFLAGS = -I /usr/include -std=c++0x
LFLAGS = -L /usr/lib
LNFLAGS = -lcppunit -ldl
OBJECTS = PostfixExpr.o Tokenizer.o PostfixExprTestFixture.o testPostfixExpr.o
OBJECTS2 = Tokenizer.o TokenizerTestFixture.o testTokenizer.o
OBJECTS3 = Tokenizer.o PostfixExpr.o main.o

all: evaluator postFixTester tokenizerTester

tests: postFixTester tokenizerTester

evaluator: $(OBJECTS3)
	${GXX} $(LFLAGS) -o $@ $^ $(LNFLAGS)

postFixTester: $(OBJECTS)
	${GXX} $(LFLAGS) -o $@ $^ $(LNFLAGS) 

tokenizerTester: $(OBJECTS2)
	${GXX} $(LFLAGS) -o $@ $^ $(LNFLAGS)  

%.o : %.cpp
	${GXX} $(CFLAGS) -c $^

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f evaluator postFixTester tokenizerTester
