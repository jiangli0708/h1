#include <stdio.h>  
#include <limits.h>  

#define MAX_VERTICES 100  


typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;
 
void initializeGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i == j) {
                graph->adjMatrix[i][j] = 0; 
            }
            else {
                graph->adjMatrix[i][j] = INT_MAX;   
            }
        }
    }
}
 
void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight; 
}


void dijkstra(Graph* graph, int src) {
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES];

 
    for (int i = 0; i < graph->numVertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0; 


    for (int count = 0; count < graph->numVertices - 1; count++) {
        int u = -1;
        int min = INT_MAX;

        for (int v = 0; v < graph->numVertices; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        visited[u] = true; 


        for (int v = 0; v < graph->numVertices; v++) {
            if (!visited[v] && graph->adjMatrix[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + graph->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->adjMatrix[u][v];
            }
        }
    }


    printf("Shortest path from vertex %d to all other vertices:\n", src);
    for (int i = 0; i < graph->numVertices; i++) {
        if (dist[i] == INT_MAX) {
            printf("Vertex %d: Not reachable\n", i);
        }
        else {
            printf("Vertex %d: Distance = %d\n", i, dist[i]);
        }
    }
}

int main() {
    Graph graph;
    initializeGraph(&graph, 5); 

  
    addEdge(&graph, 0, 1, 10);
    addEdge(&graph, 0, 4, 30);
    addEdge(&graph, 1, 2, 15);
    addEdge(&graph, 2, 3, 4);
    addEdge(&graph, 3, 1, 20);
    addEdge(&graph, 3, 4, 10);


    dijkstra(&graph, 0);

    return 0;
}