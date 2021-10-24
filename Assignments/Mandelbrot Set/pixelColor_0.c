// Assignment 1 Mandelbrot: Pixel coloring functions
// pixelColor.c
//
// Dan Nguyen (z5206032)
// 2018/09/05
//
// Dean Wunder (thu11-brass)
//
// Version 1.0.1: Fix issues with spacing and indentation.
// Version 1.0.0: Assignment released.

#include "mandelbrot.h"
#include "pixelColor.h"

// "pixelColor" takes "steps" and assigns it a colour.

// A COOL Blue Image of Mandelbrot Set
struct pixel pixelColor(int steps) {
    struct pixel color = {
        .red = steps,
        .green = steps,
        .blue = steps,
    };
    
    if (steps == NO_ESCAPE) {
        color.red = 0;
        color.green = 0;
        color.blue = 0;
    } else {
        color.red = steps / 10;
        color.green = steps * 2 / 3;
        color.blue = steps;
    }

    return color;
}

/*
// Grey Intensity Image of Mandelbrot Set
struct pixel pixelColor(int steps) {
    struct pixel color = {
        .red = steps,
        .green = steps,
        .blue = steps,
    };

    if (steps == NO_ESCAPE) {
        color.red = 0;
        color.green = 0;
        color.blue = 0;
    } else {
        color.red = steps;
        color.green = steps;
        color.blue = steps;
    }

    return color;
}
*/

/*
// Binary Image of Mandelbrot Set
struct pixel pixelColor(int steps) {
    struct pixel color = {
        .red = steps,
        .green = steps,
        .blue = steps,
    };

    if (steps == NO_ESCAPE) {
        color.red = 255;
        color.green = 255;
        color.blue = 255;
    } else {
        color.red = 0;
        color.green = 0;
        color.blue = 0;
    }

    return color;
}
*/