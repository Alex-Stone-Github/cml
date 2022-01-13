#ifndef TENSOR
#define TENSOR

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shape.h"

typedef struct cml_Tensor {
    cml_Shape shape;
    double* values; 
} cml_Tensor;

void cml_Tensor_Create(cml_Tensor* tensor, cml_Shape* shape);
void cml_Tensor_Destroy(cml_Tensor* tensor);
void cml_Tensor_Clone(cml_Tensor* src, cml_Tensor* dest);
void cml_Tensor_Print(cml_Tensor* tensor);
void cml_Tensor_Fill(cml_Tensor* tensor, double fillValue);
void cml_Tensor_FillWithRandom(cml_Tensor* tensor);
double cml_Tensor_GetValue(cml_Tensor* tensor, cml_Shape* indexShape);
void cml_Tensor_SetValue(cml_Tensor* tensor, cml_Shape* indexShape, double value);
void cml_Tensor_Add(cml_Tensor* a, cml_Tensor* b, cml_Tensor* output);
void cml_Tensor_Sub(cml_Tensor* a, cml_Tensor* b, cml_Tensor* output);
void cml_Tensor_Mul(cml_Tensor* a, cml_Tensor* b, cml_Tensor* output);
void cml_Tensor_Div(cml_Tensor* a, cml_Tensor* b, cml_Tensor* output);
double cml_Tensor_Dot(cml_Tensor* a, cml_Tensor* b);

/*private used by module*/
static unsigned int cml_Tensor_ComputeIndex(cml_Shape* origin, cml_Shape* index);

#endif // TENSOR
