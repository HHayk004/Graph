#include "graph.h"

int main()
{
	Graph g1;

	for (int i = 0; i < 10; ++i)
	{
		g1.addVertex();
	}

	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 3);
	g1.addEdge(1, 5);
	g1.addEdge(1, 4);
	g1.addEdge(1, 8);
	g1.addEdge(2, 4);
	g1.addEdge(2, 9);
	g1.addEdge(3, 5);
	g1.addEdge(4, 7);
	g1.addEdge(5, 6);
	g1.addEdge(6, 7);
	g1.addEdge(7, 8);
	g1.addEdge(8, 9);

	g1.printGraph();

    g1.levelOrder(0);    

	return 0;
}
