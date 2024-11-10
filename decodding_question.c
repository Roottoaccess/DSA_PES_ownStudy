#include<stdio.h>

// defining the function
void printAddress(int n);

int main(void){
    int n = 5;

    printf("%p\n",&n);

    printAddress(n);
}

void printAddress(int n){
    printf("%p\n",&n);
}

// Whill the two address will be same or different

/* The address will be different because in the case of call by value the copy will create and it will contain some another different address so the result will be the address will be print different.... */