// to convert postfix to infix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct node
{
    char c[50];
    float n;
    struct node *link;
};

void push(struct node **top, char c[])
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->c, c);
    temp->link = *top;
    *top = temp;
}

char *pop(struct node **top, char c[])
{
    struct node *temp;
    if (*top == NULL)
    {
        printf("\nStack underflow\n");
        exit(1);
    }
    temp = *top;
    *top = (*top)->link;
    strcpy(c, temp->c);
    free(temp);
    return c;
}

int main()
{
    struct node *stck = NULL;
    char c[50], a[50], b[50], d[2];
    printf("Enter epreswion: ");
    scanf("%s", c);
    int l = strlen(c), j, k;
    for (int i = 0; i < l; i++)
    {
        if (isalpha(c[i]))
        {
            char m[50];
            m[0] = c[i];
            push(&stck, m);
            printf("\npushing char: %s", m);
        }
        else
        {
            char m[50], e[10];
            j = 0;
            k = 1;
            strcpy(b, pop(&stck, e));
            e[0] = '\0';
            strcpy(a, pop(&stck, e));
            m[0] = '(';
            while (a[j] != '\0')
                m[k++] = a[j++];
            m[k++] = c[i];
            j = 0;
            while (b[j] != '\0')
                m[k++] = b[j++];
            m[k] = ')';
            push(&stck, m);
            printf("\npushing exp: %s", m);
        }
    }
    char e[50];
    printf("\nOuptput: %s", pop(&stck, e));
}