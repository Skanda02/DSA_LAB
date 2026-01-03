#include<stdio.h>
#include "stack.h"

int stack[MAX];
int top = -1;
int size;
int num;

void push(void)
{
    if(top == size-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        printf("Enter the number to be pushed: ");
        scanf("%d", &num);
        top++;
        stack[top] = num;
    }
}

void pop(void)
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        num = stack[top];
        printf("Popped number is %d\n", num);
        top--;
    }
}

void display(void)
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack contains:\n");
        for(int i=top ; i>=0 ; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}