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
        printf("\nlist item: %d", p->n);
        p = p->next;
    }
}

void scr(struct node *start, int n)
{
    struct node *p = start;
    while (p != NULL)
    {
        if (p->n == n)
        {
            printf("Found element: ");
            return;
        }
        p = p->next;
    }
    printf("ELement not found: ");
}

int count(struct node *start)
{
    struct node *p = start;
    int c;
    while (p != NULL)
    {
        p = p->next;
        c++;
    }
    return c;
}

void adtoempty(struct node **start, int n)
{
    create(start, n);
}

void adatbeg(struct node **start, int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->n = n;
    temp->prev = NULL;
    temp->next = *start;
    *start = temp;
}

void adatend(struct node **start, int n)
{
    create(start, n);
}

void adbefore(struct node **start, int n, int item)
{
    struct node *p = *start, *temp = (struct node *)malloc(sizeof(struct node));
    temp->n = n;
    if (p->n == item)
    {
        temp->next = p;
        temp->prev = NULL;
        *start = temp;
        return;
    }
    while (p != NULL)
    {
        if (p->next->n == item)
        {
            temp->next = p->next;
            p->next = temp;
            temp->prev = p;
            temp->next->prev = temp;
            return;
        }
        p = p->next;
    }
    printf("Not found, couldnt add\n");
}

void adafter(struct node **start, int n, int item)
{
    struct node *p = *start, *temp = (struct node *)malloc(sizeof(struct node));
    temp->n = n;
    while (p != NULL)
    {
        if (p->n == item)
        {
            temp->next = p->next;
            p->next = temp;
            temp->prev = p;
            temp->next->prev = temp;
            return;
        }
        p = p->next;
    }
    printf("Not found, couldnt add\n");
}

void adatpos(struct node **start, int n, int pos)
{
    struct node *p = *start, *temp = (struct node *)malloc(sizeof(struct node));
    temp->n = n;
    int i = 0;
    while (i < pos)
    {
        p = p->next;
        i++;
    }
    temp->next = p->next;
    p->next = temp;
    temp->prev = p;
    temp->next->prev = temp;
    return;
}

void del(struct node **start, int item)
{
    struct node *p = *start, *temp;
    if (p->n == item)
    {
        temp = p;
        *start = p->next;
        (*start)->prev = NULL;
        free(temp);
        return;
    }
    while (p->next != NULL)
    {
        if (p->next->n == item)
        {
            temp = p->next;
            p->next = p->next->next;
            p->next->prev = p;
            free(temp);
            return;
        }
        p = p->next;
    }
    printf("Not found, couldnt delete\n");
}

void rev(struct node **start)
{
    struct node *p = *start, *temp;
    temp=p->next;
    p->prev=temp;
    p->next=NULL;
    while (temp != NULL)
    {
        temp->prev = temp->next;
        temp->next = p;
        p = temp;
        temp = temp->prev;
    }
    *start=p;
}

int main()
{
    struct node *start = NULL;
    int cho = 0, l, n, pos;
    while (cho != 13)
    {
        printf("Enter choice:\n1.To create list\n2.To display list\n3.To search list\n4.Count\n5.Add to empty list\n6.Add at beginning\n7.add at end\n8.Add before\n9.Add after\n10.Add t pos\n11.delete\n12.Reverse\n13.To exit\nChoice: ");
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
            printf("enter element to search for ");
            scanf("%d", &n);
            scr(start, n);
            break;

        case 4:
            printf("count = %d", count(start));
            break;

        case 5:
            printf("\nEnter number: ");
            scanf("%d", &n);
            adtoempty(&start, n);
            break;

        case 6:
            printf("\nEnter number: ");
            scanf("%d", &n);
            adatbeg(&start, n);
            break;

        case 7:
            printf("\nEnter number: ");
            scanf("%d", &n);
            adatend(&start, n);
            break;

        case 8:
            printf("\nEnter number: ");
            scanf("%d", &n);
            printf("\nenter element before which to add");
            scanf("%d", &pos);
            adbefore(&start, n, pos);
            break;

        case 9:
            printf("\nEnter number: ");
            scanf("%d", &n);
            printf("\nenter element after which to add");
            scanf("%d", &pos);
            adafter(&start, n, pos);
            break;

        case 10:
            printf("\nEnter number: ");
            scanf("%d", &n);
            printf("\nenter position after which to add");
            scanf("%d", &pos);
            adatpos(&start, n, pos);
            break;

        case 11:
            printf("\nenter element to delete");
            scanf("%d", &n);
            del(&start, n);
            break;
        
        case 12:
            rev(&start);
            break;
        }
    }
}
