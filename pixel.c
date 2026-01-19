#include "image.h"

Picture new_picture(int width, int height) {
    Picture picture;
    picture.width = width;
    picture.height = height;
    picture.pixels = (Color*)malloc(width * height * sizeof(Color));
    return picture;
}


void save_picture(Picture *picture, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P6\n%d %d\n255\n", picture->width, picture->height);

    for (int y = 0; y < picture->height; y++) {
        for (int x = 0; x < picture->width; x++) {
            Color pixel = picture->pixels[y * picture->width + x];
            fwrite(&pixel, sizeof(Color), 1, file);
        }
    }

    fclose(file);
}


void set_pixel(Picture *picture, int x, int y, Color color) {
    if (x < 0 || x >= picture->width || y < 0 || y >= picture->height) {
        return; //vérif si hors limites
    }
    picture->pixels[y * picture->width + x] = color;
}


void draw_line(Picture *picture, int x1, int y1, int x2, int y2, Color color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int n = (abs(dx) > abs(dy) ? abs(dx) : abs(dy)) +1; //n = max(|x1-x2|, |y1-y2|) + 1

    if (n == 1) {
        set_pixel(picture, x1, y1, color);
        return;
    }

    for (int i = 0; i < n; i++) {
        int x = x1 + dx * i / (n - 1);
        int y = y1 + dy * i / (n - 1);
        set_pixel(picture, x, y, color);
        
    }
}