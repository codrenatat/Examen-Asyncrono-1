#include "Init.h"
#include "Data.h"
#include "stdlib.h"
void Init_Matrix(Cell matrix[30][30]){
    int new_cell_id = 0;
    int new_cell_age;
    int matrix_cells;

    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++){
            (*(matrix + i) + j)->id = new_cell_id; //Asignamos un identificador por persona unico e irrepetible.

            new_cell_age = rand() % 90;
            (*(matrix + i) + j)->age = new_cell_age; //Asignamos la edad random de 1-90.

            matrix_cells = rand() % 900; //Inicializamos los 900 lugares de la matriz al azar.

            // A continuacion estableceremos las condiciones del 60% de las celdas.
            if(matrix_cells <= 540){
                matrix_cells = rand() % 540; //Inicializamos las condiciones sigientes al 60% de la matriz al azar.
                (*(matrix + i) + j)->cell_state = Occupied;
                (*(matrix + i) + j)->state = Healthy;
                if(matrix_cells <= 135){ //Sin vacciner y sin mask.
                    (*(matrix + i) + j)->vaccine = False;
                    (*(matrix + i) + j)->mask = No;
                    (*(matrix + i) + j)->letter = 'S';
                }else if (matrix_cells <= 270) { // Sin vacciner y con mask
                    (*(matrix + i) + j)->vaccine = False;
                    (*(matrix + i) + j)->mask = Yes;
                    (*(matrix + i) + j)->letter = 's';
                } else if (matrix_cells <= 405) { // vaccinedos y sin mask
                    (*(matrix + i) + j)->vaccine = True;
                    (*(matrix + i) + j)->mask = No;
                    (*(matrix + i) + j)->letter = 'V';
                }else {//vaccinedos con mask
                    (*(matrix + i) + j)->vaccine = True;
                    (*(matrix + i) + j)->mask = Yes;
                    (*(matrix + i) + j)->letter='v';
                }
            }
                //60%Fin
                //40%
            else{
                (*(matrix+i)+j)->cell_state = Free;
                (*(matrix + i) + j)->letter = ' ';
            }//40%Fin
        }
    }

    matrix_cells = rand() % 30;
    int sick_cell = rand() % 30;
    (*(matrix + matrix_cells) + sick_cell)->state = Sick;
    (*(matrix + matrix_cells) + sick_cell)->cell_state = Occupied;
    (*(matrix + matrix_cells) + sick_cell)->days = 0;
    new_cell_id = rand() % 2;
    if (new_cell_id == 1) {
        (*(matrix + matrix_cells) + sick_cell)->letter = 'E';
        (*(matrix + matrix_cells) + sick_cell)->mask = No;
    }
    else {
        (*(matrix + matrix_cells) + sick_cell)->letter = 'e';
        (*(matrix + matrix_cells) + sick_cell)->mask = Yes;
    }
}
