#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} NODE;
NODE *LLone, *LLtwo, *unionLL, *interLL;
NODE *insert(NODE **first, int num)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = num;
    newNode->link = *first;
    *first = newNode;
    return *first;
}
int search(NODE *first, int num)
{
    while (first != NULL)
    {
        if (first->data == num)
        {
            return 1;
        }
        first = first->link;
    }
    return 0;
}
NODE *findUnion(NODE *LLone, NODE *LLtwo)
{
    unionLL = NULL;
    NODE *temp = LLone;
    while (temp != NULL)
    {
        insert(&unionLL, temp->data);
        temp = temp->link;
    }
    while (LLtwo != NULL)
    {
        if (!search(LLone, LLtwo->data))
        {
            insert(&unionLL, LLtwo->data);
        }
        LLtwo = LLtwo->link;
    }
    return unionLL;
}
NODE *intersection(NODE *LLone, NODE *LLtwo)
{
    interLL = NULL;
    while (LLone != NULL)
    {
        if (search(LLtwo, LLone->data))
        {
            insert(&interLL, LLone->data);
        }
        LLone = LLone->link;
    }
    return interLL;
}
void printList(NODE *cur)
{
    while (cur != NULL)
    {
        printf("->%d", cur->data);
        cur = cur->link;
    }
}
void main()
{
    int i, LLonecount, LLtwocount, temp;
    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &LLonecount);
    LLone = NULL;
    for (i = 0; i < LLonecount; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &temp);
        insert(&LLone, temp);
    }

    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &LLtwocount);
    LLtwo = NULL;
    for (i = 0; i < LLtwocount; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &temp);
        insert(&LLtwo, temp);
    }

    unionLL = findUnion(LLone, LLtwo);
    interLL = intersection(LLone, LLtwo);

    printf("\nFirst Linked List: ");
    printList(LLone);

    printf("\nSecond Linked List: ");
    printList(LLtwo);

    printf("\nUnion of Linked Lists: ");
    printList(unionLL);

    printf("\nIntersection of Linked Lists: ");
    printList(interLL);
}