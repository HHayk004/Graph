#ifndef GRAPH_H
	#define GRAPH_H
	
    #include <iostream>
	#include <vector>

	class Graph {
		private:
			std::vector<std::vector<int>> vec;
		
            bool find(int vertex1, int vertex2) const;

		public:
			Graph(size_t size = 0);
			~Graph() = default;

			void addVertex();
			void addEdge(int vertex1, int vertex2);

            void removeVertex(int vertex);

            void vertexCount() const;

			void printGraph() const;
	};

	#include "graph.hpp"
	
#endif
