#ifndef MODELS
#define MODELS

#include "shape.h"
#include "tensor.h"

typedef struct cml_Dense {
    int ninputNodes;
    int noutputNodes;
    cml_Tensor biases;
    cml_Tensor weights;
} cml_Dense;

void cml_Dense_Create(cml_Dense* dense, int ninputNodes, int noutputNodes);
void cml_Dense_Destroy(cml_Dense* dense);
void cml_Dense_Forward(cml_Dense* dense, cml_Tensor* input, cml_Tensor* output); //WARNING: this creates a new tensor for an output value
void cml_Dense_Backward(cml_Dense* dense, cml_Tensor* prevError, cml_Tensor* output, double lr); //WARNING: this creates a new tensor for an output value

#endif // MODELS
