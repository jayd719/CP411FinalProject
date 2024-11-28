class Graph {
  constructor() {
    this.nodes = [];
    this.edges = {};
  }
  addNode(node) {
    this.nodes.push(node);
    this.edges[node] = [];
  }
  addEdge(node1, node2, weight = 1) {
    this.edges[node1].push({ node: node2, weight });
  }
}

function renderGraph(gl, graph) {
    const vertices = [];
    const edges = [];
    
    // Populate vertices and edges from the graph
    graph.nodes.forEach((node, i) => {
      vertices.push(...node.position); // Assume position is [x, y]
    });
    graph.nodes.forEach(node => {
      graph.edges[node].forEach(edge => {
        edges.push(...node.position, ...edge.node.position); // Lines
      });
    });
    
    // WebGL setup for rendering vertices and edges...
  }
  