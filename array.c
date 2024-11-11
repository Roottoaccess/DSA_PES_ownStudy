// Working with the array DataStructure
#include<stdio.h>

int main(void){
    // int marks[] = {98, 99, 93};
    // // This is a 0 based indexcing
    // for(int i = 0; i < 3; i++){
    //     printf("%d\n",marks[i]);
    // }
    // List of Elements of the same type placed in a contiguous memory location

    // Here we are taking an empty array and putting the value inside it..

    /* Function defination */
    void update_value(int index, int value, int arr[],int lmt);


    int lmt; printf("Enter the limit of the array? ");

    scanf("%d",&lmt);

    // Creating the empty array....
    int arr[lmt];
        printf("Enter the elements one by one.....\n");
    /* Now we are taking the inputs from the user in the array */
    for(int i = 0; i < lmt; i++){
        scanf("%d",&arr[i]);
    }
    printf("Displaying the array you have entered.....\n");
    /* Now printing the values of the array */
    for(int i;i < lmt; i++){
        printf("%d\t",arr[i]);
    }
    /* implementing the update operation in the array.... */
    char check;
    printf("Do you want to update the value of any index? Y/n: ");
    scanf(" %c",&check);

    if(check == 'Y' || check == 'y'){
        int index, value;
        printf("Enter the index where you  want to change the value? ");
        scanf("%d",&index);

        printf("Enter the updated value? ");
        scanf("%d",&value);

        // Calling the function for the logic
        update_value(index, value, arr, lmt);
    }else if(check == 'N' || check == 'n'){
        printf("Program terminated!!\n");
    }else{
        printf("Invalid input '%c' ",check);
    }
    return 0;
}

// Creating a function which will update the value in the index of the array
void update_value(int index, int value, int arr[], int lmt){
    // for(int i = 0; i < lmt; i++){
    //     if(arr[i] == arr[index]){
    //         arr[i] = value;
    //     }
    // }

    if(index >= 0 && index < lmt){
        arr[index] = value;
    }else {
        printf("Invalid index %d \n",index);
    }

    printf("Displaying the value after updating the array....\n");

    for(int i = 0; i < lmt; i++){
        printf("%d\t",arr[i]);
    }
}
