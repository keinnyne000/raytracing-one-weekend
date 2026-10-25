CC := gcc
CFLAGS := -std=c2x -Wall

image:
	cmake -B build
	cmake --build build
	build/row > image.ppm
	feh image.ppm
