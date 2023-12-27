#ifndef GRAPH_H
	#define GRAPH_H
	
    #include <iostream>
	#include <vector>
    #include <queue>
    #include <unordered_set>

	class Graph {
		private:
			std::vector<std::vector<int>> vec;
		
            void dfs(int vertex1, int vertex2, std::unordered_set<int>& visited, 
                     std::vector<int>& path, std::vector<int>& short_path) const;

		public:
			Graph(size_t size = 0);
			~Graph() = default;

			void addVertex();
			void addEdge(int vertex1, int vertex2);

            void removeVertex(int vertex);
            void removeEdge(int vertex1, int vertex2);

            int vertexCount() const;
            int edgeCount() const;

            std::vector<int> vertexEdges(int vertex) const;

            bool find(int vertex1, int vertex2) const;

            std::vector<int> shortPath(int vertex1, int vertex2) const;
            void levelOrder(int vertex) const;

			void printGraph() const;
	};

	#include "graph.hpp"
	
#endif
