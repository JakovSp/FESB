#ifndef TYPES
#define TYPES
typedef struct PIXEL3{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
}Pixel3;

#define TILE_W 16		// active cell width
#define TILE_H 16		// active cell height
#define IMUL(a,b) __mul24(a,b)
#endif