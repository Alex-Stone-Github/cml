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
void cml_Tensor_PrintDouble(cml_Tensor* tensor);
void cml_Tensor_Fill(cml_Tensor* tensor, TENSOR_TYPE fillValue);
void cml_Tensor_FillWithRandom(cml_Tensor* tensor);

/*private used by module*/
unsigned int cml_Tensor_ComputeIndex(cml_Shape* origin, cml_Shape* index);
#endif // TENSOR
