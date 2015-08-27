#ifndef __BITMAP_H
#define __BITMAP_H
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define HEADER_SIZE 14
#define INFO_SIZE 40

typedef struct BMP {
	unsigned char header[HEADER_SIZE];
	unsigned char info[INFO_SIZE];

	/* Fields for header */
	uint16_t identifier;
	uint32_t filesize;
	uint32_t reserved;
	uint32_t bitmap_dataoffset;
	
	/* Fields for information */
	uint32_t bitmap_headersize;
	uint32_t width;
	uint16_t height;
	uint16_t planes;
	uint16_t bits_perpixel;
	uint32_t compression;
	uint32_t imagesize;
	uint32_t hresolution;
	uint32_t vresolution;
	uint32_t usedcolors;
	uint32_t importantcolors;

	/* bitmap data */
	uint32_t *data; 
} BMP;
#endif
