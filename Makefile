
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude


SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin


TARGET = $(BIN_DIR)/skillshare

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJ) -o $(TARGET)
	@echo "✅ Build successful! Run with ./$(TARGET)"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "🧹 Cleaned up!"


run: all
	./$(TARGET)
