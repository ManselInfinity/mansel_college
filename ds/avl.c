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
    return getBalFactor(n->lchild) - getBalFactor(n->rchild);
}

struct node *rightR(struct node *par)
{
    struct node *piv = par->lchild, *temp = piv->rchild;

    par->lchild = temp;
    piv->rchild = par;

    par->height = max(getheight(par->rchild), getheight(par->lchild)) + 1;
    piv->height = max(getheight(piv->lchild), getheight(piv->rchild)) + 1;

    return piv;
}

struct node *leftR(struct node *par)
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