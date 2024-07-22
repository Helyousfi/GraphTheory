# visualize_graph.py
import sys
import networkx as nx
import matplotlib.pyplot as plt

def visualize_graph(edges):
    G = nx.DiGraph()
    G.add_edges_from(edges)
    pos = nx.spring_layout(G)
    nx.draw(G, pos, with_labels=True, node_color='skyblue', edge_color='gray', node_size=2000, font_size=15, font_weight='bold')
    plt.show()

if __name__ == "__main__":
    # Read edges from command line arguments
    edges = []
    for i in range(1, len(sys.argv), 2):
        u = int(sys.argv[i])
        v = int(sys.argv[i + 1])
        edges.append((u, v))
    visualize_graph(edges)
