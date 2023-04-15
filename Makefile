CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pthread

BUILD_DIR := build
TARGET := $(BUILD_DIR)/gpio_simulator

SOURCES := $(wildcard ./*.cpp) $(wildcard ./interfaces/*.cpp) $(wildcard ./hardware/*.cpp) 
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)
	rm -rf $(OBJECTS)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(OBJECTS)

