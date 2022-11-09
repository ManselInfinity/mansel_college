// 1. insert, 2.search(name, ath), 3.display entire book list 4. delete 5.exit

#include <stdio.h>
#include <string.h>

struct library
{
    int num;
    char name[50], ath[50];
} book[50];

void ins(int count)                 
{   
    printf("Enter author name: ");
    scanf("%s", &book[count].ath);
    printf("\nEnter book name: ");
    scanf("%s", &book[count].name);
    book[count].num = 1000 + count;
}

void scr(int count)
{
    printf("Enter 1 to search for author or 2 for title: ");
    int cho, i;
    scanf("%d", &cho);
    char na[50];
    switch (cho)
    {
    case 1:
        printf("Enter author name: ");
        scanf("%s", &na);
        for (i = 0; i <= count; i++)
        {
            if (strcmp(book[i].ath, na) == 0)
            {
                printf("Found book :\n");
                printf("Title: %s \n", book[i].name);
                printf("Author: %s \n", book[i].ath);
                printf("serial no: %d \n\n", book[i].num);
                break;
            }
        }
        if (i == count)
            printf("Book not found");
        break;

    case 2:
        printf("Enter Book title: ");
        scanf("%s", &na);
        for (i = 0; i <= count; i++)
        {
            if (strcmp(book[i].name, na) == 0)
            {
                printf("Found book : %s \n");
                printf("Title: %s \n", book[i].name);
                printf("Author: %s \n", book[i].ath);
                printf("serial no: %d \n\n", book[i].num);
                break;
            }
        }
        if (i == count)
            printf("Book not found \n");
        break;

    default:
        printf("Wrong choice \n");
    }
}

void print(int count)
{
    int i;
    if(count == 0)
    {
        printf("No books.\n\n");
        return;
    }
    for (i = 0; i < count; i++)
    {
        printf("Title: %s \n", book[i].name);
        printf("Author: %s \n", book[i].ath);
        printf("serial no: %d \n", book[i].num);
    }
}

void del(int count)
{
    int i =0;
    char na[50];
    printf("Enter Book title to delete: ");
    scanf("%s", &na);
    for(i=0; i<=count; i++)
    {
        if (strcmp(book[i].name, na) == 0)
        {
            for(;i<count; i++)
              book[i]=book[i+1];
            break;
        }
    }
}

int main()
{
    int cho = 0, count = 0;
    while (cho != 5)
    {
        printf("Enter :\n1.To insert book\n2.To search book\n3.to Dislay all books\n4.To delete book\n5.To exit\nEnter Choice: ");
        scanf("%d", &cho);
        switch (cho)
        {
        case 1:
            ins(count);
            count++;
            break;

        case 2:
            scr(count);
            break;

        case 3:
            print(count);
            break;

        case 4:
            del(count);
            count--;
        }
    }
}