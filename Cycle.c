#include "Cycle.h"
#include "Data.h"
#include "stdlib.h"

void Cycle(Cell matrix[30][30], Cell matrix_changed[30][30]) {
    int up_cell;
    int down_cell;
    int left_cell;
    int right_cell;
    int probability;

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            up_cell = i - 1;
            down_cell = i + 1;
            right_cell = j + 1;
            left_cell = j - 1;
                //_ _ _
                //_ E _
                //_ _ _
            if ((*(matrix + i) + j)->state == Sick) {
                if ((*(matrix + i) + j)->days >= 9) {
                    (*(matrix + i) + j)->state = Recovered;
                    (*(matrix + i) + j)->letter = 'r';
                } else {
                    (*(matrix + i) + j)->state = Sick;
                    (*(matrix + i) + j)->days++;
                }

                //* _ _
                //_ E _
                //_ _ _
                if ((*(matrix + up_cell) + left_cell)->state == Healthy) {
                    if ((*(matrix + up_cell) + left_cell)->mask == No && (*(matrix + i) + j)->mask == No) {
                        if ((*(matrix + up_cell) + left_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <= 90) {
                                (*(matrix_changed + up_cell) + left_cell)->state = Sick;
                                (*(matrix + up_cell) + left_cell)->days = 0;
                            }
                        } else if ((*(matrix + up_cell) + left_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=45) {
                                (*(matrix_changed + up_cell) + left_cell)->state = Sick;
                                (*(matrix + up_cell) + left_cell)->days = 0;
                            }
                        }
                    }
                    if (((*(matrix + up_cell) + left_cell)->mask == No && (*(matrix + i) + j)->mask == Yes) || (*(matrix + up_cell) + left_cell)->mask == Yes && (*(matrix + i) + j)->mask == No) {
                        if ((*(matrix + up_cell) + left_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <= 20) {
                                (*(matrix_changed + up_cell) + left_cell)->state = Sick;
                                (*(matrix + up_cell) + left_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + up_cell) + left_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=15) {
                                (*(matrix_changed + up_cell) + left_cell)->state = Sick;
                                (*(matrix + up_cell) + left_cell)->days = 0;
                            }
                        }
                    }
                    if ((*(matrix + up_cell) + left_cell)->mask == Yes && (*(matrix + i) + j)->mask == Yes) {
                        if ((*(matrix + up_cell) + left_cell)->vaccine ==  False) {
                            probability = rand() % 100;
                            if (probability <= 10) {
                                (*(matrix_changed + up_cell) + left_cell)->state = Sick;
                                (*(matrix + up_cell) + left_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + up_cell) + left_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=5) {
                                (*(matrix_changed + up_cell) + left_cell)->state = Sick;
                                (*(matrix + up_cell) + left_cell)->days = 0;
                            }
                        }
                    }
                }

                //_ * _
                //_ E _
                //_ _ _
                if ((*(matrix + up_cell) + j)->state == Healthy) {
                    if ((*(matrix + up_cell) + j)->mask == No && (*(matrix + i) + j)->mask == No) {
                        if ((*(matrix + up_cell) + j)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=90) {
                                (*(matrix_changed + up_cell) + left_cell)->state = Sick;
                                (*(matrix + up_cell) + left_cell)->days = 0;
                            }
                        } else if ((*(matrix + up_cell) + j)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <= 45) {
                                (*(matrix_changed + up_cell) + left_cell)->state = Sick;
                                (*(matrix + up_cell) + left_cell)->days = 0;
                            }
                        }
                    }
                    if (((*(matrix + up_cell) + j)->mask == No && (*(matrix + i) + j)->mask == Yes) || (*(matrix + up_cell) + j)->mask == Yes && (*(matrix + i) + j)->mask == No) {
                        if ((*(matrix + up_cell) + j)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=20) {
                                (*(matrix_changed + up_cell) + left_cell)->state = Sick;
                                (*(matrix + up_cell) + left_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + up_cell) + j)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <= 15) {
                                (*(matrix_changed + up_cell) + left_cell)->state = Sick;
                                (*(matrix + up_cell) + left_cell)->days = 0;
                            }
                        }
                    }
                    if ((*(matrix + up_cell) + j)->mask == Yes && (*(matrix + i) + j)->mask == Yes) {
                        if ((*(matrix + up_cell) + j)->vaccine ==  False) {
                            probability = rand() % 100;
                            if (probability <= 10) {
                                (*(matrix_changed + up_cell) + left_cell)->state = Sick;
                                (*(matrix + up_cell) + left_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + up_cell) + j)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <= 5) {
                                (*(matrix_changed + up_cell) + left_cell)->state = Sick;
                                (*(matrix + up_cell) + left_cell)->days = 0;
                            }
                        }
                    }
                }
                //_ _ *
                //_ E _
                //_ _ _
                if ((*(matrix + up_cell) + right_cell)->state == Healthy) {
                    if ((*(matrix + up_cell) + right_cell)->mask == No && (*(matrix + i) + j)->mask == No) {
                        if ((*(matrix + up_cell) + right_cell)->vaccine ==  False) {
                            probability = rand() % 100;
                            if (probability <= 90) {
                                (*(matrix_changed + up_cell) + right_cell)->state =  Sick;
                                (*(matrix + up_cell) + right_cell)->days = 0;
                            }
                        } else if ((*(matrix + up_cell) + right_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=45) {
                                (*(matrix_changed + up_cell) + right_cell)->state =  Sick;
                                (*(matrix + up_cell) + right_cell)->days = 0;
                            }
                        }
                    }
                    if (((*(matrix + up_cell) + right_cell)->mask == No &&(*(matrix + i) + j)->mask == Yes) ||(*(matrix + up_cell) + right_cell)->mask == Yes &&(*(matrix + i) + j)->mask ==No) {
                        if ((*(matrix + up_cell) + right_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=20) {
                                (*(matrix_changed + up_cell) + right_cell)->state =  Sick;
                                (*(matrix + up_cell) + right_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + up_cell) + right_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <= 15) {
                                (*(matrix_changed + up_cell) + right_cell)->state =  Sick;
                                (*(matrix + up_cell) + right_cell)->days = 0;
                            }
                        }
                    }
                    if ((*(matrix + up_cell) + right_cell)->mask == Yes &&(*(matrix + i) + j)->mask == Yes) {
                        if ((*(matrix + up_cell) + right_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=10) {
                                (*(matrix_changed + up_cell) + right_cell)->state = Sick;
                                (*(matrix + up_cell) + right_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + up_cell) + right_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=5) {
                                (*(matrix_changed + up_cell) + right_cell)->state = Sick;
                                (*(matrix + up_cell) + right_cell)->days = 0;
                            }
                        }
                    }
                }
                //_ _ _
                //* E _
                //_ _ _
                if ((*(matrix + i) + left_cell)->state == Healthy) {
                    if ((*(matrix + i) + left_cell)->mask == No && (*(matrix + i) + j)->mask == No) {
                        if ((*(matrix + i) + left_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=90) {
                                (*(matrix_changed + i) + left_cell)->state = Sick;
                                (*(matrix + i) + left_cell)->days = 0;
                            }
                        } else if ((*(matrix + i) + left_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=45) {
                                (*(matrix_changed + i) + left_cell)->state = Sick;
                                (*(matrix + i) + left_cell)->days = 0;
                            }
                        }
                    }
                    if (((*(matrix + i) + left_cell)->mask == No &&(*(matrix + i) + j)->mask == Yes) ||(*(matrix + i) + left_cell)->mask == Yes &&(*(matrix + i) + j)->mask ==No) {
                        if ((*(matrix + i) + left_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=20) {
                                (*(matrix_changed + i) + left_cell)->state = Sick;
                                (*(matrix + i) + left_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + i) + left_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=15) {
                                (*(matrix_changed + i) + left_cell)->state = Sick;
                                (*(matrix + i) + left_cell)->days = 0;
                            }
                        }
                    }
                    if ((*(matrix + i) + left_cell)->mask == Yes &&(*(matrix + i) + j)->mask == Yes) {
                        if ((*(matrix + i) + left_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=10) {
                                (*(matrix_changed + i) + left_cell)->state = Sick;
                                (*(matrix + i) + left_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + i) + left_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=5) {
                                (*(matrix_changed + i) + left_cell)->state = Sick;
                                (*(matrix + i) + left_cell)->days = 0;
                            }
                        }
                    }
                }
                //_ _ _
                //_ E *
                //_ _ _
                if ((*(matrix + i) + right_cell)->state == Healthy) {
                    if ((*(matrix + i) + right_cell)->mask == No &&(*(matrix + i) + j)->mask ==No) {
                        if ((*(matrix + i) + right_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=90) {
                                (*(matrix_changed + i) + right_cell)->state = Sick;
                                (*(matrix + i) + right_cell)->days = 0;
                            }
                        } else if ((*(matrix + i) + right_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=45) {
                                (*(matrix_changed + i) + right_cell)->state = Sick;
                                (*(matrix + i) + right_cell)->days = 0;
                            }
                        }
                    }
                    if (((*(matrix + i) + right_cell)->mask == No &&(*(matrix + i) + j)->mask == Yes) ||(*(matrix + i) + right_cell)->mask == Yes &&(*(matrix + i) + j)->mask ==No) {
                        if ((*(matrix + i) + right_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=20) {
                                (*(matrix_changed + i) + right_cell)->state = Sick;
                                (*(matrix + i) + right_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + i) + right_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=15) {
                                (*(matrix_changed + i) + right_cell)->state = Sick;
                                (*(matrix + i) + right_cell)->days = 0;
                            }
                        }
                    }
                    if ((*(matrix + i) + right_cell)->mask == Yes &&(*(matrix + i) + j)->mask == Yes) {
                        if ((*(matrix + i) + right_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=10) {
                                (*(matrix_changed + i) + right_cell)->state = Sick;
                                (*(matrix + i) + right_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + i) + right_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=5) {
                                (*(matrix_changed + i) + right_cell)->state = Sick;
                                (*(matrix + i) + right_cell)->days = 0;
                            }
                        }
                    }
                }
                //_ _ _
                //_ E _
                //* _ _
                if ((*(matrix + down_cell) + left_cell)->state == Healthy) {
                    if ((*(matrix + down_cell) + left_cell)->mask == No &&(*(matrix + i) + j)->mask ==No) {
                        if ((*(matrix + down_cell) + left_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=90) {
                                (*(matrix_changed + down_cell) + left_cell)->state = Sick;
                                (*(matrix + down_cell) + left_cell)->days = 0;
                            }
                        } else if ((*(matrix + down_cell) + left_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=45) {
                                (*(matrix_changed + down_cell) + left_cell)->state = Sick;
                                (*(matrix + down_cell) + left_cell)->days = 0;
                            }
                        }
                    }
                    if (((*(matrix + down_cell) + left_cell)->mask == No &&(*(matrix + i) + j)->mask == Yes) ||(*(matrix + down_cell) + left_cell)->mask == Yes &&(*(matrix + i) + j)->mask ==No) {
                        if ((*(matrix + down_cell) + left_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=20) {
                                (*(matrix_changed + down_cell) + left_cell)->state = Sick;
                                (*(matrix + down_cell) + left_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + down_cell) + left_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=15) {
                                (*(matrix_changed + down_cell) + left_cell)->state = Sick;
                                (*(matrix + down_cell) + left_cell)->days = 0;
                            }
                        }
                    }
                    if ((*(matrix + down_cell) + left_cell)->mask == Yes &&(*(matrix + i) + j)->mask == Yes) {
                        if ((*(matrix + down_cell) + left_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=10) {
                                (*(matrix_changed + down_cell) + left_cell)->state = Sick;
                                (*(matrix + down_cell) + left_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + down_cell) + left_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=5) {
                                (*(matrix_changed + down_cell) + left_cell)->state = Sick;
                                (*(matrix + down_cell) + left_cell)->days = 0;
                            }
                        }
                    }
                }
                //_ _ _
                //_ E _
                //_ * _
                if ((*(matrix + down_cell) + j)->state == Healthy) {
                    if ((*(matrix + down_cell) + j)->mask == No &&(*(matrix + i) + j)->mask ==No) {
                        if ((*(matrix + down_cell) + j)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=90) {
                                (*(matrix_changed + down_cell) + j)->state = Sick;
                                (*(matrix + down_cell) + j)->days = 0;
                            }
                        } else if ((*(matrix + down_cell) + j)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=45) {
                                (*(matrix_changed + down_cell) + j)->state = Sick;
                                (*(matrix + down_cell) + j)->days = 0;
                            }
                        }
                    }
                    if (((*(matrix + down_cell) + j)->mask == No &&(*(matrix + i) + j)->mask == Yes) || (*(matrix + down_cell) + j)->mask == Yes &&(*(matrix + i) + j)->mask ==No) {
                        if ((*(matrix + down_cell) + j)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=20) {
                                (*(matrix_changed + down_cell) + j)->state = Sick;
                                (*(matrix + down_cell) + j)->days = 0;
                            }
                        }
                        if ((*(matrix + down_cell) + j)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <= 15) {
                                (*(matrix_changed + down_cell) + j)->state = Sick;
                                (*(matrix + down_cell) + j)->days = 0;
                            }
                        }
                    }
                    if ((*(matrix + down_cell) + j)->mask == Yes &&(*(matrix + i) + j)->mask == Yes) {
                        if ((*(matrix + down_cell) + j)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=10) {
                                (*(matrix_changed + down_cell) + j)->state = Sick;
                                (*(matrix + down_cell) + j)->days = 0;
                            }
                        }
                        if ((*(matrix + down_cell) + j)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=5) {
                                (*(matrix_changed + down_cell) + j)->state = Sick;
                                (*(matrix + down_cell) + j)->days = 0;
                            }
                        }
                    }
                }
                //_ _ _
                //_ E _
                //_ _ *
                if ((*(matrix + down_cell) + right_cell)->state == Healthy) {
                    if ((*(matrix + down_cell) + right_cell)->mask == No &&(*(matrix + i) + j)->mask ==No) {
                        if ((*(matrix + down_cell) + right_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=90) {
                                (*(matrix_changed + down_cell) + right_cell)->state = Sick;
                                (*(matrix + down_cell) + right_cell)->days = 0;
                            }
                        } else if ((*(matrix + down_cell) + right_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=45) {
                                (*(matrix_changed + down_cell) + right_cell)->state = Sick;
                                (*(matrix + down_cell) + right_cell)->days = 0;
                            }
                        }
                    }
                    if (((*(matrix + down_cell) + right_cell)->mask == No &&(*(matrix + i) + j)->mask == Yes) ||(*(matrix + down_cell) + right_cell)->mask == Yes &&(*(matrix + i) + j)->mask ==No) {
                        if ((*(matrix + down_cell) + right_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=20) {
                                (*(matrix_changed + down_cell) + right_cell)->state = Sick;
                                (*(matrix + down_cell) + right_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + down_cell) + right_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=15) {
                                (*(matrix_changed + down_cell) + right_cell)->state = Sick;
                                (*(matrix + down_cell) + right_cell)->days = 0;
                            }
                        }
                    }
                    if ((*(matrix + down_cell) + right_cell)->mask == Yes &&(*(matrix + i) + j)->mask == Yes) {
                        if ((*(matrix + down_cell) + right_cell)->vaccine == False) {
                            probability = rand() % 100;
                            if (probability <=10) {
                                (*(matrix_changed + down_cell) + right_cell)->state = Sick;
                                (*(matrix + down_cell) + right_cell)->days = 0;
                            }
                        }
                        if ((*(matrix + down_cell) + right_cell)->vaccine == True) {
                            probability = rand() % 100;
                            if (probability <=5) {
                                (*(matrix_changed + down_cell) + right_cell)->state = Sick;
                                (*(matrix + down_cell) + right_cell)->days = 0;
                            }
                        }
                    }
                }
            }
            (*(matrix + i) + j)->days++;
        }
    }
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if (((*(matrix + i) + j)->state == Healthy) &&
                ((*(matrix_changed + i) + j)->state ==  Sick)) {
                (*(matrix + i) + j)->state =  Sick;
            }
        }
    }
}