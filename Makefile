CC = gcc
BINARY = moby_dick_gen
SRC_DIR = src
OBJ_DIR = target
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
CFLAGS = -Wall -Wextra -g -O3

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(BINARY) $(OBJ_DIR)/*.o

.PHONY: all clean
