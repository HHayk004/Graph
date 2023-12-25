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
	}

#endif
