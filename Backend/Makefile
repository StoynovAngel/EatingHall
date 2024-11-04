CXX = g++
CXXFLAGS = -I./include -g -fdiagnostics-color=always

OBJ_FILES = build/User.o build/UserValidation.o build/Main.o build/Menu.o

BackendApp: $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o BackendApp	

build/User.o: src/User.cpp include/User.h
	$(CXX) $(CXXFLAGS) -c src/User.cpp -o build/User.o	

build/Menu.o: src/Menu.cpp include/Menu.h
	$(CXX) $(CXXFLAGS) -c src/Menu.cpp -o build/Menu.o

build/UserValidation.o: src/UserValidation.cpp include/UserValidation.h	
	$(CXX) $(CXXFLAGS) -c src/UserValidation.cpp -o build/UserValidation.o	

build/Main.o: Main.cpp include/User.h
	$(CXX) $(CXXFLAGS) -c Main.cpp -o build/Main.o	

clean:
	rm -f build/*.o BackendApp