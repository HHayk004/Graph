#include "graph.h"

int main()
{
	Graph g1;

	for (int i = 0; i < 10; ++i)
	{
		g1.addVertex();
	}

	g1.addEdge(0, 2, 20);
	g1.addEdge(0, 1, 3);
	g1.addEdge(1, 3, 9);
	g1.addEdge(1, 4, 4);
	g1.addEdge(2, 9, 30);
	g1.addEdge(3, 6, 1);
	g1.addEdge(4, 5, 1);
	g1.addEdge(5, 6, 5);
	g1.addEdge(5, 7, 1);
	g1.addEdge(6, 9, 1);
	g1.addEdge(7, 8, 2);
	g1.addEdge(8, 9, 5);

    g1.printGraph();

    std::vector<int> vec = g1.dijkstra(0);

    for (auto& elem : vec)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

	return 0;
}
