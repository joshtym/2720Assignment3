CFLAGS = =I /usr/include
LIBDIR = -L /usr/lib
LNFLAGS = =lcppunit =ldl
OBJECTS =

postFixEvaluator: $(OBJECTS)
	g++ $(LIBDIR) -o $@ $^ $(LNFLAGS)
	
%.o : %.cc
	g++ $(CFLAGS) -c $^

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f postFixEvaluator
