#include<stdio.h>

void Displaying(int x){
    printf("Your value is %d\n",x);
}


int main(void){

    int x;
    printf("What's x? ");
    scanf("%d",&x);

    Displaying(x);
    return 0;
}