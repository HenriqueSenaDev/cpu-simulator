# Compilation
CC = gcc # Compiler to use
CFLAGS = -Wall -Wextra -std=c11 # Compiler flags

# Source files to be compiled
# SRC := $(wildcard *.c)
SRC := $(shell find src -type f -name "*.c")

$(info $(SRC))

# Build
BUILD_DIR = ./build
OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o) # Compiled files generated in BUILD_DIR

$(info $(OBJ))

# Output
OUTPUT_DIR = ./output
TARGET = $(OUTPUT_DIR)/program.exe

# Set rule "build" as default to be executed.
all: build

# Rule "build" depends on compiled files in $(OBJ).
# Generates $(TARGET) executable if files in $(OBJ) are compiled.
build: create-dirs $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Creates $(BUILD_DIR) $(OUTPUT_DIR) directories.
create-dirs:
	mkdir -p $(OUTPUT_DIR)
	mkdir -p $(BUILD_DIR)

# Compile all "*.c" files in "*.o" files.
$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Deletes $(BUILD_DIR) $(OUTPUT_DIR) directories.
clean:
	rm -rf $(BUILD_DIR) $(OUTPUT_DIR)
