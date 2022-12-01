// avl treeinsert from array of approx 15 elements and do the foll:
// \n1.Insert new element\n2.Delete element\n3.Search an element\n4.list all elements in descending order
//\n5.find max element\n6.find min element\n7.find width of tree\n8.Exit
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int n;
    struct node *lchild, *rchild;
    int height;
};

int getheight(struct node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int getBalFactor(struct node *n)
{
    if (n == NULL)
        return 0;
    return getheight(n->lchild) - getheight(n->rchild);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct node *rightRotate(struct node *par)
{
    struct node *piv = par->lchild, *temp = piv->rchild;

    par->lchild = temp;
    piv->rchild = par;

    par->height = max(getheight(par->rchild), getheight(par->lchild)) + 1;
    piv->height = max(getheight(piv->lchild), getheight(piv->rchild)) + 1;

    return piv;
}

struct node *leftRotate(struct node *par)
{
    struct node *piv = par->rchild, *temp = piv->lchild;

    par->rchild = temp;
    piv->lchild = par;

    par->height = max(getheight(par->rchild), getheight(par->lchild)) + 1;
    piv->height = max(getheight(piv->lchild), getheight(piv->rchild)) + 1;

    return piv;
}

struct node *insert(struct node *root, int key)
{

    if (root == NULL)
    {
        struct node *temp = malloc(sizeof(struct node));
        temp->height = 1;
        temp->lchild = NULL;
        temp->rchild = NULL;
        temp->n = key;
        return temp;
    }

    if (key < root->n)
        root->lchild = insert(root->lchild, key);
    else
        root->rchild = insert(root->rchild, key);

    root->height = max(getheight(root->lchild), getheight(root->rchild)) + 1;
    int bf = getBalFactor(root);

    // Left Left Case
    if (bf > 1 && key < root->lchild->n)
    {
        return rightRotate(root);
    }
    // Right Right Case
    if (bf < -1 && key > root->rchild->n)
    {
        return leftRotate(root);
    }
    // Left Right Case
    if (bf > 1 && key > root->lchild->n)
    {
        root->lchild = leftRotate(root->lchild);
        return rightRotate(root);
    }
    // Right Left Case
    if (bf < -1 && key < root->rchild->n)
    {
        root->rchild = rightRotate(root->rchild);
        return leftRotate(root);
    }
    return root;
}

struct node *delete (struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->n)
        root->lchild = delete (root->lchild, key);

    else if (key > root->n)
        root->rchild = delete (root->rchild, key);

    else
    {
        if (root->lchild == NULL)
        {
            struct node *temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL)
        {
            struct node *temp = root->lchild;
            free(root);
            return temp;
        }

        struct node *temp = root->rchild;

        while (temp->lchild != NULL)
            temp = temp->lchild;

        root->n = temp->n;
        root->rchild = delete (root->rchild, temp->n);
    }

    root->height = max(getheight(root->lchild), getheight(root->rchild)) + 1;
    int bf = getBalFactor(root);

    // Left Left Case
    if (bf > 1 && key < root->lchild->n)
    {
        return rightRotate(root);
    }
    // Right Right Case
    if (bf < -1 && key > root->rchild->n)
    {
        return leftRotate(root);
    }
    // Left Right Case
    if (bf > 1 && key > root->lchild->n)
    {
        root->lchild = leftRotate(root->lchild);
        return rightRotate(root);
    }
    // Right Left Case
    if (bf < -1 && key < root->rchild->n)
    {
        root->rchild = rightRotate(root->rchild);
        return leftRotate(root);
    }
    return root;
}

int search(struct node *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->n == key)
        return 1;
    if (key <= root->lchild->n)
        return search(root->lchild, key);
    else
        return search(root->rchild, key);
}

void descendingPrint(struct node *root)
{
    if (root == NULL)
        return;
    descendingPrint(root->rchild);
    printf("%d ", root->n);
    descendingPrint(root->lchild);
}

int getWidth(struct node *root, int level)
{

    if (root == NULL)
        return 0;

    if (level == 1)
        return 1;

    else if (level > 1)
        return getWidth(root->lchild, level - 1) + getWidth(root->rchild, level - 1);
}

int getMaxWidth(struct node *root)
{
    int maxWidth = 0, width, h = root->height;
    for (int i = 1; i <= h; i++)
    {
        width = getWidth(root, i);
        if (width > maxWidth)
            maxWidth = width;
    }

    return maxWidth;
}

int main()
{
    int cho = 0, n;
    struct node *root = NULL, *temp;

    while (cho != 8)
    {
        printf("\n1.Insert new element\n2.Delete element\n3.Search an element\n4.list all elements in descending order \n5.find max element\n6.find min element\n7.find width of tree\n8.Exit");
        scanf("%d", &cho);
        switch (cho)
        {
        case 1:
            printf("\nENter element to insert: ");
            scanf("%d", &n);
            root = insert(root, n);
            break;
        case 2:
            printf("Enter element to delete: ");
            scanf("%d", &n);
            if (!search(root, n))
                printf("\nNot Found \n");
            else
                root = delete (root, n);
            break;
        case 3:
            printf("ENter value to search for: ");
            scanf("%d", &n);
            if (search(root, n))
                printf("\nFound: ");
            else
                printf("Not found");
            break;
        case 4:
            descendingPrint(root);
            break;
        case 5:
            for (temp = root; temp->rchild != NULL; temp = temp->rchild)
                ;
            printf("\nMax = %d\n", temp->n);
            break;
        case 6:
            for (temp = root; temp->lchild != NULL; temp = temp->lchild)
                ;
            printf("\nMin = %d\n", temp->n);
            break;
        case 7:
            printf("\nWidth of tree: %d", getMaxWidth(root));
            break;
        }
    }
}
