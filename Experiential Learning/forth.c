/* FORTH PROGRAM */
#include <stdio.h>
void calculateAddress1D(int *baseAddr, int index) {
    int address = (int)baseAddr + (index * sizeof(int));
    printf("Address of element at index %d in 1-D array: %p\n", index, (void *)address);
}
void calculateAddress2D(int *baseAddr, int row, int col, int totalCols) {
    int address = (int)baseAddr + ((row * totalCols) + col) * sizeof(int);
    printf("Address of element at row %d, column %d in 2-D array: %p\n", row, col, (void *)address);
}

int main(void) {
    // 1-Dimensional Array
    int arr1D[5] = {10, 20, 30, 40, 50};
    printf("Base address of 1-D array: %p\n", (void *)arr1D);
    calculateAddress1D(arr1D, 3);

    // 2-Dimensional Array
    int arr2D[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    printf("\nBase address of 2-D array: %p\n", (void *)arr2D);
    calculateAddress2D((int *)arr2D, 1, 2, 3);

    return 0;
}
