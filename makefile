CC=g++
CFLAGS=-I include -O3 -std=c++20 -o slots

all:
	$(CC) $(CFLAGS) main.cpp src/slot_parts/GlassGenerator.cpp src/utils/Reelset.cpp src/utils/Glass.cpp src/utils/RandomGenerator.cpp

clear:
	rm -rf *.o