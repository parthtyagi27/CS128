CXX = clang++
LD = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra 
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi

EXENAME = main
OBJS = main.o DNA.o

all	: $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

dna.o :	DNA.cpp DNA.h
	$(CXX) $(CXXFLAGS) DNA.cpp

main.o : main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

test:	tests.o DNA.o
	$(LD) tests.o DNA.o $(LDFLAGS) -o test

tests.o: tests/tests.cpp tests/catch.hpp DNA.cpp DNA.h
	$(CXX) $(CXXFLAGS) tests/tests.cpp

clean :
	-rm -f *.o $(EXENAME) test