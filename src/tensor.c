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
void cml_Tensor_Print(cml_Tensor* tensor) {
    cml_Shape_Print(&(tensor->shape));
    unsigned int length = cml_Shape_ComputeLength(&(tensor->shape));
    for (unsigned int i = 0; i < length; i ++) {
        printf("%lf, ", tensor->values[i]);
    }
    printf("\n");
}
