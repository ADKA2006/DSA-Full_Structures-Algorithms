#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include "List.hpp"
#include <fstream>
#include <sstream>

enum STATUS {FAILED = 0, SUCCESS = 1};

class Graph{
private:
	struct edgeNode{
		int v;
		edgeNode(int v_):v{v_}{}
		edgeNode():v{0}{}
		};

		int n_vertices;
		int n_edges;
		List<edgeNode *> *adjList;

		Graph():n_vertices{0}, n_edges{0}, adjList{nullptr} {};
public:
	static Graph* create_graph(std::string path);
	void bfs(int s);
	void dfs(int s);
	void print();
	};

Graph* Graph::create_graph(std::string path)
{
	std::ifstream in{path};

	if (!in)
	{
		std::cerr << "File Open Failed " << std::endl;
		std::cerr << "Check File : " << path << std::endl;
		return nullptr;
	}
	else
	{
		Graph *G = new Graph();
		std::string line;
		int u, v;
		int n_vertices_, n_edges_;

		if (!std::getline(in, line))
		{
			std::cerr << "Vertex Information Missing " << std::endl;
			return nullptr;
		}
		{
			std::istringstream iss(line);
			if (!(iss >> n_vertices_) || (iss >> std::ws && !iss.eof()))
			{
				std::cerr << "Vertex Information Missing : Instead found " << line << '\n';
				return nullptr;
			}
		}


		if (!std::getline(in, line))
		{
			std::cerr << "Edge Information Missing" << std::endl;
			return nullptr;
		}
		{
			std::istringstream iss(line);
			if (!(iss >> n_edges_) || (iss >> std::ws && !iss.eof()))
			{
				std::cerr << "Edge Information Missing : Instead Found  " << line << '\n';
				return nullptr;
			}
		}

		std::cout << "n_vertices : " << n_vertices_ << " " << "n_edges : " << n_edges_ << std::endl;

		G->adjList = new List<edgeNode *>[n_vertices_];
		G->n_vertices = n_vertices_;
		G->n_edges = n_edges_;

		edgeNode *node;


		while(std::getline(in, line))
			{
				std::istringstream iss(line);

				if (!(iss >> u >> v) || (iss >> std::ws && !iss.eof()))
				{
					std::cerr << "Parsing Failed : Check Content for Format " << std::endl;
				}
				//std::cout << "u : " << u <<" " << "v: " << v << std::endl;
				if ((u > n_vertices_) || (v > n_vertices_))
				{
					std::cerr <<"Nodes Should be between " << 0 << " and " << n_vertices_ << std::endl;
					delete G;
					return nullptr;
				}

				node = new edgeNode(v);
				G->adjList[u].add(node);
			}
		return G;
	}
}

void Graph::print()
{
	edgeNode *node;

	for(int u=0; u<n_vertices; u++)
	{
		std::cout << u << " : ";
		for (bool status=adjList[u].begin(node); status != false; status = adjList[u].getNext(node))
		{
			std::cout << node->v << " ";
		}
		std::cout << std::endl;
	}
}


#endif
