// PROGRAM 1
#include<stdio.h>
// creating a function for displaying the size
void size(){
    printf("Size of int: %lu\n", sizeof(int));
    printf("Size of float: %lu\n", sizeof(float));
    printf("Size of double: %lu\n", sizeof(double));
    printf("Size of char: %lu\n", sizeof(char));
    printf("Size of long: %lu\n", sizeof(long));
}
int main(void){

    // calling the functions...
    size();
}