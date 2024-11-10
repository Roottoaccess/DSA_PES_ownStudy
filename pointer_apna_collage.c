#include<stdio.h>
int main(void){
    // Taking the variable and assigning the value
    // int a = 10;
    // Printing the address of the variable
    // printf("%p",&a);


    // int age = 22;
    // int *ptr = &age;
    // int _age = *ptr;

    // printf("%d", _age);

    // Printing the address
    // printf("%p\n", &age);
    // converting the address from the hexadecimal to unsigned integer
    // printf("%u\n", &age);

    // printf("%u\n", ptr);

    // printf("%u\n",&ptr);

    // Printing the value
    // printf("%d\n",age);
    // printf("%d\n",*ptr);
    // printf("%d\n",*(&age));

    /* Solving the question */
    // int *ptr;
    // int x;

    // ptr = &x;
    // *ptr = 0;
    // printf(" x = %d\n", x);
    // printf(" *ptr = %d\n",*ptr);

    // *ptr += 5;

    // printf(" x = %d\n", x);
    // printf(" *ptr = %d\n",*ptr);

    // (*ptr)++;
    // printf(" x = %d\n", x);
    // printf(" *ptr = %d\n",*ptr);

    /* Pointer to pointer */
    float price = 100.00;
    float *ptr = &price;
    float **pptr = &ptr;

    printf("price = %f\n",**pptr);
}