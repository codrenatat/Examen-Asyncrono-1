#include <stdio.h>
#include <stdlib.h>
#include "Data.h"
#include "Init.h"
#include "Print.h"
#include "Cycle.h"

int main() {
    Cell matrix[30][30];
    Cell matrix_changed[30][30];
    Init_Matrix(matrix);

    int input;

    do{
        printf("\n Press 1 to run.\n");
        scanf("%d", &input);
        if(input == 1){
            Print_Matrix(matrix);
            Cycle(matrix, matrix_changed);
        } else {
            EXIT_FAILURE;
        }
    } while (input == 1);
}
