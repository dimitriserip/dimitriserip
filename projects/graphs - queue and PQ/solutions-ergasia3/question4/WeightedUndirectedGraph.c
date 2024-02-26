#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "WeightedUndirectedGraph.h"
#include "queue.h"
#include "PQ.h"

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

void InsertEdge(Graph* graph, Vertex from, Vertex to, int weight) {
    if (graph == NULL || from < 1 || to < 1 || from > graph->maxvertex || to > graph->maxvertex) {
        printf("vertex out of range ");
        exit(1);
    }

    from--;
    to--;

    Edge* edge = (Edge*) malloc(sizeof (Edge));
    edge->startpoint = from;
    edge->endpoint = to;
    edge->weight = weight;
    edge->symmetric = false;

    edge->nextedge = graph->firstedge[from];
    graph->firstedge[from] = edge;

    Edge* reversed_edge = (Edge*) malloc(sizeof (Edge));
    reversed_edge->startpoint = to;
    reversed_edge->endpoint = from;
    reversed_edge->weight = weight;
    reversed_edge->symmetric = true;

    reversed_edge->nextedge = graph->firstedge[to];
    graph->firstedge[to] = reversed_edge;

    graph->n++;
}

void ShowGraph(Graph* graph) {
    if (graph == NULL) {
        printf("ERROR: graph is null \n");
        return;
    }

    printf("Graph: \n");

    for (int i = 0; i < graph->maxvertex; i++) {
        if (graph->firstedge[i] != NULL) {
            printf(" %d: ", i + 1);

            Edge* edge = graph->firstedge[i];

            while (edge != NULL) {
                printf("%d (%d), ", edge->endpoint + 1, edge->weight);
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
            connected = false;

            printf("not visited: %d \n", v + 1);
        }
    }

    free(visited);

    return connected;
}

Edge ** ShortestPaths(Graph* graph, Vertex* root) {
    bool * visited = (bool *) malloc(sizeof (bool) * (graph->maxvertex));
    int * parents = (int *) malloc(sizeof (int) * (graph->maxvertex));
    Edge ** result = (Edge **) malloc(sizeof (Edge *) * (graph->maxvertex));

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

    for (int i = 0; i < graph->maxvertex; i++) {
        printf("%2d ", parents[i]);
    }
    printf("\n");

    for (int i = 0; i < graph->maxvertex; i++) {
        if (i == v) {
            Edge * e = (Edge*) malloc(sizeof (Edge));
            e->nextedge = NULL;
            e->endpoint = i;
            result[i] = e;
            continue;
        } else {
            if (parents[i] != -1) {
                int temp = i;

                do {
                    Edge * e = (Edge*) malloc(sizeof (Edge));
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

Graph * MinimumSpanningTree(Graph* graph) {

    Graph * g = Initialize(graph->maxvertex);

    PriorityQueue* pq = PriorityQueueInitialize(graph->n);


    for (int i = 0; i < graph->maxvertex; i++) {
        if (graph->firstedge[i] != NULL) {
            Edge* edge = graph->firstedge[i];

            while (edge != NULL) {
                if (edge->symmetric == false) {
                    PriorityQueueInsert(pq, edge);
                }
                edge = edge->nextedge;
            }
        }
    }

    int N = graph->maxvertex;
    int id[N], sz[N];

    for (int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    while (!PriorityQueueEmpty(pq)) {
        Edge * edge = PriorityQueueRemove(pq);
        printf("Edge removed: %d -> %d (%d) \n", edge->startpoint + 1, edge->endpoint + 1, edge->weight);

        int p = edge->startpoint;
        int q = edge->endpoint;
        int i = 0,j = 0;
        
        //
        // check if p and q are already connected:
        //
        for (i = p; i != id[i]; i = id[i]) {
            id[i] = id[id[i]];
        }
        for (j = q; j != id[j]; j = id[j]) {
            id[j] = id[id[j]];
        }
        if (i == j) {
            // already connected, skip edge.
            continue;
        }
        
        //
        // connect
        //
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }

        InsertEdge(g, p + 1, q + 1, edge->weight);
    }

    return g;
}