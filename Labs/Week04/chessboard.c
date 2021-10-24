// Week 4 Lab
// Draws a 512x512 chessboard.
// 
// Dan Nguyen (z5206032)
// 2018/08/14
// 
// Dean Wunder (thu11-brass)

// Remember to pipe the output of this program into a file
// $ ./chessboard > chessboard.bmp
// $ eog chessboard.bmp &

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BOARD_SIZE   512
#define SQUARE_SIZE  (512 / 8)

// For writing BMP
#define PIXEL_START 26
#define PIXEL_BYTES 3
#define PIXEL_ALIGN 4
#define PIXEL_BITS  24
#define HEADER_SIZE 12

typedef struct _pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

void drawChessboard(pixel pixels[BOARD_SIZE][BOARD_SIZE]);

// Write an image to output
void writeImage(int output, pixel pixels[BOARD_SIZE][BOARD_SIZE]);

int main(int argc, char *argv[]) {
    // Pixel 2-dimensional array
    // remember, it's pixels[y][x]
    pixel pixels[BOARD_SIZE][BOARD_SIZE];

    drawChessboard(pixels);

    // Write the image to output
    writeImage(STDOUT_FILENO, pixels);

    return EXIT_SUCCESS;
}

// Draws a chessboard:
// 
// i and j represent the row and column of pixels respectively.
// There are 8 x 8 tiles on the board
// There are 64 x 64 pixels in a tile.
// There are 512 x 512 pixels on the board.
// 
// limit is an integer multiplier of SQUARE_SIZE which forms the upper
// bound of j (end of tile).
// 
// whiteBlack determines the colour of the starting tile of the next row.
// Therefore tile colour for the rest of the row is determinate.
// whiteBlack can be treated as a limit for i.

void drawChessboard(pixel pixels[BOARD_SIZE][BOARD_SIZE]) {
    
    int i ,j, limit, whiteBlack;
    
    whiteBlack = 1;
    i = 0;
    
    while (i < BOARD_SIZE) {
        
        limit = 1;
        j = 0;
        
        while (j < BOARD_SIZE) {
            
            // Draws chessboard:
            // whiteBlack checks if starting tile is black or white then
            // nested if..else will continue from that statement.
            if (whiteBlack % 2 != 0) {
                // Starting tile will be black...
                
                if (j < limit * SQUARE_SIZE && limit % 2 != 0) {
                    // j is bounded by limit * SQUARE_SIZE
                    // limit % 2 != 0 ensures every odd tile is black. 
                    
                    pixels[i][j].red = 0;
                    pixels[i][j].blue = 0;
                    pixels[i][j].green = 0;
                } else { 
                    pixels[i][j].red = 255;
                    pixels[i][j].blue = 255;
                    pixels[i][j].green = 255;
                }
            } else {
                // Starting tile will be white...
                
                if (j < limit * SQUARE_SIZE && limit % 2 != 0) {
                    // j is bounded by limit * SQUARE_SIZE
                    // limit % 2 != 0 ensures every odd tile is white.
                    
                    pixels[i][j].red = 255;
                    pixels[i][j].blue = 255;
                    pixels[i][j].green = 255;
                } else {
                    pixels[i][j].red = 0;
                    pixels[i][j].blue = 0;
                    pixels[i][j].green = 0;
                }
            }
            
            j++;
            
            // If j reaches the limit (tile width) then increase limit on
            // j by SQUARE_SIZE (arithmetic progression).
            if (j == limit * SQUARE_SIZE) {
                limit++;
            }
        }
        
        i++;
        
        // If i reaches tile height then increment whiteBlack to ensure
        // next starting tile in new row is the other colour.
        if (i == whiteBlack * SQUARE_SIZE) {
            whiteBlack++;
        }
    }
}

// Writes the pixels as a BMP file using the specification from
// https://en.wikipedia.org/wiki/BMP_file_format
void writeImage(int output, pixel pixels[BOARD_SIZE][BOARD_SIZE]) {
    // Initial BM bytes
    write(output, "BM", 2);

    // File size
    unsigned int rowSize = BOARD_SIZE * PIXEL_BYTES;
    unsigned int rowPadding = 0;
    if (rowSize % PIXEL_ALIGN != 0) {
        // Padd pixel to align properly
        rowPadding = PIXEL_ALIGN - (rowSize % PIXEL_ALIGN);
        rowSize += rowPadding;
    }

    unsigned int fileSize = PIXEL_START + (rowSize * BOARD_SIZE);
    write(output, (char *)&fileSize, sizeof(fileSize));

    // 4 reserved bytes
    write(output, "\0\0\0\0", 4);

    // start of pixel data
    // pixels start immediately after header
    unsigned int pixelStart = PIXEL_START;
    write(output, (char *)&pixelStart, sizeof(pixelStart));

    // Size of header
    unsigned int headerSize = HEADER_SIZE;
    write(output, (char *)&headerSize, sizeof(headerSize));

    // Image width and height
    unsigned short size = BOARD_SIZE;
    write(output, (char *)&size, sizeof(size));
    write(output, (char *)&size, sizeof(size));

    // Number of image planes (1)
    unsigned short planes = 1;
    write(output, (char *)&planes, sizeof(planes));

    // Number of bits per pixel (24)
    unsigned short bitsPerPixel = PIXEL_BITS;
    write(output, (char *)&bitsPerPixel, sizeof(bitsPerPixel));

    // Write each of the pixels
    unsigned int padding = 0x01234567;
    int y = 0;
    while (y < BOARD_SIZE) {
        int x = 0;
        while (x < BOARD_SIZE) {
            // Write the blue, green, then red pixels
            pixel pixel = pixels[y][x];
            write(output, &(pixel.blue), sizeof(pixel.blue));
            write(output, &(pixel.green), sizeof(pixel.green));
            write(output, &(pixel.red), sizeof(pixel.red));
            x++;
        }

        // Write the row padding bytes
        write(output, (char *)&padding, rowPadding);
        y++;
    }
}