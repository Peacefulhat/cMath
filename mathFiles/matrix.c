#include"../headers/matrix.h"
const matrix MAT_UNDEFINED={0,0,NULL};
matrix allocateMatrix(unsigned int rows, unsigned int cols){
  matrix ret;
  ret.rows=rows;
  ret.cols=cols;
  ret.elements=(float*)malloc(rows*sizeof(float));
  for(unsigned int i=0;i<rows;i++){
    ret.elements[i]=(float*)malloc(cols*sizeof(float));
  }
  return ret;
}

matrix identity(unsigned int dim){
matrix ret=allocateMatrix(dim,dim);
for(unsigned int i=0;i<dim;i++){
    for(unsigned int j=0;j<dim;j++){
    ret.elements[i][j]=(i==j)?1.0f:0.0f;
    }
  }
  return ret;
}
// all rows and cols zeros
matrix zeroMatrix(unsigned int rows, unsigned int cols){
matrix ret=allocateMatrix(rows,cols);
for(unsigned int i=0;i<rows;i++){
    for(unsigned int j=0;j<cols;j++){
    ret.elements[i][j]=0.0f;
    }
  }
  return ret;
}

matrix newMatrix(unsigned int rows, unsigned int cols,...){
matrix ret =allocateMatrix(rows,cols);
va_list list;
unsigned int size=rows*cols;
va_start(list,size); // total no of element in matrix mxn
  for(unsigned int i=0;i<rows;i++){
    for(unsigned int j=0;j<cols;j++){
    ret.elements[i][j]=va_arg(list,double);
    }
  }
  va_end(list);
  return ret;
}
matrix copy(matrix m);
matrix copyPtr(matrix *m);

void printMatrix(matrix m){
printf("\n");
  for(unsigned int i=0;i<m.rows;i++){
    printf("\n");
    printf("|");
    for(unsigned int j=0;m.cols;j++){
    printf("%f",m.elements[i][j]);  
    }
    printf("|");
  }
  printf("\n");
}
