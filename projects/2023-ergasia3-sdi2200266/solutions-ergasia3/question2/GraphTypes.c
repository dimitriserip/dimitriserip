#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "GraphTypes.h"
#include "queue.h"

struct graph {
    int n; /* number of vertices in the graph */
    int maxvertex;
    Edge** firstedge;
};

Graph* Initialize(int maxvertex) {
    Graph* graph = (Graph*) malloc(sizeof (Graph));
    graph->n = 0;
    graph->maxvertex = maxvertex;
    graph->firstedge = (Edge**) malloc(sizeof (Edge*) * (maxvertex));

    for (int i = 0; i < maxvertex; i++) {
        graph->firstedge[i] = NULL;
    }

    return graph;
}

void InsertEdge(Graph* graph, Vertex from, Vertex to) {
    if (graph == NULL || from < 1 || to < 1 || from > graph->maxvertex || to > graph->maxvertex) {
        printf("vertex out of range ");
        exit(1);
    }

    from--;
    to--;

    Edge* edge = (Edge*) malloc(sizeof (Edge));
    edge->endpoint = to;

    edge->nextedge = graph->firstedge[from];
    graph->firstedge[from] = edge;


    Edge* reversed_edge = (Edge*) malloc(sizeof (Edge));
    reversed_edge->endpoint = from;

    reversed_edge->nextedge = graph->firstedge[to];
    graph->firstedge[to] = reversed_edge;

    graph->n++;
}

void ShowGraph(Graph* graph) {
    if (graph == NULL) {
        printf("ERROR: graph is null \n");
        return;
    }

    for (int i = 0; i < graph->maxvertex; i++) {
        if (graph->firstedge[i] != NULL) {
            printf(" %d: ", i + 1);

            Edge* edge = graph->firstedge[i];

            while (edge != NULL) {
                printf("%d, ", edge->endpoint);
                edge = edge->nextedge;
            }
            printf("\n");
        }
    }
}

void VisitNode(int vv) {
    printf("%d, ", vv + 1);
}

void BreadthFirstSearch(Graph* graph, Vertex root) {

    bool * visited = (bool *) malloc(sizeof (bool) * (graph->maxvertex));

    for (Vertex v = 0; v < graph->maxvertex; v++) {
        visited[v] = false;
    }

    Queue * queue = queue_create();

    for (Vertex v = 0; v < graph->maxvertex; v++) {
        if (!visited[v]) {
            int * value = malloc(sizeof (int));
            *value = v;
            queue_enqueue(queue, value);

            do {
                int * value = queue_dequeue(queue);
                int vv = *value;
                free(value);

                if (!visited[vv]) {
                    visited[vv] = true;
                    VisitNode(vv);
                }

                Edge *curedge = graph->firstedge[vv];

                while (curedge != NULL) {
                    Vertex w = curedge->endpoint;

                    if (!visited[w]) {
                        int * value = malloc(sizeof (int));
                        *value = w;
                        queue_enqueue(queue, value);
                    }
                    curedge = curedge->nextedge; /*curedge is a pointer to the next edge (v,_) of V */
                }
            } while (!queue_is_empty(queue));
        }
    }

    queue_destroy(queue);

    free(visited);

    printf("\n");
}

bool IsConnected(Graph* graph) {
    bool * visited = (bool *) malloc(sizeof (bool) * (graph->maxvertex));

    for (Vertex v = 0; v < graph->maxvertex; v++) {
        visited[v] = false;
    }

    Queue * queue = queue_create();

    Vertex v = 0;
    
    int * value = malloc(sizeof (int));
    *value = v;
    queue_enqueue(queue, value);

    do {
        int * value = queue_dequeue(queue);
        int vv = *value;
        free(value);

        if (!visited[vv]) {
            visited[vv] = true;
        }

        Edge *curedge = graph->firstedge[vv];

        while (curedge != NULL) {
            Vertex w = curedge->endpoint;

            if (!visited[w]) {
                int * value = malloc(sizeof (int));
                *value = w;
                queue_enqueue(queue, value);
            }
            curedge = curedge->nextedge; /*curedge is a pointer to the next edge (v,_) of V */
        }
    } while (!queue_is_empty(queue));

    queue_destroy(queue);

    bool connected = true;
    
    for (Vertex v = 0; v < graph->maxvertex; v++) {
         if (!visited[v]) {
            connected= false;
            
            printf("not visited: %d \n", v+1);
         }
    }
    
    free(visited);

    return connected;
}

Edge ** ShortestPaths(Graph* graph, Vertex* root) {
    bool * visited = (bool *) malloc(sizeof (bool) * (graph->maxvertex));
    int * parents = (int *)malloc(sizeof (int) * (graph->maxvertex));   
    Edge ** result = (Edge **) malloc(sizeof(Edge *) * (graph->maxvertex));

    for (Vertex v = 0; v < graph->maxvertex; v++) {
        visited[v] = false;
        parents[v] = -1;
        result[v] = NULL;
    }

    Queue * queue = queue_create();

    const Vertex v = *root;
    
    int * value = malloc(sizeof (int));
    *value = v;
    queue_enqueue(queue, value);
        
    //  1   2   3   4   5
    // -1   2   0   1   0 

    do {
        int * value = queue_dequeue(queue);
        int vv = *value;
        free(value);

        if (!visited[vv]) {
            visited[vv] = true;
        } else {
            continue;
        }
        
        Edge *curedge = graph->firstedge[vv];

        while (curedge != NULL) {
            Vertex w = curedge->endpoint;

            if (!visited[w]) {
                int * value = malloc(sizeof (int));
                *value = w;
                if (parents[w] == -1) {
                    parents[w] = vv;
                }
                queue_enqueue(queue, value);
            }
            curedge = curedge->nextedge; /*curedge is a pointer to the next edge (v,_) of V */
        }
    } while (!queue_is_empty(queue));

    queue_destroy(queue);

    for (int i=0;i<graph->maxvertex;i++) {
        printf("%2d ", parents[i]);
    }
    printf("\n");
    
    for (int i=0;i<graph->maxvertex;i++) {
        if (i == v) {
            Edge * e = (Edge* ) malloc(sizeof(Edge));
            e->nextedge = NULL;
            e->endpoint = i;
            result[i] = e;
            continue;
        } else {
            if (parents[i] != -1) {            
                int temp = i;

                do {
                    Edge * e = (Edge* ) malloc(sizeof(Edge));
                    e->endpoint = temp;
                    e->nextedge = result[i];
                    result[i] = e;
//                    printf("temp => %d \n", temp);
                    temp = parents[temp];
                    
                } while (temp != -1);
            }
        }
    }
    
    free(visited);
    free(parents);

    
    return result;       
}

void ConnectedComponents(Graph* graph) {
    
}

int GetTotalVertices(Graph * graph) {
    return graph->maxvertex;
}