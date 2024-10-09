/**
 * @file stackProg-2.c
 * @brief This file contains the implementation of a stack program in C.
 *
 * The program demonstrates the basic operations of a stack data structure,
 * including push, pop, and display functions. The stack is implemented using
 * an array, and the program includes error handling for stack overflow and
 * underflow conditions.
 *
 * Steps:
 * 1. Define the maximum size of the stack.
 * 2. Declare the stack array and top variable.
 * 3. Implement the push function to add an element to the stack.
 * 4. Implement the pop function to remove an element from the stack.
 * 5. Implement the display function to show all elements in the stack.
 * 6. Include a main function to test the stack operations.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX], value, ch = 0, top = -1, status = 0;
void push(int stack[], int value)
{
    if (top == MAX - 1)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        stack[++top] = value;
        status++;
    }
}
int pop()
{
    if (top == -1)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        return top--;
        status--;
    }
}
void display()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("|%d|\t\n", stack[i]);
        }
    }
}
void palindrome()
{
    int temp, count = 0;
    temp = status;
    for (int i = 0; i < temp; i++)
    {
        if (stack[i] == pop())
        {
            count++;
        }
    }
    if (count == temp)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not a Palindrome\n");
        exit(0);
    }
}
void main()
{
    while (ch <= 5)
    {
        printf("\nEnter the choice: \n");
        printf("1.Push\t2.Pop\t3.Display\t4.Palindrome\t5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value: \n");
            scanf("%d", &value);
            push(stack, value);
            break;

        case 2:
            printf("Popped value is %d\n", pop());
            break;

        case 3:
            display();
            break;

        case 4:
            palindrome();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}