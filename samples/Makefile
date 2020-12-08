CFLAGS = -lattyr -lm -Wall -O2
CC = gcc

SRC = scene.c darray.c common.c wavefront.c
HDR = darray.h common.h wavefront.h

all: scene tri

scene: $(SRC) $(HDR)
	$(CC) $(SRC) $(CFLAGS) -o $@

tri: tri.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm scene tri
