# Makefile 

CC = gcc
CFLAGS = -Wall -Wextra $(shell pkg-config --cflags sdl2 SDL2_image gtk+-3.0)
LDLIBS := -lm $(shell pkg-config --libs sdl2 SDL2_image gtk+-3.0)
SRC = $(wildcard ColorFilters/*.c DetectionFilters/*.c \
        BlurringFilters/*.c MathsFilters/*.c main.c test.c)
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

all: main test

#here $@ mean the target and $^ mean the dependencies

main: main.o ${OBJ}
    ${CC} ${CFLAGS} ${LDLIBS} -o $@ $^ 

test: test.o ${OBJ}
    ${CC} ${CFLAGS} ${LDLIBS} -o $@ $^ 

.PHONY: all clean

clean:
    ${RM} ${OBJ}
    ${RM} ${DEP}
    ${RM} main

-include ${DEP}

# END