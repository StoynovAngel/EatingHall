CXX = g++
CXXFLAGS = -I./include -g -fdiagnostics-color=always

SRC_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(patsubst src/%.cpp, build/%.o, $(SRC_FILES))

OUTPUT = build/BackendApp

$(OUTPUT): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(OUTPUT)

build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f build/*.o $(OUTPUT)