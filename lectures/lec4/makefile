# --- Compiler and flags ---
CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -g

# --- Project setup ---
TARGET   := main
SRC      := $(wildcard b.cpp)

# --- Default target ---
all: $(TARGET)

$(TARGET): $(SRC)
	@echo "🔧 Building with $(CXX)..."
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
