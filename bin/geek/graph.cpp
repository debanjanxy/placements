#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct AdjListNode{
	int dest;
	struct AdjListNode *next;
};

struct AdjList{
	struct AdjListNode *head;
};

struct Graph{
	int V;
	struct AdjList *arr;
};

struct AdjListNode *newAdjListNode(int dest){
	struct AdjListNode *newnode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newnode->dest = dest;
	newnode->next = NULL;
	return newnode;
}

struct Graph *createGraph(int V){
	struct Graph *newgraph = (struct Graph*)malloc(sizeof(struct Graph));
	newgraph->V = V;
	newgraph->arr = (struct AdjList*)malloc(V*sizeof(struct AdjList));
	for(int i=0;i<V;i++){
		newgraph->arr[i].head = NULL;
	}
	return newgraph;
}

void addEdge(struct Graph *graph, int src, int dest){
	struct AdjListNode *newnode = newAdjListNode(dest);
	newnode->next = graph->arr[src].head;
	graph->arr[src].head = newnode;

	newnode = newAdjListNode(src);
	newnode->next = graph->arr[dest].head;
	graph->arr[dest].head = newnode;
}

void printGraph(struct Graph *graph){
	int v;
	for(int i=0;i<graph->V;i++){
		struct AdjListNode *temp = graph->arr[i].head;
		printf("\n Adjacency list of vertex %d\n head ",i);
		while(temp){
			printf("-> %d",temp->dest);
			temp = temp->next;
		}
	}
	cout << endl;
}

int main(){
	int V = 5;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
    return 0;
}













