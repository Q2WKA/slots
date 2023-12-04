CC=g++
CFLAGS=-Wall -I include

all:
	g++ main.cpp src/slot_parts/GlassGenerator.cpp src/utils/Reelset.cpp src/utils/Glass.cpp src/utils/RandomGenerator.cpp -Iinclude -O3 -o slots