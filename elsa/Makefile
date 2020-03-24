
CXXFLAGS = --std=c++17

all: store

debug: CXXFLAGS += -g
debug: store

rebuild: clean main

store: customer.o options.o desktop.o order.o store.o main.o *.h
	$(CXX) $(CXXFLAGS) customer.o options.o desktop.o order.o store.o -o store

customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp -o customer.o

options.o: options.cpp *.h
	$(CXX) $(CXXFLAGS) -c options.cpp -o options.o

desktop.o: desktop.cpp *.h
	$(CXX) $(CXXFLAGS) -c desktop.cpp -o desktop.o

order.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c order.cpp -o order.o

store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp -o store.o
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

customer.gch: customer.h
	$(CXX) $(CXXFLAGS) -c customer.h -o customer.gch

options.gch: options.h
	$(CXX) $(CXXFLAGS) -c options.h -o options.gch

desktop.gch: desktop.h
	$(CXX) $(CXXFLAGS) -c desktop.h -o desktop.gch

order.gch: order.h
	$(CXX) $(CXXFLAGS) -c order.h -o order.gch

store.gch: store.h
	$(CXX) $(CXXFLAGS) -c store.h -o store.gch

clean:
	-rm -f *.o *.gch a.out store
