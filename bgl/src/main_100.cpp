#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/biconnected_components.hpp>

namespace fs = std::filesystem;
using namespace boost;

int main() {
	typedef adjacency_list<
		vecS,
		vecS,
		undirectedS,
		no_property,
		property<edge_index_t, int>
	> Graph;

	typedef graph_traits<Graph>::vertex_descriptor Vertex;
	typedef graph_traits<Graph>::edge_descriptor Edge;

	Graph g(100);

	// Read dataset file and add edges to graph
	const fs::path datasetPath = fs::path(DATASET_DIR) / "dataset_100.inp";
	if (fs::exists(datasetPath)) {
		std::ifstream datasetFile(datasetPath);
		if (!datasetFile.is_open()) {
			std::cerr << "Failed to open file: " << datasetPath << std::endl;
			return 1;
		}

		int v1, v2;
		while (datasetFile >> v1 >> v2) {
			add_edge(--v1, --v2, g);
		}

		datasetFile.close();
	} else {
		std::cerr << "File not found: " << datasetPath << std::endl;
	}



	// Assign edge indices
	auto edge_index_map = get(edge_index, g);
	int i = 0;
	graph_traits<Graph>::edge_iterator ei, ei_end;
	for (tie(ei, ei_end) = edges(g); ei != ei_end; ++ei) {
		edge_index_map[*ei] = i++;
	}

	std::vector<Vertex> articulation_points;
	std::vector<int> component(num_edges(g));

	// NOTE: biconnected_components returns a pair in this Boost version
	auto result = biconnected_components(
		g,
		make_iterator_property_map(component.begin(), edge_index_map),
		std::back_inserter(articulation_points)
	);

	int num_comps = result.first;

	// Count edges per component
	std::vector<int> comp_count(num_comps, 0);
	int idx = 0;
	for (tie(ei, ei_end) = edges(g); ei != ei_end; ++ei, ++idx) {
		comp_count[component[idx]]++;
	}

	std::cout << "Articulation Points:\n";
	for (Vertex v : articulation_points) {
		std::cout << v << "\n";
	}

	std::cout << "\nBridges:\n";
	idx = 0;
	for (tie(ei, ei_end) = edges(g); ei != ei_end; ++ei, ++idx) {
		if (comp_count[component[idx]] == 1) {
			std::cout << source(*ei, g)
					  << " -- "
					  << target(*ei, g)
					  << "\n";
		}
	}

	return 0;
}
