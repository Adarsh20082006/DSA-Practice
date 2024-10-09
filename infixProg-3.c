#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
char stack[100];
int top = -1;
void push(char num)
{
    stack[++top] = num;
}
char pop()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}
int priority(char num)
{

    if (num == '(')
    {
        return 0;
    }
    else if (num == '+' || num == '-')
    {
        return 1;
    }
    else if (num == '*' || num == '/' || num == '%')
    {
        return 2;
    }
    else if (num == '^')
    {
        return 3;
    }
    return 0;
}
void main()
{
    char exp[25], *e, x;
    printf("Enter the expression:\n");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            printf("%c", *e);
        }
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {

            while (top != -1 && priority(stack[top]) >= priority(*e))
                printf("%c", pop());
            push(*e);
        }

        e++;
    }

    while (top != -1)
    {
        printf("%c", pop());
    }

    char post[25], *p;
    printf("Enter the postfix expression:\n");
    scanf("%s", post);
    int num, n1, n2, n3;
    p = post;
    while (*p != '\0')
    {
        if (isdigit(*p))
        {
            num = *p - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch (*p)
            {
            case '+':
                n3 = n1 + n2;
                break;
            case '-':
                n3 = n1 - n2;
                break;
            case '*':
                n3 = n1 * n2;
                break;
            case '/':
                n3 = n1 / n2;
                break;
            case '^':
                n3 = pow(n1, n2);
                break;
                break;
            case '%':
                n3 = n1 % n2;
                break;

            default:
                printf("Invalid");
                break;
            }
        }
        p++;
    }
    printf("The final output is %d", pop());
}