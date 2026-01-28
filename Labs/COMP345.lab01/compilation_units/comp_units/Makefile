CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra
INCLUDES = -Iinclude
TARGET = app

SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:src/%.cpp=build/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
