#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front = -1, rear = -1;
typedef struct process
{
    int pid;
    int pr;
    int bt;
} jobs;
jobs job[MAX];
void insert()
{
    int pid, pr, bt;
    if (rear == MAX - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter pid, pr and bt: \n");
        scanf("%d %d %d", &pid, &pr, &bt);
        if (front == -1 || rear == -1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        job[rear].pid = pid;
        job[rear].pr = pr;
        job[rear].bt = bt;
    }
}
void delete()
{
    int max = -1, pos;
    if (front == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                if (job[i].pr > max)
                {
                    max = job[i].pr;
                    pos = i;
                }
            }
            for (int i = pos; i < rear; i++)
            {
                job[i].pid = job[i + 1].pid;
                job[i].pr = job[i + 1].pr;
                job[i].bt = job[i + 1].bt;
            }
            rear--;
        }
    }
}
void display()
{
    if (front == -1)
    {
        printf("Empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("pid: %d\t pr: %d\t bt:%d\n", job[i].pid, job[i].pr, job[i].bt);
        }
    }
}
void main()
{
    int ch;
    while (ch < 5)
    {
        printf("1.Insert\t 2.Delete\t 3.Display\t 4.Exit\n");
        printf("Enter the choice: \n");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            delete ();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}