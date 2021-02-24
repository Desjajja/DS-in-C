TARGET = sqlist
CC = gcc
CFLAGS = -Wall -c
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

debug: $(SRC)
	@mkdir -p debug
	$(CC) $(SRC) -o debug/test_$(TARGET) -g

release: $(OBJ)
	$(CC) $(OBJ) -o release/$@_$(TARGET)
	rm $(OBJ)

%.o: %.c
	@mkdir -p release 
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf release/ debug/
