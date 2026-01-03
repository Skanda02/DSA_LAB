/*
3. Develop menu driven Program in C for following operations o n STACK of Integers
(Array Implementation o f Stack with maximum size MAX)
    a. Push an Element on to Stack
    b . Pop an Element from Stack
    c . Demonstrate how Stack can be used to check Palindrome
    d. Demonstrate Overflow and Underflow situations on Stack
    e. Display the status of Stack
    f . Exit
Support the program with appropriate functions for each of the above operations
*/

#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main(void)
{
    int choice, f;
    printf("Enter the size of stack: ");
    scanf("%d", &size);

    printf("\n--- MENU --- \n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Check palindrome\n");
    printf("5. Exit\n");

    while(1)
    {
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            f = pali();
            if(f==1)
            {
                printf("It is a palindraome\n");
            }
            else{
                printf("Not pali\n");
            }
            break;
        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}