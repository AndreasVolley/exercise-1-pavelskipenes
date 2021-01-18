CC = gcc

CFLAGS = -Wall -Wextra -g3 -std=c99 -fanalyzer
LDFLAGS = -lpthread -g3
SRC = foo.c

TARGET = foo

all: $(TARGET)

# Define all object files.
OBJ = $(SRC:.c=.o)

# rule to link the program
$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

# Compile: create object files from C source files.
%.o : %.c
	$(CC) $(CFLAGS) -c  $< -o $@ 

# rule for cleaning re-compilable files.
clean:
	rm -f $(TARGET) $(OBJ)

rebuild:	clean all

.PHONY: all rebuild clean

.PHONY: format
format:
	indent --linux-style --line-length0 *.c
