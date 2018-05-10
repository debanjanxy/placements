#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int d)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = d;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void preorder(struct Node *root)
{
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node *root)
{
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct Node *root)
{
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(struct Node *root)
{
    if(!root) return;
    queue<struct Node*> q;
    q.push(root);
    while(!q.empty())
    {
        struct Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
    cout << endl;
}

void newLineLevelOrder(struct Node *root)
{
    if(!root) return;
    queue<Node *> q;
    int nodeCount = 0,inc=0;
    q.push(root);
    nodeCount++;
    while(1)
    {
        if(q.empty()) break;
        while(nodeCount>0)
        {
            struct Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if(temp->left)
            {
                q.push(temp->left);
                inc++;
            }
            if(temp->right)
            {
                q.push(temp->right);
                inc++;
            }
            nodeCount--;
        }
        nodeCount = inc;
        inc = 0;
        cout << endl;
    }
}

void inorderWithoutRec(struct Node *root)
{
    list<Node *> st;
    st.push_back(root);
    struct Node *curr = root;
    int done = 0;
    while(!done)
    {
        if(curr)
        {
            st.push_back(curr);
            curr = curr->left;
        }
        else
        {
            if(!st.empty())
            {
                struct Node *temp = st.front();
                cout << temp->data << " ";
                st.pop_back();
                curr = curr->right;
            }
            else
            {
                done = 1;
            }
        }
    }
}

int main()
{
    struct Node *root = createNode(2);
    root->left = createNode(1);
    root->right = createNode(3);
    root->left->left = createNode(5);
    root->right->left = createNode(9);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    levelorder(root);
    cout << endl;
    newLineLevelOrder(root);
    cout << endl;
    inorderWithoutRec(root);

}
