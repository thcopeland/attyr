CFLAGS = -lattyr -lm -Wall -O2
CC = gcc

all: scene tri

scene: scene.c utils/darray.c utils/common.c utils/wavefront.c
	$(CC) scene.c utils/darray.c utils/common.c utils/wavefront.c $(CFLAGS) -o $@

tri: tri.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm scene tri
