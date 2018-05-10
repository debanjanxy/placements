#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void swapNodes(struct Node **headref, int a, int b){
	struct Node *temp = &headref, *temp_prev = &headref;
	
	

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 
void printList(struct Node *node){
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
	struct Node *start = NULL;
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
    printf("\n Linked list before calling swapNodes() ");
    printList(start);
    swapNodes(&start, 4, 3);
    printf("\n Linked list after calling swapNodes() ");
    printList(start);
    return 0;
}
