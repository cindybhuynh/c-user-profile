# Makefile

# The compiler
CC = gcc

# The source file
SRC = main.c

# The output executable
OUT = bin/myprogram

# The build rule
all: $(OUT)

# How to build the executable
$(OUT): $(SRC)
	@mkdir -p bin
	$(CC) $(SRC) -o $(OUT)

# Clean up build artifacts
clean:
	rm -rf bin