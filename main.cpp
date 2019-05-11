#include <fstream>
#include <iostream>
#include "Dijkstra.h"
using namespace std;

int main()
{
	Dijkstra dd;
	dd.fill_adjacency_list(dd.read_doc("paths.txt"));
	//dd.fill_adjacency_list();

	string start_city, final_city;
	cout << "Minimal cost from ";
	cin >> start_city;
	cout << " to ";
	cin >> final_city;
	cout<<" is "<<dd.Dijkstra_algorithm(start_city, final_city)<<endl;

	dd.~Dijkstra();
	system("pause");
	return 0;
}