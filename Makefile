# Directories
BUILD_DIR = build
SRC_DIR = .

# Default rule
all: create_build_dir configure build 

# Rule to configure using CMake
configure: 
	@cmake -S $(SRC_DIR) -B $(BUILD_DIR)

# Rule to build using CMake
build: 
	@cmake --build $(BUILD_DIR)

# Rule to create build directory
create_build_dir:
	@mkdir -p $(BUILD_DIR)

# Clean rule to remove build artifacts and the JSON file
clean:
	rm -rf $(BUILD_DIR)

move-json:
	@cp $(SRC_DIR)/flashcards/*.json $(BUILD_DIR)/

.PHONY: all clean create_build_dir configure build move-json