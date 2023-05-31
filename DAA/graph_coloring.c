#include <stdio.h>
#define V 7 
int isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}
int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        return 1;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1) == 1) {
                return 1;
            }
            color[v] = 0;
        }
    }
    return 0;
}
void graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;  
    }

    if (graphColoringUtil(graph, m, color, 0) == 0) {
        printf("Solution does not exist.\n");
        return;
    }

    printf("Solution exists with the following colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}
int main() {
    int graph[V][V] = {
        {0,1,1,1,0,0,0},
                     {1,0,1,0,0,0,0},
                     {1,1,0,1,1,0,0},
                     {1,0,1,0,1,0,0},
                     {0,0,1,1,0,1,1},
                     {0,0,0,0,1,0,0}, 
                     {0,0,0,0,1,0,0}
    };
    int m = 3;  // Number of colors

    graphColoring(graph, m);

    return 0;
}
