#include <stdio.h>
#include <stdlib.h>

struct Tnode
{
    char info;
    struct node *lc, *rc;
};

struct node
{
    char info;
    struct node *next;
};

struct Tnode *construct_in_post(struct node *inptr, struct node *postptr, int num)
{
    struct Tnode *temp;
    struct node *q, *ptr;
    int i, j;
    if (num == 0)
        return NULL;
    ptr = postptr;
    for (i = 1; i < num; i++)
        ptr = ptr->next;
    temp = (struct Tnode *)malloc(sizeof(struct Tnode));
    temp->info = ptr->info;
    temp->lc = NULL;
    temp->rc = NULL;
    if (num == 1)
        return temp;
    q = inptr;
    for (i = 0; q->info != ptr->info; i++)
        q = q->next;
    temp->lc = construct_in_post(inptr, postptr, i);
    for (j = 1; j <= i; j++)
        postptr = postptr->next;
    temp->rc = construct_in_post(q->next, postptr, num - i - 1);
    return temp;
}

struct node *ad(struct node *start, int data)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    p = start;
    temp->info = data;
    temp->next = NULL;
    if (start == NULL)
        start = temp;
    else
    {
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }
    return start;
}

int height(struct Tnode *ptr)
{
    int h_left, h_right;
    if (ptr == NULL)
        return 0;
    h_left = height(ptr->lc);
    h_right = height(ptr->rc);
    if (h_left > h_right)
        return 1 + h_left;
    else
        return 1 + h_right;
}

void levelorder(struct Tnode *ptr)
{
    int h = height(ptr);
    int i;
    for (i = 1; i <= h; i++)
        displaygivenlevel(ptr, i);
}
void displaygivenlevel(struct Tnode *ptr, int level)
{
    if (ptr == NULL)
        return;
    if (level == 1)
        printf("%c ", ptr->info);
    else if (level > 1)
    {
        displaygivenlevel(ptr->lc, level - 1);
        displaygivenlevel(ptr->rc, level - 1);
    }
}

int node_depth(struct Tnode *ptr, char c, int i)
{
    if (ptr == NULL)
        return;
    if (ptr->info == c)
        return i;
    node_depth(ptr->lc, c, i++);
    node_depth(ptr->rc, c, i++);
}

int main()
{
    int n, cho = 0;
    char m;
    struct node *inorder = NULL, *postorder = NULL;
    printf("Enter no of elements: ");
    scanf("%c", &n);

    printf("\nEnter inorder list: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &m);
        ad(&inorder, m);
    }

    printf("\nEnter postorder list: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        ad(&postorder, m);
    }
    struct Tnode *T = NULL;
    T = construct_in_post(inorder, postorder, n);

    while (cho != 5)
    {
        printf("Enter : \n1.To Display height of the tree\n2.Return the depth of a given node in the tree\n3.Perform level order traversal\n4.Perform Spiral order traversal\n5.Exit");
        scanf("%d", &cho);
        switch (cho)
        {
        case 1:
            printf("\nHeight of tree: %d", height(T));
            break;
        case 2:
            printf("\nEnter node to find depth of: ");
            scnaf("%c", &m);
            printf("\nDepth: %d", node_depth(T, m, 0));
            break;
        case 3:
            printf("\n Level order traversal: ");
            levelorder(T);
            break;
        case 4:
            /*

            //     do in class maybe

            */
            break;
        }
    }
}
