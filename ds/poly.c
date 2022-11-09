// program to input polynomials and sort in order and 1.add, 2.multiply, 3.modify(add, delete)

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef, exp;
    struct node *link;
};

struct node *ad(struct node *start, int exp, int coef)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    p = start;
    temp->exp = exp;
    temp->coef = coef;
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

struct node *adbeg(struct node *start, int exp, int coef)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coef = coef;
    temp->exp = exp;
    temp->link = start;
    start = temp;
    return start;
}

struct node *adaft(struct node *p, int exp, int coef)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->exp = exp;
    temp->coef = coef;
    temp->link = p->link;
    p->link = temp;
    return p;
}

struct node *input(struct node *start)
{
    printf("Enter number of terms: ");
    int n, i, coef, exp;
    scanf("%d", &n);
    struct node *p1;
    p1 = start;

    for (i = 0; i < n; i++)
    {
        int flag = 0;
        printf("Enter coeff and exponent:\n");
        scanf("%d", &coef);
        scanf("%d", &exp);
        if (start == NULL || start->exp < exp)
        {
            start = adbeg(start, exp, coef);
            continue;
        }
        else
        {
            if (start->link == NULL)
            {
                start = ad(start, exp, coef);
                continue;
            }
            while (p1->link != NULL)
            {
                if (p1->link->exp < exp)
                {
                    p1 = adaft(p1, exp, coef);
                    flag = 1;
                }
            }
            if (flag == 0)
                start = ad(start, exp, coef);
            p1 = start;
            flag = 0;
        }
    }
    return start;
}

struct node *add(struct node *s1, struct node *s2, struct node *start)
{
    struct node *p1 = s1, *p2 = s2, *p;
    p = start;
    int flag = 0;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            start = ad(start, p1->exp, p1->coef);
            p1 = p1->link;
        }
        else if (p1->exp == p2->exp)
        {
            start = ad(start, p1->exp, (p1->coef + p2->coef));
            p1 = p1->link;
            p2 = p2->link;
        }
        else
        {
            start = ad(start, p2->exp, p2->coef);
            p2 = p2->link;
        }
    }
    while (p1 != NULL)
    {
        start = ad(start, p1->exp, p1->coef);
        p1 = p1->link;
    }
    while (p2 != NULL)
    {
        start = ad(start, p2->exp, p2->coef);
        p2 = p2->link;
    }
    return start;
}

struct node *multiply(struct node *s1, struct node *s2, struct node *start)
{
    struct node *p1 = s1, *p2 = s2, *p = start;
    while (p1 != NULL)
    {
        while (p2 != NULL)
        {
            start = ad(start, (p1->exp + p2->exp), (p1->coef * p2->coef));
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    return start;
}

struct node *mod(struct node *start)
{
    printf("Enter :\n1. To add element\n2.To remove element\n");
    int cho, flag = 0, exp, coef;
    struct node *p = start, *s1, *temp;
    scanf("%d", &cho);
    switch (cho)
    {
    case 1:
        printf("Enter element to add ; coeff and exp: ");
        scanf("%d %d", &coef, &exp);
        while (p->link != NULL)
        {
            if (p->exp == exp)
            {
                p->coef += coef;
                flag++;
                break;
            }
            else if (p->exp > exp && p->link->exp < exp)
            {
                p = adaft(p, exp, coef);
                flag = 1;
                break;
            }
            p = p->link;
        }
        if (flag == 0)
            start = ad(start, exp, coef);
        return start;

    case 2:

        printf("ENter coeff and exp to remove: ");
        scanf("%d %d", &coef, &exp);
        if (start->exp == exp && start->coef == coef)
        {
            temp = start;
            start = start->link;
            free(temp);
            return start;
        }
        while (p->link != NULL && p->link->coef != coef && p->link->exp != exp)
            p = p->link;
        temp = p->link;
        p->link = p->link->link;
        free(temp);
        return start;
    }
}

void disp(struct node *s)
{
    struct node *p = s;
    printf("\nOutput: ");
    while (p != NULL)
    {
        printf("%dX^%d + ", p->coef, p->exp);
        p = p->link;
    }
}

int main()
{
    struct node *p1 = NULL, *p2 = NULL, *output = NULL;
    int cho = 0,exp,coef;
    printf("input polynomial 1 in terms of coeff and exp :\n ");
    p1 = input(p1);
    printf("\nInput polynomial 2:\n");
    p2 = input(p2);

    FILE *f;
    while (cho != 5)
    {
        printf("Enter :\n1.To add them\n2.To multiply them\n3.To modify them\n4.To input from file\n5.To exit\nChoice: ");
        scanf("%d", &cho);
        switch (cho)
        {
        case 1:
            output = add(p1, p2, output);
            disp(output);
            break;

        case 2:
            output = multiply(p1, p2, output);
            disp(output);
            break;

        case 3:
            output = mod(p1);
            disp(p1);
            break;

        case 4:
            f=fopen("file.txt", "r");
            while(getc(f) != EOF)
            {
                fscanf(f, "%d %d", &coef, &exp);
                output=ad(output, exp, coef);
            }
            disp(output);
            fclose(f);

        }
    }
}
