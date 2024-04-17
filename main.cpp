#include <iostream>
#include <vector>
#include "Neural Network Framework.h"

int main(){
    // Seed the random number generator
    srand((unsigned) time(NULL));
    float data[][3]={
            {1,0,1},
            {0,1,0},
            {1,1,1},
            {0,0,0}
    };
    size_t sizeOfData=sizeof(data)/sizeof(data[0]);

    Matrix inputs= Matrix_Maker_2DArray(3, 4, 2, 0, &data[0][0]);
    Matrix_Display(inputs);
//    Matrix modifiedInput= Matrix_Create_Zero(inputs.column, inputs.row);
//
//    size_t dataSize=sizeof(modifiedInput.data);
//    Matrix_Display(modifiedInput);
//    printf("%zu",dataSize);
//    printf("----------\n");
    Matrix output= Matrix_Maker_2DArray(3,4,1,2,&data[0][0]);
    Matrix_Display(output);

    std::vector g= Forward_Pass({3, 2, 1}, inputs);
    Back_Propagation(g, {3, 2, 1},output);
//    Display_Gradients(g,{4,3,2,1});
}





