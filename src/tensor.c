#include "tensor.h"

void cml_Tensor_Create(cml_Tensor* tensor, cml_Shape* shape) {
    memcpy(&(tensor->shape), shape, sizeof(cml_Shape)); // copy shape
    unsigned int length = cml_Shape_ComputeLength(shape);
    tensor->values = (double*)malloc(length * sizeof(double));
}
void cml_Tensor_Destroy(cml_Tensor* tensor) {
    free(tensor->values);
}
void cml_Tensor_Clone(cml_Tensor* src, cml_Tensor* dest) {
    memcpy(src, dest, sizeof(cml_Tensor));
    unsigned int length = cml_Shape_ComputeLength(&(dest->shape));
    dest->values = (double*)malloc(length * sizeof(double));
    memcpy(src->values, dest->values, length * sizeof(double));
}
void cml_Tensor_Print(cml_Tensor* tensor) {
    cml_Shape_Print(&(tensor->shape));
    unsigned int length = cml_Shape_ComputeLength(&(tensor->shape));
    for (unsigned int i = 0; i < length; i ++) {
        printf("%lf, ", tensor->values[i]);
    }
    printf("\n");
}
void cml_Tensor_Fill(cml_Tensor* tensor, double fillValue) {
    for (unsigned int i = 0; i < cml_Shape_ComputeLength(&(tensor->shape)); i ++) {
        tensor->values[i] = fillValue;
    }
}
void cml_Tensor_FillWithRandom(cml_Tensor* tensor) {
    for (unsigned int i = 0; i < cml_Shape_ComputeLength(&(tensor->shape)); i ++) {
        tensor->values[i] = (double)((float)(rand() % 1000) / 1000.0f);
    }
}
static unsigned int cml_Tensor_ComputeIndex(cml_Shape* origin, cml_Shape* index) {
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
double cml_Tensor_GetValue(cml_Tensor* tensor, cml_Shape* indexShape) {
    unsigned int index = cml_Tensor_ComputeIndex(&(tensor->shape), indexShape);
    return tensor->values[index];
}
void cml_Tensor_SetValue(cml_Tensor* tensor, cml_Shape* indexShape, double value) {
    unsigned int index = cml_Tensor_ComputeIndex(&(tensor->shape), indexShape);
    tensor->values[index] = value;
}
void cml_Tensor_Add(cml_Tensor* a, cml_Tensor* b, cml_Tensor* output) {
    unsigned int length = cml_Shape_ComputeLength(&(a->shape));
    for (unsigned int i = 0; i < length; i ++) {
        output->values[i] = a->values[i] + b->values[i];
    }
}
void cml_Tensor_Sub(cml_Tensor* a, cml_Tensor* b, cml_Tensor* output) {
    unsigned int length = cml_Shape_ComputeLength(&(a->shape));
    for (unsigned int i = 0; i < length; i ++) {
        output->values[i] = a->values[i] - b->values[i];
    }
}
void cml_Tensor_Mul(cml_Tensor* a, cml_Tensor* b, cml_Tensor* output) {
    unsigned int length = cml_Shape_ComputeLength(&(a->shape));
    for (unsigned int i = 0; i < length; i ++) {
        output->values[i] = a->values[i] * b->values[i];
    }
}
void cml_Tensor_Div(cml_Tensor* a, cml_Tensor* b, cml_Tensor* output) {
    unsigned int length = cml_Shape_ComputeLength(&(a->shape));
    for (unsigned int i = 0; i < length; i ++) {
        output->values[i] = a->values[i] / b->values[i];
    }
}
double cml_Tensor_Dot(cml_Tensor* a, cml_Tensor* b) {
    unsigned int length = cml_Shape_ComputeLength(&(a->shape));
    double output = 0;
    for (unsigned int i = 0; i < length; i ++) {
        output += a->values[i] + b->values[i];
    }
    return output;
}
