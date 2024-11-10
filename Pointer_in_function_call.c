// Declaring the header file
#include<stdio.h>
// Declaring the main function
int main(void){
    /* Here we will learn about the function call with pointer */

    // Giving the function defination
    void square(int num);
    void _square(int *num);

    int number;
    printf("Enter the number: ");
    scanf("%d",&number);
    square(number);
    printf("The number is: %d\n", number);
    _square(&number);
    printf("The number is: %d\n", number);
}
// call by value
void square(int num){
    num = num * num;
    printf("square = %d\n",num);
}

// call by reference
// we directly chaged in the address so the original variable value is also changed....
void _square(int* num){
    *num = (*num) * (*num);

    printf("square = %d\n",*num);
}
