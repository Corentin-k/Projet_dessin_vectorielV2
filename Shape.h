//
// Created by koco on 13/04/2023.
//

#ifndef PROJET_C_SHAPE_H
#define PROJET_C_SHAPE_H
typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;

typedef struct shape {
    unsigned id;
    SHAPE_TYPE shape_type; // type de la forme pointé
    void *ptrShape; // pointeur sur n'importe quelle forme
    char* color;
}Shape;


Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py,char* color);
Shape *create_line_shape(int px1, int py1, int px2, int py2,char* color);
Shape *create_square_shape(int px, int py, int length,char* color);
Shape *create_rectangle_shape(int px, int py, int width, int height,char* color);
Shape *create_circle_shape(int px, int py, int radus,char* color);
Shape *create_polygon_shape(int lst[], int n,char* color);
void delete_shape(Shape * shape);
void print_shape(Shape * shape);

#endif //PROJET_C_SHAPE_H
