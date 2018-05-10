#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *newNode(int data)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    return 0;
}
