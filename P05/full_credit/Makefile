CXXFLAGS = --std=c++17

all: store

debug: CXXFLAGS += -g
debug: store


rebuild: clean main

store: main.o product.o taxfree.o taxed.o *.h
	$(CXX) $(CXXFLAGS) main.o product.o taxfree.o taxed.o -o store
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
product.o: product.cpp *.h
	$(CXX) $(CXXFLAGS) -c product.cpp -o product.o
taxfree.o: taxfree.cpp *.h
	$(CXX) $(CXXFLAGS) -c taxfree.cpp -o taxfree.o
taxed.o: taxed.cpp *.h
	$(CXX) $(CXXFLAGS) -c taxed.cpp -o taxed.o

product.gch: product.h
	$(CXX) $(CXXFLAGS) -c product.h -o product.gch
taxfree.gch: taxfree.h
	$(CXX) $(CXXFLAGS) -c taxfree.h -o taxfree.gch
taxed.gch: taxed.h
	$(CXX) $(CXXFLAGS) -c taxed.h -o taxed.gch

clean:
	rm -f *.o *.gch a.out coin
