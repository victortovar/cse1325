CXXFLAGS = --std=c++17

debug: CXXFLAGS += -g

store: main.o cart.o item.o *.h
	$(CXX) $(CXXFLAGS) main.o cart.o item.o -o store
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
cart.o: cart.cpp *.h
	$(CXX) $(CXXFLAGS) -c cart.cpp
item.o: item.cpp *.h
	$(CXX) $(CXXFLAGS) -c item.cpp
clean:
	-rm -f *.o *.gch store

