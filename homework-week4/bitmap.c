#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "bitmap.h"

#if defined(VERSION1)
void rgba_to_bw(uint32_t *bitmap, int width, int height, long stride) {
	int row, col;
	uint32_t pixel, r, g, b, a, bw; 
	for (row = 0; row < height; row++) {
		for (col = 0; col < width; col++) {
			pixel = bitmap[col + row * stride / 4]; 
			a = (pixel >> 24) & 0xff;
			r = (pixel >> 16) & 0xff;
			g = (pixel >> 8) & 0xff;
			b = pixel & 0xff;
			bw = (uint32_t) (r * 0.299 + g * 0.587 + b * 0.114);
			bitmap[col + row * stride / 4]  
				= (a << 24) + (bw << 16) + (bw << 8) + (bw);
		}
	}
}
#endif

#if defined(VERSION2)
#define TABLE_SIZE 256
uint8_t mul_299[TABLE_SIZE];
uint8_t mul_587[TABLE_SIZE];
uint8_t mul_114[TABLE_SIZE];

void generate_table() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		mul_299[i] = i * 0.299;
		mul_587[i] = i * 0.587;
		mul_114[i] = i * 0.114;
	}
}

void rgba_to_bw(uint32_t *bitmap, int width, int height, long stride) {
	int row, col, position;
	uint32_t pixel, r, g, b, a, bw; 
	for (row = height ; row >= 0; row--){
		for (col = width; col >= 0; col--){
			position = col + row * stride / 4;
			pixel = bitmap[position];
			a = (pixel >> 24) & 0xff;
			r = (pixel >> 16) & 0xff;
			g = (pixel >>  8) & 0xff;
			b = pixel & 0xff;
			bw = (uint32_t) (mul_299[r] + mul_587[g] + mul_114[b]);
			bitmap[position] = (a << 24) + (bw << 16) + (bw << 8) + (bw);
		}
	}
}
#endif

struct timespec timespec;

int main(int argc, char *argv[]) {

#if defined(VERSION1)                  /* for version 1*/
	printf("This is for version 1! \n");
	char result[] = "version_1.png";

#elif defined(VERSION2)                /* for version 2
					* and generate the table*/
	printf("This is for version 2! \n");
	char result[] = "version_2.png";
	printf("Now, generate table...\n");
	generate_table();
#endif
	
	return 0;
}
