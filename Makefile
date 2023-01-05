CC = gcc
CFLAGS = -I./include -L./lib -lm -lSDL2
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = main


all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(OBJECTS) -o $@ $(CFLAGS)

%.o: %.c
    $(CC) -c $< -o $@ $(CFLAGS)

test: $(EXECUTABLE)
    ./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

