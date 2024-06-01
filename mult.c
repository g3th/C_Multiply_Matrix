#include <stdio.h>
#define MAX_DATA 1024

typedef struct {
    double data[MAX_DATA];
    int nrows;
    int ncolumns;
} Matrix;

void printMatrix(Matrix M){
    int data_counter = 0;
    printf("\n[");
    for(int i=0; i<M.nrows;i++){
        printf("\n");
        for (int k=0; k<M.ncolumns; k++){
            printf("%.3f  ", M.data[data_counter]);
            data_counter++;
        }
    }
    printf("\n]");
}

Matrix matrixMult(Matrix A, Matrix B)
{   
    Matrix C;
    C.ncolumns = B.ncolumns;
    C.nrows = A.nrows;
    int rows_done = 1;
    int temp=0;
    int data_a=0;
    int data_b=0;
    int index=0;
    double store_value[100];
    while (rows_done <= A.nrows){
        data_a=temp;
        for (int i=0;i<A.nrows;i++){
            for(int j=0; j<B.nrows;j++){
                //printf("%.2f ", A.data[data_a] * B.data[i + data_b]);
                store_value[index] = A.data[data_a] * B.data[i + data_b];
                data_a++;
                index++;
                data_b += 3;
            }
            data_a=temp;
            data_b=0;
        }
        temp += 2;
        rows_done++;
    }
    data_a = 0;
    index = 0;
    for (int k=0;k<A.nrows;k++){
        for (int j=0;j<B.ncolumns;j++){
            if (store_value[data_a]==0.0){
                    break;
            }
            C.data[index] = store_value[data_a] + store_value[data_a+1];
            data_a += 2;
            index++;
        }
    }
  return C;
}

int main(){
    Matrix A = { {1.2, 2.3,
                3.4, 4.5,
                5.6, 6.7},
                3,
                2};
    Matrix B = { {5.5, 6.6, 7.7,
                1.2, 2.1, 3.3},
                2,
                3};
    Matrix C = matrixMult(A, B);
    printMatrix(C);
  return 0;
}
