#include<stdio.h>
/* Doing by call by reference */
// Function defination
void swap(int *a, int *b, int*c);

int main(void){
    int a, b, c;
    printf("What's a? "); scanf("%d",&a);
    printf("What's b? "); scanf("%d",&b);
    printf("Before swapping a = %d, b = %d\n",a,b);
    // Calling the function to perform the tasks
    swap(&a,&b,&c);
}

void swap(int* a, int* b,int *c){
    *c = *a;
    *a = *b;
    *b = *c;

    printf("After swapping a = %d and b = %d\n",*a,*b);
}
