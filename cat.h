#ifndef CAT_H
#define CAT_H

#include "image.h"

typedef struct {
    double x1;
    double y1;
    double x2;
    double y2;
    struct vector *next; 
} Vector;

Vector* read_vector_file(const char *filename);
void draw_vector(Vector *vector, Picture *picture, Color color);
void scale_vector(Vector *vector, double scale);
void shift_vector(Vector *vector, double dx, double dy);
void flip_vector(Vector *vector);
Vector* duplicate_vector(Vector *vector);
void free_vector(Vector *vector);

#endif