#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct node
{
    char c;
    float n;
    struct node *link;
};

void push(struct node **top, char c)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->c = c;
    temp->link = *top;
    *top = temp;
}

void ipush(struct node **top, float c)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->n = c;
    temp->link = *top;
    *top = temp;
}

char pop(struct node **top)
{
    struct node *temp;
    char c;
    if (*top == NULL)
    {
        printf("\nStack underflow\n");
        exit(1);
    }
    temp = *top;
    *top = (*top)->link;
    c = temp->c;
    free(temp);
    return c;
}

float ipop(struct node **top)
{
    struct node *temp;
    float c;
    if (*top == NULL)
    {
        printf("\nStack underflow\n");
        exit(1);
    }
    temp = *top;
    *top = (*top)->link;
    c = temp->n;
    free(temp);
    return c;
}

int instk(char c) // functions for postfix priorities
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/' || c == '%')
        return 2;
    else if (c == '(' || c == '{' || c == '[')
        return 0;
    return 1;
}

int incmg(char c)
{
    if (c == '^')
        return 4;
    else if (c == '*' || c == '/' || c == '%')
        return 2;
    else if (c == '(' || c == '{' || c == '[')
        return 0;
    return 1;
}

int Xinstk(char c) // functions for prefix priorities
{

    if (c == '^')
        return 4;
    else if (c == '*' || c == '/' || c == '%')
        return 2;
    return 1;
}

int Xincmg(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/' || c == '%')
        return 2;
    return 1;
}

int main()
{
    struct node *stck;
    stck = NULL;

    printf("Enter expression:");
    char c[50], exp[100], t;
    scanf("%s", c);
    printf("\nEnter :\n1.To convert infix to postfix\n2.To convert infix to prefix\n3.To evaluate postfix\n4.To evaluate prefix\nChoice: ");
    int cho, l = strlen(c), i, m = 0, x[50];
    float a = 0, b = 0;
    scanf("%d", &cho);
    switch (cho)
    {
    case 1:
        for (i = 0; i < l; i++)
        {
            if (isalpha(c[i]))
            {
                exp[m++] = c[i];
            }
            else
            {
                if (c[i] == '(' || c[i] == '{' || c[i] == '[')
                    push(&stck, c[i]);
                else if (c[i] == ')') // to dump stack till opening bracket
                    while (t = pop(&stck) != '(')
                        exp[m++] = t;
                else if (c[i] == '}') // to dump stack till opening bracket
                    while (t = pop(&stck) != '{')
                        exp[m++] = t;
                else if (c[i] == ']') // to dump stack till opening bracket
                    while (t = pop(&stck) != '[')
                        exp[m++] = t;
                else
                {
                    if (stck != NULL)
                        a = instk(stck->c);
                    b = incmg(c[i]);
                    while (a >= b && stck != NULL)
                    {
                        exp[m++] = pop(&stck);
                        printf("Isisde while : %c", exp[m - 1]);
                        if (stck != NULL)
                            a = instk(stck->c);
                    }
                    push(&stck, c[i]);
                }
            }
        }
        while (stck != NULL)
            exp[m++] = pop(&stck);

        printf("\nOutput: %s", exp);
        break;

    case 2:
        for (i = (l - 1); i >= 0; i--)
        {
            printf("\nC[%d]=%c", i, c[i]);
            if (isalpha(c[i]))
            {
                exp[m++] = c[i];
            }
            else
            {
                if (c[i] == ')' || c[i] == ')' || c[i] == ')')
                    push(&stck, c[i]);
                else if (c[i] == '(') // to dump stack till opening bracket
                    while (t = pop(&stck) != ')')
                        exp[m++] = t;
                else if (c[i] == '{')
                    while (t = pop(&stck) != '}')
                        exp[m++] = t;
                else if (c[i] == '[')
                    while (t = pop(&stck) != ']')
                        exp[m++] = t;
                else
                {
                    if (stck != NULL)
                        a = Xinstk(stck->c);
                    b = Xincmg(c[i]);
                    while (a > b && stck != NULL)
                    {
                        exp[m++] = pop(&stck);
                        if (stck != NULL)
                            a = Xinstk(stck->c);
                    }
                    push(&stck, c[i]);
                }
            }
        }
        while (stck != NULL)
            exp[m++] = pop(&stck);
        printf("\nOutput: ");
        for (i = l - 1; i >= 0; i--)
            printf("%c", exp[i]);
        break;

    case 3:
        for (i = 0; i < l; i++)
        {
            if (isdigit(c[i]))
                ipush(&stck, (c[i] - '0'));
            else if (c[i] == '+')
            {
                b = ipop(&stck);
                a = ipop(&stck);
                ipush(&stck, (a + b));
            }
            else if (c[i] == '-')
            {
                b = ipop(&stck);
                a = ipop(&stck);
                ipush(&stck, (a - b));
            }
            else if (c[i] == '/')
            {
                b = ipop(&stck);
                a = ipop(&stck);
                ipush(&stck, (a / b));
            }
            else if (c[i] == '*')
            {
                b = ipop(&stck);
                a = ipop(&stck);
                ipush(&stck, (a * b));
            }
            else if (c[i] == '^')
            {
                b = ipop(&stck);
                a = ipop(&stck);
                ipush(&stck, pow(a, b));
            }
        }
        printf("Answer: %f", stck->n);
        break;

    case 4:
        for (i = l - 1; i >= 0; i--)
        {
            if (isdigit(c[i]))
                ipush(&stck, (c[i] - '0'));
            else if (c[i] == '+')
            {
                b = ipop(&stck);
                a = ipop(&stck);
                ipush(&stck, (a + b));
            }
            else if (c[i] == '-')
            {
                b = ipop(&stck);
                a = ipop(&stck);
                ipush(&stck, (a - b));
            }
            else if (c[i] == '/')
            {
                b = ipop(&stck);
                a = ipop(&stck);
                ipush(&stck, (a / b));
            }
            else if (c[i] == '*')
            {
                b = ipop(&stck);
                a = ipop(&stck);
                ipush(&stck, (a * b));
            }
            else if (c[i] == '^')
            {
                b = ipop(&stck);
                a = ipop(&stck);
                ipush(&stck, pow(a, b));
            }
        }
        printf("Answer: %f", stck->n);
        break;
    }
}

// Test cases to try:
// a+b/c*(d-e)^f => abc/de-f^*+ (postfix)
// => a*/bc^-def (prefix)
// 532/32-2^*+ => 6.5
// +9*26 => 21