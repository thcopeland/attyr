CFLAGS = -lattyr -lm -Wall -O3 -flto
CC = gcc

all: scene tri

scene: scene.c utils/darray.c utils/common.c utils/wavefront.c
	$(CC) $^ $(CFLAGS) -o $@

tri: tri.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm scene tri
