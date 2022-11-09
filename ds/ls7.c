//develop a c program to create a binary tree given its post and inorder traversal 
// provide menu options to perform the followonig operations
// 1] to find height 2]to find depth of a given node 3] perform level order traversal 
// 4] spiral order traversal 

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int n;
    struct node *lc, *rc;
};

struct list
{
    int n;
    struct node *next;
};

