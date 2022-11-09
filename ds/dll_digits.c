// Create a double linked list in which info part of each node contains a digit of a given number.
// The digits should be stored in reverse order i.e.
// the least significant digit should be stored in the first node and the most significant digit should be stored in the last node.
// Eg of number entered is 5678 the list should be 8-> 7 -> 6 -> 5. Write a function to add two numbers using the above linked list representation.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int n;
    struct node *next, *prev;
};

void create(struct node **start, int data)
{
    struct node *temp, *p = *start;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->n = data;
    temp->next = NULL;
    if (*start == NULL)
    {
        *start = temp;
        temp->prev = NULL;
        return;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->prev = p;
}

void dis(struct node *start)
{
    struct node *p = start;
    int n = 0;
    if (p == NULL)
    {
        printf("List empty. EXITING....\n");
        return;
    }
    printf("\nList: ");
    while (p != NULL)
    {
        printf("%d, ", p->n);
        p = p->next;
    }
    p = start;
    while (p->next != NULL)
        p = p->next;
    while (p != NULL)
    {
        n = (n * 10) + p->n;
        p = p->prev;
    }
    printf("\nNumber: %d", n);
}

void add(struct node *m, struct node *n, struct node **start)
{
    struct node *p = m, *q = n;
    int rem = 0;
    while (p != NULL && q != NULL)
    {
        create(start, (((p->n + q->n) + rem) % 10));
        rem = (p->n + q->n + rem) / 10;
        p = p->next;
        q = q->next;
    }
    while (p != NULL)
    {
        create(start, ((p->n) + rem) % 10);
        rem = (p->n + rem) / 10;
        p = p->next;
    }
    while (q != NULL)
    {
        create(start, ((q->n) + rem) % 10);
        rem = (q->n + rem) / 10;
        q = q->next;
    }
    if (rem != 0)
        create(start, rem);
}

int main()
{
    struct node *ml = NULL, *nl = NULL, *start = NULL;
    int m, n;
    printf("ENtrer the 2 numbers: ");
    scanf("%d%d", &m, &n);
    int m1 = m, n1 = n;
    while (m1 != 0)
    {
        create(&ml, m1 % 10);
        m1 /= 10;
    }
    while (n1 != 0)
    {
        create(&nl, n1 % 10);
        n1 /= 10;
    }
    printf("\nNum 1: ");
    dis(ml);
    printf("\nNum 2: ");
    dis(nl);
    add(ml, nl, &start);
    printf("\nadded numbers: ");
    dis(start);
}
