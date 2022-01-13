#include "models.h"

void cml_Dense_Create(cml_Dense* dense, int ninputNodes, int noutputNodes) {
    cml_Shape weightShape, biasShape;
    cml_Shape_New2(&weightShape, noutputNodes, ninputNodes);
    cml_Shape_New1(&biasShape, noutputNodes);
    dense->ninputNodes = ninputNodes;
    dense->noutputNodes = noutputNodes;
    cml_Tensor_Create(&(dense->weights), &weightShape);
    cml_Tensor_Create(&(dense->biases), &biasShape);
    cml_Tensor_FillWithRandom(&(dense->weights));
    cml_Tensor_FillWithRandom(&(dense->biases));
} 
void cml_Dense_Destroy(cml_Dense* dense) {
    cml_Tensor_Destroy(&(dense->weights));
    cml_Tensor_Destroy(&(dense->biases));
}
void cml_Dense_Forward(cml_Dense* dense, cml_Tensor* input, cml_Tensor* output) {
    // Creates a new tensor at specified input address
    cml_Shape nshape;
    cml_Shape_New1(&nshape, dense->noutputNodes);
    cml_Tensor_Destroy(output); // just make sure
    cml_Tensor_Create(output, &nshape);

    cml_Tensor current;
    cml_Tensor_Create(&current, &nshape);
    cml_Tensor_Fill(&current, 0.0);
    for (int i = 0; i < dense->noutputNodes; i ++) {
        for (int j = 0; j < dense->ninputNodes; j ++) {
            // just setup for index shapes
            cml_Shape currentIndexWeights;cml_Shape_New2(&currentIndexWeights, i, j);
            cml_Shape currentIndexInput;cml_Shape_New1(&currentIndexInput, i);

            double weightConnection = cml_Tensor_GetValue(&(dense->weights), &currentIndexWeights);
            double inputValue = cml_Tensor_GetValue(input, &currentIndexInput);
            cml_Tensor_SetValue(&(dense->weights), &currentIndexWeights, weightConnection * inputValue);
        }
    }
    cml_Tensor_Add(&(dense->biases), &current, output);
    cml_Tensor_Destroy(&current);
}
void cml_Dense_Backward(cml_Dense* dense, cml_Tensor* prevError, cml_Tensor* output, double lr) {
    // Adjust weights
    for (int i = 0; i < dense->noutputNodes; i ++) {
        for (int j = 0; j < dense->ninputNodes; j ++) {
            cml_Shape currentIndexWeights;cml_Shape_New2(&currentIndexWeights, i, j);
            cml_Shape currentIndexPrevError;cml_Shape_New1(&currentIndexPrevError, i);

            double currentWeight = cml_Tensor_GetValue(&(dense->weights), &currentIndexWeights);
            double currentPrevError = cml_Tensor_GetValue(prevError, &currentIndexPrevError);

            cml_Tensor_SetValue(&(dense->weights), &currentIndexWeights, (currentWeight + currentPrevError) * lr); 
        }
    }
    // Compute next error
    cml_Shape nshape;cml_Shape_New1(&nshape, dense->ninputNodes);
    cml_Tensor_Create(output, &nshape);
    cml_Tensor_Fill(output, 0.0);
    for (int i = 0; i < dense->noutputNodes; i ++) {
        for (int j = 0; j < dense->ninputNodes; j ++) {
            cml_Shape currentIndexWeights;cml_Shape_New2(&currentIndexWeights, i, j);
            cml_Shape currentIndexPrevError;cml_Shape_New1(&currentIndexPrevError, i);
            cml_Shape currentIndexNError;cml_Shape_New1(&currentIndexNError, j);
            
            double currentWeight = cml_Tensor_GetValue(&(dense->weights), &currentIndexWeights);
            double currentPrevError = cml_Tensor_GetValue(prevError, &currentIndexPrevError);
            double currentNError = cml_Tensor_GetValue(output, &currentIndexNError);
            double nerror = currentPrevError * currentWeight;

            cml_Tensor_SetValue(output, &currentIndexNError, nerror + currentNError);
        }
    }
}
