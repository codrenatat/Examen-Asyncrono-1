#include "Print.h"
#include "Data.h"
#include "stdio.h"

void Print_Matrix(Cell matrix[30][30]) {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if ((*(matrix + i) + j)->cell_state == Occupied) {
                if ((*(matrix + i) + j)->state == Healthy &&(*(matrix + i) + j)->vaccine == False &&(*(matrix + i) + j)->mask == No) {
                    printf( " S" );
                } else if ((*(matrix + i) + j)->state == Healthy &&(*(matrix + i) + j)->vaccine == False &&(*(matrix + i) + j)->mask == Yes) {
                    printf( " s" );
                } else if ((*(matrix + i) + j)->state == Healthy &&(*(matrix + i) + j)->vaccine == True &&(*(matrix + i) + j)->mask == No) {
                    printf( " V" );
                } else if ((*(matrix + i) + j)->state == Healthy &&(*(matrix + i) + j)->vaccine == True &&(*(matrix + i) + j)->mask == Yes) {
                    printf( " v" );
                } else if ((*(matrix + i) + j)->state == Sick &&(*(matrix + i) + j)->mask == No) {
                    printf( " E" );
                } else if ((*(matrix + i) + j)->state == Sick &&(*(matrix + i) + j)->mask == Yes) {
                    printf(" e" );
                } else if ((*(matrix + i) + j)->state == Recovered) {
                    printf( " r" );
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}