#include "shape.h"

void cml_Shape_New(cml_Shape* shape, unsigned int* values, unsigned int ndim) {
    shape->ndim = ndim;
    for (int i = 0; i < ndim; i ++) {
        shape->values[i] = values[i];
    }
}
unsigned int cml_Shape_ComputeLength(cml_Shape* shape) {
    unsigned int length = 1;
    for (int i = 0; i < shape->ndim; i++) {
        length *= shape->values[i];
    }
    return length;
}
void cml_Shape_New1(cml_Shape* shape, unsigned int a) {
    cml_Shape_New(shape, &a, 1);
}
void cml_Shape_New2(cml_Shape* shape, unsigned int a, unsigned int b) {
    unsigned int values[] = {a,b};
    cml_Shape_New(shape, values, 2);
}
void cml_Shape_New3(cml_Shape* shape, unsigned int a, unsigned int b, unsigned int c) {
    unsigned int values[] = {a,b,c};
    cml_Shape_New(shape, values, 3);
}
void cml_Shape_Print(cml_Shape* shape) {
    printf("(");
    for (int i = 0; i < shape->ndim; i ++) {
        printf("%u, ", shape->values[i]);
    }
    printf(")\n");
}

