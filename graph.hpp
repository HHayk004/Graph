#ifndef GRAPH_HPP
	#define GRAPH_HPP
	
	Graph::Graph(size_t size) : vec(size, std::vector<int>()) {}

	void Graph::addVertex()
	{
		vec.push_back(std::vector<int>());
	}	

	void Graph::addEdge(int vertex1, int vertex2)
	{
		if (vertex1 >= 0 && vertex2 >= 0 && vertex1 < vec.size() && vertex2 < vec.size()
            && vertex1 != vertex2 && !find(vertex1, vertex2))
		{
			vec[vertex1].push_back(vertex2);
		}
	}

    void Graph::removeVertex(int vertex)
    {
        if (vertex >= 0 && vertex < vec.size())
        {
            vec.erase(vec.begin() + vertex);

            for (int i = 0; i < vec.size(); ++i)
            {
                for (int j = 0; j < vec[i].size(); ++j)
                {
                    if (vec[i][j] == vertex)
                    {
                        vec[i].erase(vec[i].begin() + j);
                        break;
                    }
                }
            }
        }
    }

    void Graph::removeEdge(int vertex1, int vertex2)
    {
        for (int i = 0; i < vec[vertex1].size(); ++i)
        {
            if (vec[vertex1][i] == vertex2)
            {
                vec[vertex1].erase(vec[vertex1].begin() + i);
                break;
            }
        }
    }

    int Graph::vertexCount() const
    {
        return vec.size();
    }

    int Graph::edgeCount() const
    {
        int edges_count = 0;
        for (int i = 0; i < vec.size(); ++i)
        {
            edges_count += vec[i].size();
        }

        return edges_count;
    }

    std::vector<int> Graph::vertexEdges(int vertex) const
    {
        return vec[vertex];
    }

    std::vector<int> Graph::shortPath(int vertex1, int vertex2) const
    {
        std::unordered_set<int> visited;
        std::vector<int> path;
        std::vector<int> short_path;
        
        dfs(vertex1, vertex2, visited, path, short_path);

        return short_path;
    }

    void Graph::dfs(int vertex1, int vertex2, std::unordered_set<int>& visited, 
            std::vector<int>& path, std::vector<int>& short_path) const
    { 
        if (short_path.empty() || path.size() <= short_path.size())
        {
            visited.insert(vertex1);
            path.push_back(vertex1);

            if (vertex1 == vertex2)
            {
                short_path = path;
            }
        
            else
            {   
                for (int neigbour : vec[vertex1])
                {
                    if (visited.find(neigbour) == visited.end())
                    {
                        dfs(neigbour, vertex2, visited, path, short_path);
                    }
                }
            }

            visited.erase(vertex1);
            path.pop_back();
        }
    }

    bool Graph::find(int vertex1, int vertex2) const
    {
        for (int i = 0; i < vec[vertex1].size(); ++i)
        {
            if (vec[vertex1][i] == vertex2)
            {
                return true;
            }
        }

        return false;
    }

	void Graph::printGraph() const
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			std::cout << i << " -> ";
			for (int j = 0; j < vec[i].size(); ++j)
			{
				std::cout << vec[i][j] << ' ';
			}
			std::cout << std::endl;
		}
        std::cout << std::endl;
	}

#endif
