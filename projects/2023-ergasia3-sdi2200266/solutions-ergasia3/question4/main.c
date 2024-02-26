#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "WeightedUndirectedGraph.h"
#include "queue.h"

Graph* loadFile(const char* filename) {
    FILE* fp = fopen(filename, "r");
    char buffer[4000];

    if (fp == NULL) {
        return NULL;
    }

    // read first line
    fgets(buffer, 4000, fp);

    int n = atoi(buffer);

    Graph* g = Initialize(n);

    while (fgets(buffer, 4000, fp)) {
        char* first = strtok(buffer, "-\n");
        char* second = strtok(NULL, "-\n");
        char* third = strtok(NULL, "-\n");

        if (isalpha(first[0])) {
            Vertex n1 = first[0] - 'A' + 1;
            Vertex n2 = second[0] - 'A' + 1;
            int weight = atoi(third);

            printf("Creating edge %d (%c) to %d (%c) with weight %d for file %s \n", n1, first[0], n2, second[0], weight, filename);
            InsertEdge(g, n1, n2, weight);
        } else {
            Vertex n1 = atoi(first);
            Vertex n2 = atoi(second);
            int weight = atoi(third);

            printf("Creating edge %d to %d with weight %d for file %s \n", n1, n2, weight, filename);
            InsertEdge(g, n1, n2, weight);
        }
    }

    fclose(fp);

    return g;
}

void test_queue() {
    Queue * queue = queue_create();
    int N = 100;

    for (int i = 0; i < N; i++) {
        int * value = (int *) malloc(sizeof (int));
        *value = i;
        queue_enqueue(queue, value);
    }


    for (int i = 0; i < N; i++) {
        int * value = (int*) queue_dequeue(queue);
        if (*value != i) {
            printf("queue error \n");
            exit(1);
        }
        free(value);
    }

    queue_destroy(queue);

    printf("queue ok \n");

    exit(0);
}

int main(int argc, char* argv[]) {
    Graph* g1 = loadFile("graph_edge_p4.txt");
    Graph* g2 = loadFile("graph_edge_p7_minimum_spanning_tree.txt");

    if (g1 == NULL) {
        printf("Error while reading .. graph_edge_p4 \n");
        return 1;
    }

    if (g2 == NULL) {
        printf("Error while reading .. graph_edge_p7_minimum_spanning_tree \n");
        return 1;
    }

    printf("-------------------- G1 ----------------------\n");
    ShowGraph(g1);

    printf("-------------------- G2 ----------------------\n");
    ShowGraph(g2);

    printf("-------------------- G1 MST ----------------------\n");
    Graph * g1_mst = MinimumSpanningTree(g1);
    
    ShowGraph(g1_mst);
    
        
    Graph * g2_mst = MinimumSpanningTree(g2);
    
    ShowGraph(g2_mst);






    // printf("-------------------- G1 BFS ----------------------\n");
    // BreadthFirstSearch(g1, 1);

    // printf("-------------------- G2 BFS ----------------------\n");
    // BreadthFirstSearch(g2, 1);

    // printf("-------------------- G3 BFS ----------------------\n");
    // BreadthFirstSearch(g3, 1);


    // printf("Graph G1 is connected: %d \n", IsConnected(g1));
    // printf("Graph G2 is connected: %d \n", IsConnected(g2));
    // printf("Graph G3 is connected: %d \n", IsConnected(g3));

    // Vertex root = 0;

    // Edge ** sp1 = ShortestPaths(g1, &root);
    // Edge ** sp2 = ShortestPaths(g2, &root);
    // Edge ** sp3 = ShortestPaths(g3, &root);
    // int n1 = GetTotalVertices(g1);
    // int n2 = GetTotalVertices(g2);
    // int n3 = GetTotalVertices(g3);


    // printf("---------------- G1 Shortest path -----------------\n");
    // for (int i=0;i<n1;i++) {
    //     printf("from:%2d to %2d: ", 1, i+1);

    //     Edge * list = sp1[i];

    //     while (list != NULL) {
    //         printf("%d -> ", list->endpoint + 1);
    //         list=list->nextedge;
    //     }

    //     printf(" null \n");
    // }

    // printf("---------------- G2 Shortest path -----------------\n");

    // for (int i=0;i<n2;i++) {
    //     printf("from:%2d to %2d: ", 1, i+1);

    //     Edge * list = sp2[i];

    //     while (list != NULL) {
    //         printf("%d -> ", list->endpoint + 1);
    //         list=list->nextedge;
    //     }

    //     printf(" null \n");
    // }


    // printf("---------------- G3 Shortest path -----------------\n");

    // for (int i=0;i<n3;i++) {
    //     printf("from:%2d to %2d: ", 1, i+1);

    //     Edge * list = sp3[i];

    //     while (list != NULL) {
    //         printf("%d -> ", list->endpoint + 1);
    //         list=list->nextedge;
    //     }

    //     printf(" null \n");
    // }

    return 0;
}
