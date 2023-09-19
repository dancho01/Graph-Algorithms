
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

static void recursive(Graph g, int v, bool *visited, int nV);

void depthFirstSearch(Graph g, int src) {
	// TODO
	int nV = GraphNumVertices(g);
	bool *visited = calloc(nV, sizeof(bool));

	for (int v = 0; v < nV; v++) {
		visited[v] = false;
	}
	recursive(g, src, visited, nV);
	free(visited);
}

static void recursive(Graph g, int v, bool *visited, int nV) {
	visited[v] = true;
	printf("%d ", v);
	for (int i = 0; i < nV; i++) {
		if (GraphIsAdjacent(g, v, i)) {
			if (!visited[i]) {
				recursive(g, i, visited, nV);
			}
		}
	}
}

