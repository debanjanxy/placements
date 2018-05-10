#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

struct node
{
	struct node *left;
	int data;
	struct node *right;
};
node *createNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
}
void levelOrderTraversal(node *root)
{
	queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		node *node1 = q.front();	
		cout << node1->data << " ";
		q.pop();
		if(node1->left) q.push(node1->left);
		if(node1->right) q.push(node1->right);
	}

}
void printLevelWise(node *root)
{
	if(root){
	queue<node *> q;
	q.push(root);
	int l = 0;
	while(!q.empty())
	{
		int p = pow(2,l);
		while(p--){
			node *node1 = q.front();
			cout << node1->data << " ";
			q.pop();
			if(node1->left) q.push(node1->left);
			if(node1->right) q.push(node1->right);
		}
		cout << endl;
		l++;
	}
}
}

void inOrderwithoutRecursion(node *root)
{
	stack<node *> st;
	//st.push(root);
	//st.pop();
	node *temp = root;
	label:while(temp)
	{
		st.push(temp);
		temp = temp->left;
	}
	if(!temp && !st.empty())
	{
		node *popped_elem = new node;
		popped_elem = st.top();
		st.pop();
		cout << popped_elem->data << " ";
		temp = popped_elem->right;
		goto label;
	}
	cout << endl;
}
void inOrder_without_recursion_and_stack(node *root)
{
	node *curr = root;
	while(curr)
	{
		if(!curr->left)
		{
			cout << curr->data << " ";
			curr = curr->right;
		}
		else
		{}
	}
}
void preorder_without_recursion(node *root)
{
	stack<node *> st;
	//st.push(root);
	//st.pop();
	node *temp = root;
	st.push(root);
	while(!st.empty())
	{
		temp = st.top();
		cout << temp->data << " ";
		st.pop();
		if(temp->right) st.push(temp->right);
		if(temp->left) st.push(temp->left);
	}
	cout << endl;
}
int main()
{
	node *root = createNode(1);
	root->left = createNode(3);
	root->right = createNode(4);
	root->left->left = createNode(2);
	//root->left->right = createNode(6);
	root->right->left = createNode(7);
	root->right->right = createNode(5);
	levelOrderTraversal(root);
	cout << endl;
	printLevelWise(root);
	inOrderwithoutRecursion(root);
	preorder_without_recursion(root);
	return 0;
}


