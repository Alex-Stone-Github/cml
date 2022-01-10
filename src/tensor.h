#ifndef TENSOR
#define TENSOR

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shape.h"

#define TENSOR_TYPE double

typedef struct cml_Tensor {
    cml_Shape shape;
    TENSOR_TYPE* values; 
} cml_Tensor;

void cml_Tensor_Create(cml_Tensor* tensor, cml_Shape* shape);
void cml_Tensor_Destroy(cml_Tensor* tensor);
void cml_Tensor_Clone(cml_Tensor* src, cml_Tensor* dest);
void cml_Tensor_Print(cml_Tensor* tensor);

#endif // TENSOR
