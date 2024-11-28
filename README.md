### CP411 Computer Graphics

# Graph Algorithm Simulator (WebGL)

An interactive **Graph Algorithm Simulator** built with **WebGL**, designed to help users visualize and understand the inner workings of various graph algorithms. The simulator provides dynamic visualizations of algorithm steps, making it a valuable tool for students and professionals learning graph theory.

Deployed Version: <a href="https://jashandeep.co.uk/grapher/">jashandeep.co.uk/grapher</a>

##  Features

- **Interactive Graph Creation**

  - Create graphs dynamically by clicking and dragging nodes.
  - Upload adjacency matrices to generate graphs.

- **Supported Algorithms**

  - Dijkstra’s Algorithm
  - Prim’s Algorithm
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)

- **Real-Time Visualization**

  - Step-by-step highlighting of algorithm execution.
  - Animations to show visited nodes and paths.

- **User-Friendly Interface**
  - Mouse-based graph manipulation (add/move nodes, connect edges).
  - Upload adjacency matrices via file input.


<h2>Usage</h2>
<ol>
  <li>Open the simulator in your browser.</li>
  <li>
    <strong>Create a Graph</strong>:
    <ul>
      <li>Click on the canvas to add nodes.</li>
      <li>Drag nodes to reposition them.</li>
      <li>Connect nodes by selecting two nodes in sequence.</li>
    </ul>
  </li>
  <li>
    <strong>Upload Adjacency Matrix</strong>:
    <ul>
      <li>Use the file upload button to load a graph from a matrix.</li>
    </ul>
  </li>
  <li>
    <strong>Run Algorithms</strong>:
    <ul>
      <li>Select an algorithm from the control panel.</li>
      <li>Watch the visualization animate step-by-step.</li>
    </ul>
  </li>
</ol>


<h2>Technologies Used</h2>
<ul>
  <li>
    <strong>WebGL</strong>: For rendering interactive graph visualizations.
  </li>
  <li>
    <strong>JavaScript</strong>: For graph data structure and algorithm logic.
  </li>
  <li><strong>HTML5</strong>: For structuring the web application.</li>
  <li><strong>Tailwind</strong>: For styling the interface.</li>
 
</ul>



## File Structure
<pre>
CP411Project/
├── index.html       # Main HTML file
├── js/
│   ├── app.js       # Controller
│   ├── graph.js     # Model
│   ├── render.js    # View
│   └── utils.js     
├── assets/          
└── README.md        # Project documentation
</pre>


<h2>Acknowledgments</h2>
<ul>
  <li><strong>WebGL Documentation</strong></li>
  <li><strong>Graph Theory Algorithms</strong>: Based on the work of Cormen etal., <em>Introduction to Algorithms</em>.</li>
</ul>
