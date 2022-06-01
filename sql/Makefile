CC = gcc
CFLAGS = -g -O2 -Wall -Wstrict-prototypes -Werror -Wextra
VPATH = src

BIN = sql
SRC = $(shell find src -name '*.c')
OBJ = $(SRC:.c=.o)

all: $(BIN) 

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

clean:
	$(RM) -rf $(BIN)

