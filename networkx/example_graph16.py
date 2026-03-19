import networkx as nx
import matplotlib.pyplot as plt

# Create graph
G = nx.Graph()

edges = [
    ("A", "B"),
    ("A", "C"),
    ("B", "C"),
    ("B", "D"),
    ("C", "E"),
    ("D", "E"),
    ("D", "F"),
    ("E", "F"),
    ("E", "G"),
    ("F", "H"),
    ("G", "H"),
    ("H", "I"),
    ("I", "J"),
    ("J", "G"),
    ("J", "K"),
    ("K", "L"),
    ("L", "M"),
    ("M", "K"),
    ("L", "N"),
    ("N", "O"),
    ("O", "P"),
    ("P", "N")
]
G.add_edges_from(edges)

# Find bridges and articulation points
bridges = list(nx.bridges(G))
articulation_points = list(nx.articulation_points(G))

print("Bridges:", bridges)
print("Articulation points:", articulation_points)

# Layout for drawing
pos = nx.spring_layout(G)

# Node colors
node_colors = []
for node in G.nodes():
    if node in articulation_points:
        node_colors.append("red")
    else:
        node_colors.append("lightblue")

# Edge colors
edge_colors = []
for edge in G.edges():
    if edge in bridges or (edge[1], edge[0]) in bridges:
        edge_colors.append("red")
    else:
        edge_colors.append("black")

# Draw graph
nx.draw(
    G,
    pos,
    with_labels=True,
    node_color=node_colors,
    edge_color=edge_colors,
    node_size=200,
    font_size=8
)

plt.title("Bridges (Red edges) and Articulation Points (Red vertices)")
plt.show()
