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
    if (p == NULL)
    {
        printf("List empty. EXITING....\n");
        return;
    }
    while (p != NULL)
    {
        printf(" %d, ", p->n);
        p = p->next;
    }
}

void rev(struct node **start)
{
    struct node *p = *start, *temp;
    if (p->next == NULL)
        return;
    temp = p->next;
    temp->prev = NULL;
    p->prev = temp;
    p->next = temp->next;
    temp->next = p;
    *start = temp;
    p->next->prev = p;
    p = p->next;

    while (p != NULL)
    {
        if (p->next == NULL)
            break;
        temp = p->next;
        temp->prev = p->prev;
        p->prev = temp;
        p->next = temp->next;
        temp->next = p;
        if (p->next != NULL)
            p->next->prev = p;
        temp->prev->next = temp;
        p = p->next;
    }
}

int main()
{
    struct node *start = NULL;
    int cho = 0, l, n, pos;
    while (cho != 13)
    {
        printf("Enter choice:\n1.To create list\n2.To display list\n3.Swap alternate nodes\n13.To exit\nChoice: ");
        scanf("%d", &cho);
        switch (cho)
        {
        case 1:
            printf("\nEnter length of list: ");
            scanf("%d", &l);
            for (int i = 0; i < l; i++)
            {
                printf("\nEnter number: ");
                scanf("%d", &n);
                create(&start, n);
            }
            break;

        case 2:
            dis(start);
            break;

        case 3:
            rev(&start);
            break;
        }
    }
}
