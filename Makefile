CXX = g++-13
CXXFLAGS = -std=c++20 -O2

EIGEN_INCLUDE = -I/usr/include/eigen3

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = QRDecomposition

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(EIGEN_INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

pack:
	zip -r $(TARGET).zip *.cpp *.h *.hpp Makefile README.md

.PHONY: all clean run pack