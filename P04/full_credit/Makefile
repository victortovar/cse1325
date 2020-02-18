CXXFLAGS = --std=c++17

all: coin

debug: CXXFLAGS += -g
debug:coin

logger: logger.h
	$(CXX) $(CXXFLAGS) -DLOGGER test.cpp -c -o test.o
	$(CXX) $(CXXFLAGS) -DLOGGER coin.cpp -c -o coin.o
	$(CXX) $(CXXFLAGS) -DLOGGER test.o coin.o -o coin

rebuild: clean coin

coin: test.o coin.o *.h
	$(CXX) $(CXXFLAGS) test.o coin.o -o coin
test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o
coin.o: coin.cpp *.h
	$(CXX) $(CXXFLAGS) -c coin.cpp -o coin.o

coin.gch: coin.h
	$(CXX) $(CXXFLAGS) -c coin.h -o coin.gch

clean:
	rm -f *.o *.gch a.out coin
