
CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

debug: CXXFLAGS += -g

rebuild: clean main

elsa: customer.o options.o desktop.o order.o store.o main.o mainwin.o entrydialog.o *.h
	$(CXX) $(CXXFLAGS) customer.o options.o desktop.o order.o store.o main.o mainwin.o entrydialog.o $(GTKFLAGS) -o elsa

customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp

options.o: options.cpp *.h
	$(CXX) $(CXXFLAGS) -c options.cpp

desktop.o: desktop.cpp *.h
	$(CXX) $(CXXFLAGS) -c desktop.cpp

order.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c order.cpp

store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp 

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS)

entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS)

clean:
	-rm -f *.o *.gch elsa
