#include <stdio.h>  
#include <stdbool.h>  

#define MAX_VERTICES 10  

typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    bool visited[MAX_VERTICES];
} Graph;


typedef struct {
    int queue[MAX_VERTICES];
    int front, rear;
} Queue;


void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

bool isQueueFull(Queue* q) {
    return (q->rear + 1) % MAX_VERTICES == q->front;
}

void enqueue(Queue* q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->queue[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_VERTICES;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->queue[q->front];
    q->front = (q->front + 1) % MAX_VERTICES;
    return value;
}

void DFS(Graph* graph, int startVertex) {
    graph->visited[startVertex] = true;
    printf("%d ", startVertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[startVertex][i] && !graph->visited[i]) {
            DFS(graph, i);
        }
    }
}

void BFS(Graph* graph, int startVertex) {
    Queue q;
    initQueue(&q);

    graph->visited[startVertex] = true;
    enqueue(&q, startVertex);

    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] && !graph->visited[i]) {
                graph->visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}


int main() {
    Graph graph;
    graph.numVertices = 5; 

 
    for (int i = 0; i < graph.numVertices; i++) {
        for (int j = 0; j < graph.numVertices; j++) {
            graph.adjMatrix[i][j] = 0; 
        }
    }

    graph.adjMatrix[0][1] = 1;
    graph.adjMatrix[0][2] = 1;
    graph.adjMatrix[1][3] = 1;
    graph.adjMatrix[2][4] = 1;

    for (int i = 0; i < graph.numVertices; i++) {
        graph.visited[i] = false;
    }

 
    printf("DFS traversal from vertex 0: ");
    DFS(&graph, 0);
    printf("\n");

    for (int i = 0; i < graph.numVertices; i++) {
        graph.visited[i] = false;
    }

    printf("BFS traversal from vertex 0: ");
    BFS(&graph, 0);
}