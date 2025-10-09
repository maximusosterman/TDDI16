# --- Compiler and flags ---
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -Weffc++ -Wold-style-cast -Woverloaded-virtual -g

# --- Project setup ---
TARGET   := main
SRC      := $(wildcard *.cpp)

# --- Default target ---
all: $(TARGET)

$(TARGET): $(SRC)
	@echo "Building with $(CXX)..."
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

# --- Run with input redirection ---
run-input: $(TARGET)
	./$(TARGET) < combined.txt

# --- Debug with LLDB and redirected input ---
debug: $(TARGET)
	lldb -- ./$(TARGET) < combined.txt

clean:
	rm -f $(TARGET)

.PHONY: all run clean
