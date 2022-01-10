#include <stdio.h>
#include "shape.h"
#include "tensor.h"

int main() {
    printf("Hi there\n");
    cml_Shape shape;
    cml_Shape_New2(&shape, 3, 4);
    cml_Tensor tensor;
    cml_Tensor_Create(&tensor, &shape);
    cml_Tensor_Print(&tensor);
    return 0;
}
