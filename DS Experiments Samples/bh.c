#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int key;
    int degree;
    struct Node *child, *sibling, *parent;
};

struct Node* newNode(int key)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->degree = 0;
    temp->child = temp->parent = temp->sibling = NULL;
    return temp;
}
