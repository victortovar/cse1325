
CXXFLAGS = --std=c++17

all: store

debug: CXXFLAGS += -g
debug: store

rebuild: clean main

store: customer.o options.o desktop.o *.h
	$(CXX) $(CXXFLAGS) customer.o options.o desktop.o -o store

customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp -o customer.o

options.o: options.cpp *.h
	$(CXX) $(CXXFLAGS) -c options.cpp -o options.o

desktop.o: desktop.cpp *.h
	$(CXX) $(CXXFLAGS) -c desktop.cpp -o desktop.o

customer.gch: customer.h
	$(CXX) $(CXXFLAGS) -c customer.h -o customer.gch

options.gch: options.h
	$(CXX) $(CXXFLAGS) -c options.h -o options.gch

desktop.gch: desktop.h
	$(CXX) $(CXXFLAGS) -c desktop.h -o desktop.gch

clean:
	-rm -f *.o *.ghc a.out store
