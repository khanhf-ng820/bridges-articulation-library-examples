#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/biconnected_components.hpp>

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

	Graph g(7);

	add_edge(0, 1, g);
	add_edge(1, 2, g);
	add_edge(0, 3, g);
	add_edge(1, 4, g);
	add_edge(2, 5, g);
	add_edge(3, 4, g);
	add_edge(4, 5, g);
	add_edge(4, 6, g);

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
