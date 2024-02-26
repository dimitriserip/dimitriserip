#pragma once

#include <stdbool.h>


typedef int Vertex;

typedef struct edge Edge;

typedef struct graph Graph;

struct edge {
    Vertex endpoint;
    struct edge* nextedge;
};

Graph * Initialize(int maxvertex);

void InsertEdge(Graph * graph,Vertex from,Vertex to);

void ShowGraph(Graph * graph);

void BreadthFirstSearch(Graph * graph,Vertex root);

bool IsConnected(Graph * graph);

Edge ** ShortestPaths(Graph * graph,Vertex * root);

void ConnectedComponents(Graph * graph);


int GetTotalVertices(Graph * graph);