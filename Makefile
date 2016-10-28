## Simple SDL mini code
 
CC=gcc
 
CPPFLAGS= `pkg-config --cflags sdl`
CFLAGS= -Wall -Wextra -Werror -std=c99 
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lm  
 
SRC= detect.c binarization.c  toolstr.c
OBJ= ${SRC:.c=.o}

 
all: main
 
main: ${OBJ}
 
clean:
	rm -f *~ *.o
	rm -f main
 
# END
