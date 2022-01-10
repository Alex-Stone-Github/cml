#include "tensor.h"

void cml_Tensor_Create(cml_Tensor* tensor, cml_Shape* shape) {
    memcpy(&(tensor->shape), shape, sizeof(cml_Shape)); // copy shape
    unsigned int length = cml_Shape_ComputeLength(shape);
    tensor->values = (TENSOR_TYPE*)malloc(length * sizeof(TENSOR_TYPE));
}
void cml_Tensor_Destroy(cml_Tensor* tensor) {
    free(tensor->values);
}
void cml_Tensor_Clone(cml_Tensor* src, cml_Tensor* dest) {
    memcpy(src, dest, sizeof(cml_Tensor));
    unsigned int length = cml_Shape_ComputeLength(&(dest->shape));
    dest->values = (TENSOR_TYPE*)malloc(length * sizeof(TENSOR_TYPE));
    memcpy(src->values, dest->values, length * sizeof(TENSOR_TYPE));
}
void cml_Tensor_PrintDouble(cml_Tensor* tensor) {
    cml_Shape_Print(&(tensor->shape));
    unsigned int length = cml_Shape_ComputeLength(&(tensor->shape));
    for (unsigned int i = 0; i < length; i ++) {
        printf("%lf, ", tensor->values[i]);
    }
    printf("\n");
}
void cml_Tensor_Fill(cml_Tensor* tensor, TENSOR_TYPE fillValue) {
    for (unsigned int i = 0; i < cml_Shape_ComputeLength(&(tensor->shape)); i ++) {
        tensor->values[i] = fillValue;
    }
}
void cml_Tensor_FillWithRandom(cml_Tensor* tensor) {
    for (unsigned int i = 0; i < cml_Shape_ComputeLength(&(tensor->shape)); i ++) {
        tensor->values[i] = (TENSOR_TYPE)((float)(rand() % 1000) / 1000.0f);
    }
}
unsigned int cml_Tensor_ComputeIndex(cml_Shape* origin, cml_Shape* index) {
    unsigned int indexValue = 0;
    for (int i = 0; i < index->ndim; i ++) {
        if (i + 1 != origin->ndim) {
            indexValue += index->values[i] * origin->values[i + 1];
        }
        else {
            indexValue += index->values[i];
        }
    }
    return indexValue;
}
