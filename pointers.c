/* This is the C programming about the topic pointers */

// This is the header file which we have to include to run our program..
#include<stdio.h>

// This is the main function from where the program will start....
int main(void){
    // Declairing the normal variable.....
    int a; printf("What's a: ");
    scanf("%d",&a);

    // Declaring the pointer variable....
    int *ptr;
    // In the pointer variable we are inserting the address of the variable a
    ptr = &a;

    // Now I am printing the address where the value is stored....
    printf("The address where the value is stored is : %p\n",(void *)ptr);

    // Now I am trying to print the value of the variable is stored....
    printf("The value of the variable is : %d\n", *ptr);
}