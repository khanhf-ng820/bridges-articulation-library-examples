import networkx as nx
import matplotlib.pyplot as plt

# Create an empty graph
G = nx.Graph()

edges = [
    ("A", "B"),
    ("B", "C"),
    ("B", "D"),
    ("D", "E"),
    ("C", "E"),
    ("E", "F")
]

# Add nodes
G.add_node("A")
G.add_node("B")
G.add_node("C")

# Add edges
G.add_edges_from(edges)

# Draw the graph
nx.draw(G, with_labels=True)

# Show graph window
plt.show()
