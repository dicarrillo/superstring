CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic
DEPS = superstring.h
OBJ = main.o superstring.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

superstring: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) superstring