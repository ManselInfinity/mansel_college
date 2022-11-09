#include<stdio.h>
#include<stdlib.h>

const int MAX=4;

void add(int n[], int *rear,int *start, int data)
{
   printf("start value: %d\n", *start);
   printf("rear value:%d\n", *rear);
   if((*rear+1)%MAX == (*start+1))
   {
    printf("FULL !!\n");
    exit(1);
   }
   n[*rear]=data;  
   *rear= (*rear+1) % MAX;   
}

int rem(int n[], int *front, int rear)
{
    if(*front == rear)
    {
        printf("queue empty:\n");
        exit(1);
    }
    int data=n[*front];
    *front=(*front+1)%MAX;
    return data;
}

void disp(int n[], int start, int rear)
{
    int i;
    for(i=start; i!=rear; i=(i+1)%MAX)
     printf("\nelement at pos %d is : %d", i, n[i]);
}

int main()
{
    int cho=0,n[50],front=0,rear=-1,data;
    while(cho!=9)
    {
        printf("\nEnter :\n1.To add to queue\n2.To remove from queue\n3.To display queue\n9.To exit\nChoice: ");
        scanf("%d", &cho);
        switch(cho)
        {
            case 1:
            printf("\nEnter number to add : ");
            scanf("%d", &data);
            add(n,&rear,&front, data);
            break;

            case 2:
            printf("\nPopped element: %d", rem(n, &front, rear));
            break;

            case 3:
            printf("Whole queue: \n");
            disp(n, front, rear);
            break;
        }
    }

}


