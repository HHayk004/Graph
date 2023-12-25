#include "graph.h"

int main()
{
	Graph g1;

	for (int i = 0; i < 4; ++i)
	{
		g1.addVertex();
	}

	g1.addEdge(0, 1);
	g1.addEdge(0, 3);
	g1.addEdge(1, 2);
	g1.addEdge(3, 2);
	g1.addEdge(0, 2);
	g1.addEdge(2, 2);
	g1.addEdge(0, 1);
	g1.addEdge(-1, 2);
	g1.addEdge(2, 5);

	g1.printGraph();

    g1.removeVertex(2);

    g1.printGraph();

	return 0;
}
