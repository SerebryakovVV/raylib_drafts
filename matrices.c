#include <stdio.h>
#include <stdlib.h>

typedef struct mtrxMatrix {
    int col;
    int row;
    float* data;
} mtrxMatrix;


void setElement(mtrxMatrix* mtrx, int col, int row, float val) {
    mtrx->data[col*mtrx->col+row] = val;
}

float getElement(mtrxMatrix* mtrx, int col, int row) {
    return mtrx->data[col*mtrx->col+row];
}


int main() {



    mtrxMatrix mOne = {3, 3, malloc(sizeof(float)*3*3)};
    mtrxMatrix mTwo = {3, 3, malloc(sizeof(float)*3*3)};


    setElement(&mOne, 1, 1, 234.675);
    setElement(&mOne, 1, 2, 4.6);
    printf("%f", getElement(&mOne, 1, 1));
    printf("%f", getElement(&mOne, 1, 2));


    free(mOne.data);
    free(mTwo.data);

}