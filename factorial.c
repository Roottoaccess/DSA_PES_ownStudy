// Defining the header files....
#include<stdio.h>
// Declaring the main function
int main(void){
    int num;
    // Taking the limit of the factorial value....
    printf("What's num limit? ");
    scanf("%d",&num);
    // Logic of the factorial program
    int fact = 1;
    for(int i = num; i > 0; i--){
        fact *= i;
    }
    // Displaying the result.....
    printf("the factorial is: %d\n",fact);

    return ;
}