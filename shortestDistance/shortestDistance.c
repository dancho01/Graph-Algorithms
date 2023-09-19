
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int shortestDistance(Graph g, int src, int dest) {
	// TODO: Dijkstra algo
	Vertex v;
	int nV = GraphNumVertices(g);
	int *visited = calloc(nV, sizeof(int));

	for (int v = 0; v < nV; v++) {
		visited[v] = -1;
	}
	visited[src] = src;
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	bool found = false;
	while (!QueueIsEmpty(q)) {
		v = QueueDequeue(q);
		for (int w = 0; w < nV; w++) {
			if (GraphIsAdjacent(g, v, w) && visited[w] == -1) {
				visited[w] = v;
				if (w == dest) {
					found = true;
				} else {
					QueueEnqueue(q, w);	
				}	
			}
		}
	}
	if (!found && src != dest) {
		QueueFree(q);
		free(visited);	
		return -1;
	}
	int num = 1;
	while (visited[dest] != src) {
		num += 1;
		dest = visited[dest];
	}
	QueueFree(q);
	free(visited);
	if (src == dest) {
		return 0;
	} else {
		return num;
	} 
}
