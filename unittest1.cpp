#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "../Dijkstra/Dijkstra.h"
#include "../Dijkstra/Dijkstra.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
/*
std::string testFile1 = R"(SPb;Moskva;13;9
Tambov;Moskva;25;N/A
Tambov;SPb;10;16

Ekb;SPb;45;30
Ekb;Moskva;25;20
end)";*/

namespace DijkstraTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Разместите здесь код своего теста
		}

		TEST_METHOD(Dijkstra_straight) 
		{
			Dijkstra dd;
			dd.paths[0] = "SPb;Moskva;13;9";
			dd.paths[1] = "Tambov;Moskva;25;N/A";
			dd.paths[2] = "Tambov;SPb;10;16";
			dd.paths[3] = "Ekb;SPb;45;30";
			dd.paths[4] = "Ekb;Moskva;25;20";

			dd.fill_adjacency_list(5);
					
			Assert::IsTrue(dd.Dijkstra_algorithm("SPb", "Tambov") == 16);
		}

		TEST_METHOD(Dijkstra_not_straight_and_connected)
		{
			Dijkstra dd;
			dd.paths[0] = "SPb;Moskva;13;9";
			dd.paths[1] = "Tambov;Moskva;25;N/A";
			dd.paths[2] = "Tambov;SPb;10;16";
			dd.paths[3] = "Ekb;SPb;45;30";
			dd.paths[4] = "Ekb;Moskva;25;20";

			dd.fill_adjacency_list(5);

			Assert::IsTrue(dd.Dijkstra_algorithm("Ekb", "SPb") == 34);
		}

		TEST_METHOD(Dijkstra_not_connected_cities_with_path)
		{
			Dijkstra dd;
			dd.paths[0] = "SPb;Moskva;13;9";
			dd.paths[1] = "Tambov;Moskva;25;N/A";
			dd.paths[2] = "Tambov;SPb;10;16";
			dd.paths[3] = "Ekb;SPb;45;30";
			dd.paths[4] = "Ekb;Moskva;25;20";

			dd.fill_adjacency_list(5);

			Assert::IsTrue(dd.Dijkstra_algorithm("Ekb", "Tambov") == 50);
		}

		TEST_METHOD(Dijkstra_not_connected_without_path)
		{
			Dijkstra dd;
			dd.paths[0] = "SPb;Moskva;13;9";
			dd.paths[1] = "Tambov;Moskva;25;N/A";
			dd.paths[2] = "Tambov;SPb;10;16";
			dd.paths[3] = "Ekb;SPb;45;30";
			dd.paths[4] = "Ekb;Moskva;25;20";
			dd.paths[5] = "Tiksi;Ekb;N/A;N/A";

			dd.fill_adjacency_list(6);

			Assert::IsTrue(dd.Dijkstra_algorithm("Tiksi", "Tambov") == 1000000); // here 1000000 = infinity
		}

		TEST_METHOD(Dijkstra_final_city_is_start_city)
		{
			Dijkstra dd;
			dd.paths[0] = "SPb;Moskva;13;9";
			dd.paths[1] = "Tambov;Moskva;25;N/A";
			dd.paths[2] = "Tambov;SPb;10;16";
			dd.paths[3] = "Ekb;SPb;45;30";
			dd.paths[4] = "Ekb;Moskva;25;20";

			dd.fill_adjacency_list(5);

			Assert::IsTrue(dd.Dijkstra_algorithm("SPb", "SPb") == 0);
		}

		

	};
}