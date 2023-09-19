
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirstSearch(Graph g, int src) {
	// TODO
	Vertex v;
	int nV = GraphNumVertices(g);
	bool *visited = calloc(nV, sizeof(bool));
	for (int v = 0; v < nV; v++) {
		visited[v] = false;
	}
	visited[src] = true;
	printf("%d ", src);
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	while (!QueueIsEmpty(q)) {
		v = QueueDequeue(q);
		for (int w = 0; w < nV; w++) {
			if (GraphIsAdjacent(g, v, w) && !visited[w]) {
				visited[w] = true;
				printf("%d ", w);
				QueueEnqueue(q, w);
			}
		}
	}
	QueueFree(q);
	free(visited);
}



