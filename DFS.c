#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

//Define a node structure of Adjacent List about Graph
typedef struct graphNode {
	int vertex;
	struct graphNode* link;
} graphNode;

typedef struct graphType {
	int n;			//vertex count
	graphNode* adjList_H[MAX_VERTEX];	//head node array
	int visited[MAX_VERTEX];	//visited flag array
} graphType;

//Stack

typedef int element;

typedef struct stackNode {
	int data;
	struct stackNode *link;
} stackNode;


stackNode *top;

//function if a stack is blank
int isEmpty() {
	if (top==NULL) return 1;
	else return 0;
}

//function which can push()
void push(int item){
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

//functino which can pop()
int pop() {
	int item;
	stackNode* temp = top;
	
	if (isEmpty()) {
		printf("\n\n Stack is Empty! \n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

//function which initialize a stack	
void createGraph(graphType* g) {
	int v;
	for (v=0; v<MAX_VERTEX; v++){
		g->visited[v] = FALSE;
		g->adjList_H[v] = NULL;
	}
}

//function which insert vertex v into graph g
void insertVertex(graphType* g, int v){
	if (((g->n)+1) >MAX_VERTEX) {
		printf("\n Graph vertex Overflow!\n");
		return;
	}
	g->n++;
}

//function insert an edge(u,v) into graph g
void insertEdge(graphType* g, int u, int v) {
	graphNode* node;
	if (u>=g->n || v>=g->n) {
		printf("\n not exists vertex in graph!\n");
		return;
	}
	node = (graphNode *)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}

//this function print Adjacent List about each vertices of graph g
void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t Vertex %d's Adjacent List", i+65);
		p = g->adjList_H[i];
		while(p){
			printf("-> %c", p->vertex + 65);
			p = p->link;
		}
	}
}

//function which is DFS about vertex v
void DFS_adjList(graphType* g, int v){
	graphNode* w;
	top = NULL;
	push(v);
	g->visited[v] = TRUE;
	printf(" %c", v+65);
	
	//repeat DFS while stack is not emtpy
	while (isEmpty()) {
		w = g->adjList_H[v];
		//do while adjacent vertex exists
		while (w) {
			//case that is not visited now vertex w
			if (g->visited[w->vertex]){
				push(w->vertex);
				g->visited[w->vertex] = TRUE;
				printf(" %c", w->vertex + 65);
				v = w->vertex;
			}
			//case that has been visited already
			else w = w->link;
		}
		v = pop();	//if there's no visting adjacent vertex at now vertex
	}	//if stack is empty, then end DFS()
}

void main() {
	int i;
	graphType *G9;
	G9 = (graphType *)malloc(sizeof(graphType));
	createGraph(G9);
	
	for (i = 0; i<7; i++){
		insertVertex(G9,i);
	}
	
	insertEdge(G9, 0, 2);
	insertEdge(G9, 0, 1);
	insertEdge(G9, 1, 4);
	insertEdge(G9, 1, 3);
	insertEdge(G9, 1, 0);
	insertEdge(G9, 2, 4);
	insertEdge(G9, 2, 0);
	insertEdge(G9, 3, 6);
	insertEdge(G9, 3, 2);
	insertEdge(G9, 4, 1);
	insertEdge(G9, 4, 6);
	insertEdge(G9, 4, 5);
	insertEdge(G9, 5, 4);
	insertEdge(G9, 6, 3);
	insertEdge(G9, 6, 2);
	insertEdge(G9, 6, 2);
	printf("\n G9's Adjacent List ");
	print_adjList(G9);
	
	printf("\n\n ****************************DFS*************");
	DFS_adjList(G9, 0);
	
	getchar();
}
	
















