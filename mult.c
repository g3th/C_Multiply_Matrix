#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double *data;
  int nrows;
  int ncols;
} Matrix;

void matrixMult(Matrix *A, Matrix *B, Matrix *C)
{   
    C->ncols = B->ncols;
    C->nrows = A->nrows;
    int rows_done = 1;
    int temp=0;
    int data_a=0;
    int data_b=0;
    int index=0;
    double store_value[100];
    while (rows_done <= A->nrows){
        data_a=temp;
        for (int i=0;i<A->nrows;i++){
            for(int j=0; j<B->nrows;j++){
                //printf("%.2f ", A.data[data_a] * B.data[i + data_b]);
                store_value[index] = A->data[data_a] * B->data[i + data_b];
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
    for (int k=0;k<A->nrows;k++){
        for (int j=0;j<B->ncols;j++){
            if (store_value[data_a]==0.0){
                    break;
            }
            C->data[index] = store_value[data_a] + store_value[data_a+1];
            data_a += 2;
            index++;
        }
    }
}

void destroyMatrix(Matrix *M)
{
  free(M->data);
  free(M);
}

Matrix *createMatrix(int rows, int cols){
  int matrix_size = rows * cols;
  Matrix *m = (Matrix*)malloc(sizeof(Matrix));
  m->data = (double*)malloc(sizeof(double) * matrix_size);
  m->nrows = rows;
  m->ncols = cols;
  return m;
}


void printMatrix(Matrix *m){
  int d = 0;
  int rows = m->nrows;
  int columns = m->ncols;
  printf("[\n");
  for (int j=0; j<m->nrows;j++){
    for (int i=0; i<m->ncols;i++){
      printf(" %.3f ",m->data[d]);
      d++;
    }
    printf("\n"); 
  }
  printf("]\n\n");
}

int main(){
  Matrix *A = createMatrix(3, 2);
  A->data[0] = 1.2;
  A->data[1] = 2.3;
  A->data[2] = 3.4;
  A->data[3] = 4.5;
  A->data[4] = 5.6;
  A->data[5] = 6.7;
  printMatrix(A);
  Matrix *B = createMatrix(2, 3);
  B->data[0] = 5.5;
  B->data[1] = 6.6;
  B->data[2] = 7.7;
  B->data[3] = 1.2;
  B->data[4] = 2.1;
  B->data[5] = 3.3;
  printMatrix(B);
  Matrix *C = createMatrix(3, 3);
  matrixMult(A, B, C);
  printMatrix(C);
  destroyMatrix(A);
  destroyMatrix(B);
  destroyMatrix(C);
  return 0;
}
