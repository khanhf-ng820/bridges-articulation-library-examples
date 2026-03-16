import networkx as nx
import matplotlib.pyplot as plt

# Create an empty graph
G = nx.Graph()

# Add nodes
G.add_node("A")
G.add_node("B")
G.add_node("C")

# Add edges
G.add_edge("A", "B")
G.add_edge("A", "C")
G.add_edge("B", "C")

# Draw the graph
nx.draw(G, with_labels=True)

# Show graph window
plt.show()
