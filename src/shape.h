#ifndef SHAPE
#define SHAPE

#include <stdio.h>
#include <assert.h>

#define CML_SHAPE_NDIM_SIZE 10

typedef struct cml_Shape {
    unsigned int values[CML_SHAPE_NDIM_SIZE];
    unsigned int ndim;
} cml_Shape;

void cml_Shape_New(cml_Shape* shape, unsigned int* values, unsigned int ndim);
unsigned int cml_Shape_ComputeLength(cml_Shape* shape);
void cml_Shape_New1(cml_Shape* shape, unsigned int a);
void cml_Shape_New2(cml_Shape* shape, unsigned int a, unsigned int b);
void cml_Shape_New3(cml_Shape* shape, unsigned int a, unsigned int b, unsigned int c);
void cml_Shape_Print(cml_Shape* shape);

#endif // SHAPE
