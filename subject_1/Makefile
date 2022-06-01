CC = gcc
CFLAGS = -g -O2 -Wall -Wstrict-prototypes -Werror -Wextra
VPATH = src

BIN = extract
SRC = $(shell find src -name '*.c')
OBJ = $(SRC:.c=.o)

WOLFSSLIBS = -lwolfssl
WOLFSSLDIR = wolfssl

all: $(BIN) wolfssl



$(BIN): $(OBJ)
	$(CC) $(WOLFSSLIBS) $(CFLAGS) $(OBJ) -o $(BIN)

wolfssl:
	unzip zip/wolfssl-5.2.0.zip
	mv wolfssl-5.2.0 $(WOLFSSLDIR)
	cd $(WOLFSSLDIR) && ./configure && make

clean:
	$(RM) -rf $(BIN)

clean_lib:
	$(RM) -rf $(WOLFSSLDIR)

clean_all: clean clean_lib
