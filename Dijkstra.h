#pragma once
#include <fstream>
#include <iostream>
#include "../AiStrD_4.2/Map.h"
#include "../AiStrD_4.2/Map.cpp"
#include "../Sem4_Lab1/List.h"
#include <string>
using namespace std;

class Dijkstra;

struct adjacencyNode
{
	size_t city;
	size_t distance;
	List<adjacencyNode*> connections;

	friend Dijkstra;

	adjacencyNode()
	{
		city = 0;
		distance = 0;
	};
};

class Dijkstra
{
	List<adjacencyNode*> adjacencyList;
	
	Map<string, size_t> cities;

public:
	
	size_t Dijkstra_algorithm(string start_city_name, string final_city_name);

	void fill_adjacency_list(size_t paths_size);

	size_t read_doc(string file_name);
	
	char* paths[100];

	~Dijkstra()
	{
		adjacencyList.clear();
		cities.~Map();
	};
};
