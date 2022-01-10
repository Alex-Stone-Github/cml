#include <stdio.h>
#include "shape.h"
#include "tensor.h"

int main() {
    printf("Hi there\n");

    cml_Shape originS, indexS;
    cml_Tensor origin;
    cml_Shape_New2(&originS, 3, 3);
    cml_Shape_New2(&indexS, 1, 2);
    cml_Tensor_Create(&origin, &originS);
    cml_Tensor_PrintDouble(&origin);
    cml_Shape_Print(&indexS);
    
    unsigned int ind = cml_Tensor_ComputeIndex(&(origin.shape), &indexS);
    printf("%u\n", ind);
    return 0;
}
