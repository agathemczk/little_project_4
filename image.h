#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

typedef struct {
    int width;
    int height;
    Color* pixels;
} Picture;

Picture new_picture(int width, int height);
void save_picture(Picture *picture, const char* filename);
void set_pixel(Picture *picture, int x, int y, Color color);
void draw_line(Picture *picture, int x1, int y1, int x2, int y2, Color color);

#endif