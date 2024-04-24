
#ifndef _DISCRIMINATIVE_DENSE_NEURAL_NETWORK_FRAMEWORK_NEURAL_NETWORK_FRAMEWORK_H
#define _DISCRIMINATIVE_DENSE_NEURAL_NETWORK_FRAMEWORK_NEURAL_NETWORK_FRAMEWORK_H
#include <iostream>
#include <initializer_list>
#include <vector>
#include <cmath>
extern "C" {
#include "library.h"
}


class Neural_Layer {
private:
    int neurons_in_first_layer, neurons_in_second_layer;

public:
    Matrix weights_matrix;
    Matrix transposed_weights_matrix;
    Matrix bias_matrix;
    Matrix input_matrix;
    Matrix actual_output_matrix;
    Matrix weight_and_input_matrix;
    Matrix weight_input_bias_matrix;
    Matrix activated_output_matrix;
    Matrix dC_dy_matrix;
    Matrix dC_da_matrix;
    Matrix dC_dw_matrix;
    Matrix dC_db_matrix;
    Matrix dh_da_matrix;
    Matrix C;


    // Constructors
    Neural_Layer();
    Neural_Layer(int neuronsInFirstLayer, int neuronsInSecondLayer, const Matrix& inputMatrix);

    // Member functions
    void Compute_Weighted_Sum();
    void Activate();
    void Activate_Last();
    void Dh_Da_Function();
    void Initialize_dC_dy_Matrix();
    void Initialize_Cost_Function_Matrix();

    // Display functions
    static void Display_Layer_Details(const Neural_Layer& layer);
    void Display_Inputs() const;
    void Display_Weights() const;
    void Display_Weighted_Sum() const;
    void Display_Bias_Weighted_Sum() const;
    void Display_Bias() const;
    void Display_Activated_Output() const;
    void Display_Activated_Function_Derivatives() const;

private:
    // Static member functions
    static float Sigmoid_Function(float x);
    static float ReLU(float x);
    static float LeakyReLU(float x, float alpha);
    static float ELU(float x, float alpha);
    static float Swish(float x);
    static float Tanh(float x);

};

Matrix* Neural_Layer_Maker(int neurones_In_First_Layer, int neurones_In_Second_Layer,Matrix inputMatrix);
void  Forward_Pass(std::vector<Neural_Layer>&neural_layers, std::initializer_list<int> layers, Matrix inputMatrix);
void Back_Propagation(std::vector<Neural_Layer>&neural_layers, std::initializer_list<int> layers,Matrix output,float &mean_squared_error);
void Matrix_Transpose_v2(Matrix *final, const Matrix original) ;
void Matrix_Multiply_V2(Matrix *finalMatrix, Matrix firstMatrix, Matrix secondMatrix);
void Display_Gradients(const std::vector<Neural_Layer>&neural_layers, std::initializer_list<int> layers);
Matrix Matrix_Maker_2DArray_v2(int maxColumns, int totalRows, int desiredRows, int desiredColumns, int stride, int step, const float *data);
void Matrix_Broadcast(Matrix *result, const Matrix original, const int newRows,const int newColumns);
void Matrix_Scalar_Multiply(Matrix &matrix, float scalar);
float Matrix_Sum_All_Elements(const Matrix& matrix);
void Matrix_Power(Matrix& matrix, float power);
void Matrix_Hadamard_Product(Matrix &result, const Matrix &a, const Matrix &b);
void Matrix_Absolute(Matrix &matrix);
void Learn(std::vector<Neural_Layer>&neural_layers, std::initializer_list<int> layers,double learning_rate, int iterations);
void fillMatrix(Matrix& matrix, float value);
std::vector<Neural_Layer> Form_Network(std::initializer_list<int> layers, Matrix inputMatrix);
void Learn(std::vector<Neural_Layer>&neural_layers, std::initializer_list<int> layers,Matrix input_matrix, Matrix output_matrix, float learning_rate, int iterations);
void Matrix_Copy(Matrix *destination, const Matrix *source);
void Matrix_Sum_Columns(Matrix &dest, const Matrix &src);
void Matrix_Fill(Matrix& matrix, float value);
void Matrix_Subtract_V2(Matrix& result, const Matrix& matrix1, const Matrix& matrix2);
std::vector<Neural_Layer> Form_Network(std::initializer_list<int> layers, int sample_size);



#endif //_DISCRIMINATIVE_DENSE_NEURAL_NETWORK_FRAMEWORK_NEURAL_NETWORK_FRAMEWORK_H