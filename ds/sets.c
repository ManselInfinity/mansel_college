// sets union, intersection, difference using ll
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int n;
    struct node *link;
};

struct node *ad(struct node *start, int data)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    p = start;
    temp->n = data;
    temp->link = NULL;
    if (start == NULL)
        start = temp;
    else
    {
        while (p->link != NULL)
            p = p->link;
        p->link = temp;
    }
    return start;
}

struct node *un(struct node *s1, struct node *s2, struct node *start)
{
    int flag = 0;
    struct node *p1 = s1, *p2 = s2, *p = start;
    while (p1 != NULL)
    {
        start = ad(start, p1->n);
        p1 = p1->link;
    }
    p1 = s1;
    while (p2 != NULL)
    {
        while (p1 != NULL)
        {
            printf("Inside inside loop p1= %d\n", p1->n);
            if (p2->n == p1->n)
                flag = 1;
            p1 = p1->link;
        }
        if (flag == 0)
            start = ad(start, p2->n);
        p2 = p2->link;
        p1 = s1;
        flag = 0;
    }
    return start;
}

struct node *inter(struct node *s1, struct node *s2, struct node *start)
{
    struct node *p1 = s1, *p2 = s2, *p = start;
    while (p2 != NULL)
    {
        while (p1 != NULL)
        {
            if (p2->n == p1->n)
            {
                start = ad(start, p1->n);
                break;
            }
            p1 = p1->link;
        }
        p2 = p2->link;
        p1 = s1;
    }
    return start;
}

struct node *diff(struct node *s1, struct node *s2, struct node *start)
{
    int flag = 0;
    struct node *p1 = s1, *p2 = s2, *p = start;
    while (p1 != NULL)
    {
        while (p2 != NULL)
        {
            if (p2->n == p1->n)
            {
                flag = 1;
                break;
            }
            p2 = p2->link;
        }
        if (flag == 0)
            start = ad(start, p1->n);
        p1 = p1->link;
        p2 = s2;
        flag = 0;
    }
    return start;
}

void disp(struct node *s)
{
    struct node *p = s;
    printf("\nOutput: ");
    while (p != NULL)
    {
        printf("%d ", p->n);
        p = p->link;
    }
}

int main()
{
    int cho = 0, i, data, n;
    struct node *s1 = NULL, *s2 = NULL, *s = NULL;
    while (cho != 5)
    {
        printf("Enter :\n1.To input sets\n2.To perform set union\n3. To perform set intersection\n4.To perform set difference\n5.To exit\nChoice : ");
        scanf("%d", &cho);
        switch (cho)
        {
        case 1:
            printf("Enter length of set 1: \n");
            scanf("%d", &n);
            printf("\nEnter data:\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &data);
                s1 = ad(s1, data);
            }
            printf("Enter length of set 2: ");
            scanf("%d", &n);
            printf("\nEnter data:\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &data);
                s2 = ad(s2, data);
            }
            printf("set 1:\n");
            disp(s1);
            break;
        case 2:
            s = un(s1, s2, s);
            disp(s);
            break;
        case 3:
            s = inter(s1, s2, s);
            disp(s);
            break;
        case 4:
            s = diff(s1, s2, s);
            disp(s);
            break;
        }
    }
}
