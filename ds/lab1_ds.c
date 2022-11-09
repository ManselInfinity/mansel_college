//program to input polynomials and sort in order and 1.add, 2.multiply, 3.modify(add, delete)

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef, exp;
    struct node *link;
};

struct node *inp(struct node *start)
{
    printf("Enter number of terms: ");
    int n,i,data;
    scanf("%d", &n);
    struct node *temp, *p1;
    temp = (struct node *)malloc(sizeof(struct node));
    p1 = start;
    

    for(i=0; i<n; i++)
    {
        int flag=0;
        printf("Enter coeff and exponent:\n");
        scanf("%d", &temp->coef);
        scanf("%d", &temp->exp);
        if(start == NULL || start->exp < temp->exp)
        {
            temp->link=start;
            start = temp;
            continue;
        }
        else
        {
            if(start->link == NULL)
            {
                start->link = temp;
                continue;
            }
            while(p1->link != NULL)
            {
                if(p1->link->exp < temp->exp)
                {
                    temp->link = p1->link;
                    p1->link = temp;
                    flag=1;
                }
            }
            if(flag == 0)
            {
                p1->link = temp;
            }
            p1=start;
        }
    }
    return start;
}

 void add(struct node *s1, struct node *s2, struct node *start)
{
    struct node *p1=s1, *p2=s2, *temp, *p;
    temp = (struct node*)malloc(sizeof(struct node));
    p=start;
    int flag =0;
    while(p1->link != NULL)
    {   
        while(p2->link != NULL)
        {
            if(p1->exp > p2->exp)
            {
                temp->coef = p1->coef;
                temp->exp = p1->exp;
                if(start == NULL)
                  start = temp;
                else
                  p->link = temp;
                flag =1;
                break;
            }
            else if(p1->exp == p2->exp)
            {
                temp->coef = p1->coef + p2->coef;
                temp->exp = p1->exp;
                if(start == NULL)
                  start = temp;
                else
                  p->link = temp;                
                flag =1;
                break;
            }         
            p2=p2->link;
        }
        p2=s2;
        if(flag == 0)
        {
            p->link = temp;
        }
        flag=0;
        p1=p1->link;
    }
}

struct node *multiply(struct node *s1, struct node *s2)
{
    struct node *start, *p1=s1, *p2=s2, *temp, *p=start;
    temp = (struct node*)malloc(sizeof(struct node));
    start=temp;
    while(p1->link != NULL)
    {
        while(p2->link != NULL)
        {
            temp->coef = p1->coef * p2->coef;
            temp->exp = p1->exp + p2->exp;
            p->link = temp;
            p1=p1->link;
            p2=p2->link;
        }
    }
    return start;
}

struct node *mod(struct node *start)
{
    printf("Enter :\n1. To add element\n2.To remove element\n");
    int cho,flag=0, exp, coef;
    struct node *temp, *p=start, *s1;
    scanf("%d", &cho);
    switch(cho)
    {
    case 1:
        printf("Enter element to add ; coeff and exp: ");
        temp = (struct node *)malloc(sizeof(struct node));
        scanf("%d %d", &temp->coef, &temp->exp);
        while(p->link != NULL)
        {
            if(p->exp == temp->exp)
            {
                p->coef+= temp->coef;
                flag++;
                break;
            }
            else if(p->exp > temp->exp && p->link->exp < temp->exp)
            {
                temp->link = p->link;
                p->link = temp;
                flag++;
                break;
            }
            p=p->link;
        }
        if(flag==0)
            p->link = temp;
        return start;

    case 2:
        
        printf("ENter coeff and exp to remove: ");
        scanf("%d %d", &coef, &exp);
        if(start->exp == exp && start->coef == coef)
        {
            temp=start;
            start = start->link;
            free(temp);
            return start;
        }
        while(p->link->coef!=coef && p->link->exp != exp)
            p=p->link;
        temp = p->link;
        p->link=temp->link;
        free(temp);
        return start;
    }
}

void disp(struct node *s)
{
    struct node *p=s;
    printf("\n\nOutput: ");
    while(p->link != NULL)
    {
        printf("%dX^%d + ", p->coef, p->exp);
        p=p->link;
    }
}

int main()
{
    struct node *p1=NULL,*p2=NULL,*output;
    int cho=0;
    printf("input polynomial 1 in terms of coeff and exp :\n ");
    inp(p1);
    printf("\nInput polynomial 2:\n");
    inp(p2);
    printf("Enter :\n1.To add them\n2.To multiply them\n3.To modify them\n4.To exit\n\nChoice: ");
    scanf("%d", &cho);
    while(cho!=4)
    {
    switch(cho)
    {
        case 1:
            add(p1, p2, output);
            disp(output);
            break;
        
        case 2:
            output = multiply(p1, p2);
            disp(output);
            break;

        case 3:
            output = mod(p1);
            disp(p1);
            break;
    }
    }
}
