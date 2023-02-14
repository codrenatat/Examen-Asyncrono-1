#ifndef INC_1A_EXAM_DATA_H
#define INC_1A_EXAM_DATA_H

//ENUMS//
typedef enum cell_state {
    Free,
    Occupied
} Cell_State;

typedef enum state {
    Healthy,
    Sick,
    Recovered
} State;

typedef enum vaccine {
    True,
    False
} Vaccine;

typedef enum mask {
    Yes,
    No
} Mask;
//ENUMS//

typedef struct cell{
    char letter;
    Cell_State cell_state;
    int id;
    int age;
    State state;
    Vaccine vaccine;
    int days;
    Mask mask;
} Cell;

#endif //INC_1A_EXAM_DATA_H
