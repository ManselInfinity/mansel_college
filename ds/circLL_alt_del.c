#include <stdio.h>
#include <stdlib.h>

struct node
{
    int n;
    struct node *next;
};

void create(struct node **last, int data)
{
    struct node *temp, *p = *last;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->n = data;
    if (*last == NULL)
    {
        *last = temp;
        temp->next = temp;
        return;
    }
    temp->next = (*last)->next;
    (*last)->next = temp;
    *last = temp;
}

void dis(struct node *last)
{
    struct node *p = last->next;
    if (p == NULL)
    {
        printf("List empty. EXITING....\n");
        return;
    }
    do
    {
        printf("%d, ", p->n);
        p = p->next;
    } while (p != last->next);
}

void del(struct node **last)
{
    struct node *p = (*last)->next, *temp;
    do
    {
        temp = p->next;
        if (p->next != *last)
            p->next = p->next->next;
        else
        {
            *last = p;
            p->next = p->next->next;
            free(temp);
            break;
        }
        free(temp);
        p = p->next;
    } while (p != (*last));
}

int main()
{
    struct node *start = NULL;
    int cho = 0, l, n, pos;
    while (cho != 13)
    {
        printf("Enter choice:\n1.To create list\n2.To display list\n3.delete alt\n13.To exit\nChoice: ");
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
            del(&start);
            break;
        }
    }
}
