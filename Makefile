# Alexis Tercero
# Compiler to use
CC=gcc

# Compiler flags
CFLAGS=-Wall -Wextra -std=c17 -pedantic

# Directories
SRC_DIR=./src
BUILD_DIR=./build
OUT_DIR=./software

# Files
# sets the SRC variable to a list of all the source code files in the SRC_DIR directory.
# SRC=$(wildcard $(SRC_DIR)/*.c)
SRC = $(wildcard $(SRC_DIR)/*.c) #$(wildcard $(SRC_DIR)/conversions/*.c)
# This sets the OBJ variable to a list of all the object files that need to be built
OBJ=$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Output file
EXECUTABLE=$(OUT_DIR)/main.exe

# Default target: build the executable
all: $(EXECUTABLE)

# Build the executable
$(EXECUTABLE): $(OBJ)
	@mkdir -p $(@D) # Create the output directory if it doesn't exist
	$(CC) $(CFLAGS) $^ -o $@

# Build the object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D) # Create the build directory if it doesn't exist
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: remove object files and the executable
clean:
	rm -f $(OBJ) $(EXECUTABLE)

# Declare the targets that are not files
.PHONY: all clean
