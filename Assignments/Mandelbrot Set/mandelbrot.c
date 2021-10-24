// Assignment 1 Mandelbrot: Mandelbrot generation functions
// mandelbrot.c
//
// Dan Nguyen (z5206032)
// 2018/08/26 - 2018/09/05
// 
// Dean Wunder (thu11-brass)
//
// Version 1.0.2: Fix minor typos in comments.
// Version 1.0.1: Fix issues with spacing and indentation.
// Version 1.0.0: Assignment released.

#include <stdio.h>
#include <math.h>
#include "mandelbrot.h"
#include "pixelColor.h"

// Take a pixel grid and and the path from the web browser used to
// request the 'tile'.
//
// The requestPath will be in the form "/mandelbrot/2/{zoom}/{x}/{y}.bmp".
// In the query, 'x' and 'y' are decimals and describe the 'center' of the
// tile and need to be converted into a complex number.
// 'zoom' is an integer representing the zoom level for the tile.
void serveMandelbrot(
    struct pixel pixels[TILE_SIZE][TILE_SIZE],
    char *requestPath
) {
    struct complex center = {0.0, 0.0};
    int z = 7;

    sscanf(
        requestPath,
        "/mandelbrot/2/%d/%lf/%lf.bmp",
        &z, &center.re, &center.im
    );

    // Use drawMandelbrot to draw the image.
    drawMandelbrot(pixels, center, z);
}

// Draws the mandelbrot
// 
// "pixels" acts as a map for complex numbers to be assigned to a particular
// position of the array.
// 
// "center" complex number of a tile is given so the first complex number,
// "c", can be calculated and mapped to pixels[0][0].
// 
// Zoom level, "z", is given and can be used to calculate distance between
// each pixel.
// 
// As i++ and j++, c.im += distance and c.re += distance respectively.
void drawMandelbrot(
    struct pixel pixels[TILE_SIZE][TILE_SIZE],
    struct complex center,
    int z
) {
    
    int i, j, steps;
    double distance = pow(2, -z);
    
    struct complex c;
    c.re = center.re - (TILE_SIZE / 2) * distance + distance / 2;
    c.im = center.im - (TILE_SIZE / 2) * distance + distance / 2;
    
    i = 0;
    
    while (i < TILE_SIZE) {
        
        c.re = center.re - (TILE_SIZE / 2) * distance + distance / 2;
        j = 0;
        
        while (j < TILE_SIZE) {
            
            steps = escapeSteps(c);
            pixels[i][j] = pixelColor(steps);
            
            c.re += distance;
            j++;
        }
        
        c.im += distance;
        i++;
    }
}

// "escapeSteps" determines number of iterations it takes for "c" to
// escape the Mandelbrot set.
int escapeSteps (struct complex c) {
    
    struct complex z;
    double modulus;
    double z_re_placeholder;
    int steps = 0;
   
    z.re = 0;
    z.im = 0;

    while (steps < MAX_STEPS) {
        
        modulus = sqrt(z.re * z.re + z.im * z.im);
        
        if (modulus >= 2) {
            return steps;
        }
        
        z_re_placeholder = z.re;
        z.re = (z.re * z.re - z.im * z.im) + c.re;
        z.im = (2 * z_re_placeholder * z.im) + c.im;
        
        steps++;
    }

    return NO_ESCAPE;
}


// Temporary Main Function
/*
int main (void) {
    
    struct complex c;
    
    c.im = -2;
    
    while (c.im <= 2) {
        
        c.re = -2;
        
        while (c.re <= 2) {
            if (escapeSteps(c) == NO_ESCAPE) {
                printf("*");
            } else {
                printf(" ");
            }
            c.re += 0.02;
        }
        printf("\n");
        c.im += 0.02;
    }
    
    return 0;
}
*/

// Temporary Main Function with Array Mapping
/*
int main (void) {
    
    struct complex c;
    int i, j;
    
    i = 0;
    c.im = -2;
    
    while (i <= 128) {
        
        j = 0;
        c.re = -2;
        
        while (j <= 128) {
            if (escapeSteps(c) == NO_ESCAPE) {
                printf("*");
            } else {
                printf(" ");
            }
            c.re += 0.025;
            j++;
        }
        printf("\n");
        c.im += 0.025;
        i++;
    }
    
    return 0;
}
*/