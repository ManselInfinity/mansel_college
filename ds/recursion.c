// Develop a menu driven C program to do the following recursively:
// 1. Base conversion
// 2. Tower Hanoi
// 3. Greatest Common Divisor
// 4. Reverse a string
// 5. Search an item in a linked list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int n;
    struct node *next;
};

int cnv(int n, int b)
{
    if (n == 0)
        return 0;
    cnv(n / b, b);
    printf("%d", n % b);
}

void towerOfHanoi(int n, char a, char b, char t)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, a, t, b);
    printf("Moved disk %d from rod %c to rod %c \n", n, a, b);
    towerOfHanoi(n - 1, t, b, a);
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void rev(char *c, int n)
{
    if (n < 0)
        return;
    printf("%c", c[n]);
    rev(c, n - 1);
}

void addlst(struct node **s)
{
    printf("\nEnter number: ");
    struct node *temp = (struct node *)malloc(sizeof(struct node)), *p = *s;
    int n;
    scanf("%d", &n);
    temp->n = n;
    temp->next = NULL;
    if (*s == NULL)
        *s = temp;
    else
    {
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }
}

void scr(struct node *s, int n)
{
    if (s == NULL)
    {
        printf("Element not found ");
        return;
    }
    if (s->n == n)
    {
        printf("Found element");
        return;
    }
    scr(s->next, n);
}

int main()
{
    printf("Enter :\n1.base conversion\n2.tower of Hanoi\n3.GCD\n4.Reverse a string\n5.Search an item in a linked list ");
    int cho, n, b;
    struct node *s = NULL, *p;
    char c[50];
    scanf("%d", &cho);
    switch (cho)
    {
    case 1:
        printf("Enter number and base: ");
        scanf("%d %d", &n, &b);
        printf("number: ");
        cnv(n, b);
        break;
    case 2:
        printf("Enter number of discs: ");
        scanf("%d", &n);
        towerOfHanoi(n, 'a', 'c', 'b');
        break;
    case 3:
        printf("Enter numbers to find GCD of: ");
        scanf("%d %d", &n, &b);
        printf("\n Output: %d", gcd(n, b));
        break;
    case 4:
        printf("enter string to reverse: ");
        scanf("%s", c);
        rev(c, strlen(c));
        break;
    case 5:
        printf("Enter number of items: ");
        int n, i;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            addlst(&s);
        printf("Enter item to search for in ll: ");
        n = 0;
        scanf("%d", &n);
        scr(s, n);
        break;
    default:
        printf("Wrong choice\n");
    }
}
