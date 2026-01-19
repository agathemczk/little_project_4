#include "image.h"
#include "cat.h"

int main () {
    Picture image = new_picture(500,500);

    Color black = {0, 0, 0};
    Color red = {255, 0, 0};
    Color green = {0, 255, 0};
    Color yellow = {255, 255, 0};
    Color blue = {0, 0, 255};
    Color magenta = {255, 0, 255};
    Color cyan = {0, 255, 255};
    Color white = {255, 255, 255};
    Color favorite = {104, 130, 217};

    /*
    //1
    FILE *file = fopen("ressources/cat.txt", "r");
    if (file == NULL) {
        printf("error: can't open the file\n");
        return 1;
    }

    float x1, y1, x2, y2;
    while (fscanf(file, "%f %f %f %f", &x1, &y1, &x2, &y2) == 4) {
        draw_line(&image, (int)x1, (int)y1, (int)x2, (int)y2, favorite);
    }
    

    //2
    Vector *cat = read_vector_file("ressources/cat.txt");
    draw_vector(cat, &image, white);
    

    //3
    Vector *cat = read_vector_file("ressources/cat.txt");
    scale_vector(cat, 0.5);
    draw_vector(cat, &image, yellow);
    flip_vector(cat);
    shift_vector(cat,500,0);
    draw_vector(cat, &image, red);

    
    //3 bis
    Vector *kangkang = read_vector_file("ressources/kang.txt");

    for (int i = 0; i <= 4; i++) {
        draw_vector(kangkang, &image, cyan);
        shift_vector(kangkang, 100, 0);
    }    
    
    shift_vector(kangkang, -500, 200); 
    for (int i = 0; i <= 4; i++) {
        draw_vector(kangkang, &image, magenta);
        shift_vector(kangkang, 100, 0);
    }    

    flip_vector(kangkang);
    shift_vector(kangkang, 550, -100);
    for (int i = 0; i <= 5; i++) {
        draw_vector(kangkang, &image, green);
        shift_vector(kangkang, 100, 0);
    }
    */

    //4
    Vector *kangkang = read_vector_file("ressources/kang.txt");

    Vector *top_line = duplicate_vector(kangkang);
    for (int i = 0; i <= 4; i++) {
        draw_vector(top_line, &image, blue);
        shift_vector(top_line, 100, 0);
    }
    free_vector(top_line);

    Vector *bottom_line = duplicate_vector(kangkang);
    shift_vector(bottom_line, 0, 200);
    for (int i = 0; i <= 4; i++) {
        draw_vector(bottom_line, &image, magenta);
        shift_vector(bottom_line, 100, 0);
    }
    free_vector(bottom_line);

    Vector *middle_line = duplicate_vector(kangkang);
    flip_vector(middle_line);
    shift_vector(middle_line, 50, 100);
    for (int i = 0; i <= 5; i++) {
        draw_vector(middle_line, &image, favorite);
        shift_vector(middle_line, 100, 0);
    }
    free_vector(middle_line);
    free_vector(kangkang);
    
    save_picture(&image, "duplicate.ppm");

    //fclose(file);
    free(image.pixels);
    return 0;
}