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

static int redSteps (long int steps);
static int greenSteps (long int steps);
static int blueSteps (long int steps);

// "pixelColor" takes "steps" and assigns it a colour.
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
        color.red = redSteps(steps);
        color.green = greenSteps(steps);
        color.blue = blueSteps(steps);
    }

    return color;
}

static int redSteps (long int steps) {
      
    steps = steps * steps;
    steps = steps % 255;
    
    return steps;
}

static int greenSteps (long int steps) {
    
    steps = steps * steps * steps + steps * steps;
    steps = steps % 255;
    
    return steps;
}

static int blueSteps (long int steps) {
    
    steps = steps * steps * steps + steps * steps;
    steps = steps % 255;
    
    return steps;
}