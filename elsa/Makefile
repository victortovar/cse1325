
CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`


elsa: main.o mainwin.o entrydialog.o customer.o options.o desktop.o order.o store.o 
	$(CXX) $(CXXFLAGS) main.o mainwin.o entrydialog.o customer.o options.o desktop.o order.o store.o $(GTKFLAGS) -o elsa

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS)

entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS)

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


clean:
	-rm -f *.o *.gch elsa
