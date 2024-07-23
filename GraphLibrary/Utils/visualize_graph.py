# visualize_graph.py
import sys
import networkx as nx
import matplotlib.pyplot as plt

def visualize_graph(edges):
    G = nx.DiGraph()
    G.add_edges_from(edges)
    pos = nx.spring_layout(G)
    
    # Set the background color to black
    plt.figure(figsize=(12, 10), facecolor='black')
    ax = plt.gca()
    ax.set_facecolor('black')
    
    nx.draw(
        G, pos,
        with_labels=True,
        node_color='lightblue',  # Changed for better contrast
        edge_color='lightgray',  # Changed for better contrast
        node_size=2500,          # Adjust node size
        font_size=12,            # Adjust font size
        font_weight='bold',
        edgecolors='w'           # Add white border around nodes
    )
    plt.show()

if __name__ == "__main__":
    # Read edges from command line arguments
    edges = []
    for i in range(1, len(sys.argv), 2):
        u = int(sys.argv[i])
        v = int(sys.argv[i + 1])
        edges.append((u, v))
    visualize_graph(edges)
