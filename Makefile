CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = simulator

all: $(TARGET)

$(TARGET): src/LRUCache.cpp src/LFUCache.cpp test/simulator.cpp
	$(CXX) $(CXXFLAGS) -Iinclude src/LRUCache.cpp src/LFUCache.cpp test/simulator.cpp -o $(TARGET).exe

clean:
	del /Q simulator.exe 2> NUL || rm -f simulator simulator.exe
