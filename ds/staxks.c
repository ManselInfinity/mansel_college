// matching parenthesis
// reversing a string using stacks
// conversions => d2b, d2o, d2h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[50];
int top = -1;

void push(char c)
{

  stack[++top] = c;
}

char pop()
{
  if (top == -1)
  {
    printf(" ERROR :stack underflow\n");
    exit(1);
  }
  return stack[top--];
}

int par(char inp[])
{
  char c, m;
  for (int i = 0; i <= strlen(inp); i++)
  {
    c = inp[i];
    if (c == '(' || c == '{' || c == '[')
      push(c);
    if (c == ')' && stack[top] == '(')
      m = pop();
    if (c == '}' && stack[top] == '{')
      m = pop();
    if (c == ']' && stack[top] == '[')
      m = pop();
  }
  if (top == -1)
    return 1;
  return 0;
}

void rev(char str[])
{
  char c[50];
  int i;
  for (i=0; i < strlen(str); i++)
    push(str[i]);
  for (i = 0; i < strlen(str); i++)
    c[i] = pop();
  printf("Reversed string : %s", c);
}

void convert(int a, int b)
{
  char c[50],x;
  int m;
  while (a != 0)
  {
          m=a%b;
      x = m+'0';
    if (b == 2 || b == 8)
    {
      push(x);
      printf("\nint logic : %c, number : %d", x, m);
    }
    else
    {
      if ((a % b) <= 9)
        push(x);
      else
        push((a%b) -10 + 'A'); 
    }
    a /= b;
  }
  for (int i = 0; top>-1 ; i++)
    c[i] = pop();
 
   printf("Output number: %s\n\n", c);

}

int main()
{
  char string[50];
  int cho;
  while (cho != 4)
  {
    printf("Enter :\n1. To check for bracket validity\n2.To reverse the string\n3.To convert decimal to other number system\n4.Exit\nChoice: ");
    scanf("%d", &cho);

    switch (cho)
    {
    case 1:
      printf("Enter expression : ");
      scanf("%s", string);
      if (par(string))
        printf("Valid brackets in statement\n");
      else
        printf("Invalid brackets \n");
      break;

    case 2:
      printf("Enter string to reverse: ");
      scanf("%s", string);
      rev(string);
      break;

    case 3:
      printf("Enter decimal number followed by base of number system you wish to convert to: ");
      int a, b;
      scanf("%d%d", &a, &b);
      convert(a, b);
    }
  }
}
