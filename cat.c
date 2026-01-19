#include "cat.h"

Vector* read_vector_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("error: can't open the file %s\n", filename);
        return NULL;
    }

    //a
    Vector *head = NULL;
    float x1, y1, x2, y2;

    while (fscanf(file, "%f %f %f %f", &x1, &y1, &x2, &y2) == 4) {
        
        //b
        Vector *new_segment = (Vector*)malloc(sizeof(Vector));
        new_segment->x1 = x1;
        new_segment->y1 = y1;
        new_segment->x2 = x2;
        new_segment->y2 = y2;
        
        //c
        new_segment->next = head;
        
        //d
        head = new_segment;
    }
    fclose(file);
    return head;
}


void draw_vector(Vector *vector, Picture *picture, Color color) {
    Vector *current = vector;
    while (current != NULL) {
        draw_line(picture, (int)current->x1, (int)current->y1, (int)current->x2, (int)current->y2, color);
        current = current->next;
    }
}


void scale_vector(Vector *vector, double scale) {
    Vector *current = vector;
    while (current != NULL) {
        current->x1 *= scale;
        current->y1 *= scale;
        current->x2 *= scale;
        current->y2 *= scale;
        
        current = current->next;
    }
}


void shift_vector(Vector *vector, double dx, double dy) {
    Vector *current = vector;
    while (current != NULL) {
        current->x1 += dx;
        current->y1 += dy;
        current->x2 += dx;
        current->y2 += dy;
        
        current = current->next;
    }
}


void flip_vector(Vector *vector) {
    Vector *current = vector;
    while (current != NULL) {
       
        current->x1 = -current->x1;
        current->x2 = -current->x2;
        
        current = current->next;
    }
}


Vector* duplicate_vector(Vector *vector) {
    if (vector == NULL) {
        return NULL;
    }

    Vector *new_head = NULL;
    Vector *new_tail = NULL;
    Vector *current = vector;

    while (current != NULL) {
        Vector *new_segment = (Vector*)malloc(sizeof(Vector));
        new_segment->x1 = current->x1;
        new_segment->y1 = current->y1;
        new_segment->x2 = current->x2;
        new_segment->y2 = current->y2;
        new_segment->next = NULL;

        if (new_head == NULL) {
            new_head = new_segment;
            new_tail = new_segment;
        } else {
            new_tail->next = new_segment;
            new_tail = new_segment;
        }

        current = current->next;
    }

    return new_head;
}


void free_vector(Vector *vector) {
    Vector *current = vector;
    while (current != NULL) {
        Vector *next = current->next;
        free(current);
        current = next;
    }
}