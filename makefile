
CXX = clang++
CXXFLAGS = -I./header

SRC_DIR = src
UTIL_DIR = header
BUILD_DIR = build
TARGET = $(BUILD_DIR)/program  # Output file is now a program, not the directory

# Collect all source files
SRC = $(wildcard $(SRC_DIR)/*.cpp $(UTIL_DIR)/*.cpp)

# Convert .cpp files to .o object files
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp)) \
      $(patsubst $(UTIL_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(UTIL_DIR)/*.cpp))

all: $(TARGET)

# Link executable
$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)  
# Link object files to create the executable


# Compile .cpp files from SRC_DIR
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile .cpp files from UTIL_DIR
$(BUILD_DIR)/%.o: $(UTIL_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean

