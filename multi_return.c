// In the caseof multiple return we will use pointers because it is efficient for doing it.....

#include<stdio.h>

/* Function defination */
void DoWork(int a,int b,int* sum, int *prod, int* avg);

/* this is the main function */
int main(void){
    int a = 5, b = 8;

    int sum, prod, avg;
    // calling the function
    DoWork(a,b,&sum,&prod,&avg);
    printf("sum = %d, product = %d, average = %d\n",sum,prod,avg);
}

void DoWork(int a, int b, int* sum, int* prod, int * avg){
    *sum = a + b;
    *prod = a * b;
    *avg = (a + b)/2;
}