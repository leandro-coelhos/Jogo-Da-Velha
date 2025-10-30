CXX = g++
CXXFLAGS = -Wall -ftest-coverage -fprofile-arcs
LDFLAGS = -lgcov

all: test

test: velha.o testa_velha.o
	$(CXX) $(CXXFLAGS) -o test velha.o testa_velha.o $(LDFLAGS)

velha.o: velha.cpp velha.h
	$(CXX) $(CXXFLAGS) -c velha.cpp

testa_velha.o: testa_velha.cpp velha.h
	$(CXX) $(CXXFLAGS) -c testa_velha.cpp

clean:
	rm -f *.o *.gcda *.gcno *.gcov test
