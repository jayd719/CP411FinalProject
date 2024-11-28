// Vertex shader source code
const vertexShaderSource = `
precision mediump float;

attribute vec2 vertPosition;
attribute vec3 vertColor;
varying vec3 fragColor;

void main() {
    fragColor = vertColor;
    gl_Position = vec4(vertPosition, 0.0, 1.0);
}
`;

// Fragment shader source code
const fragmentShaderSource = `
precision mediump float;

varying vec3 fragColor;

void main() {
    gl_FragColor = vec4(fragColor, 1.0);
}
`;

// Initialize WebGL and set up the canvas
const initializeWebGLApp = () => {
  console.log(`App Initialized - ${new Date()}`);

  // Get the canvas element
  const canvas = document.getElementById("canvas");
  if (!canvas) {
    console.error("Canvas element not found!");
    return;
  }

  // Get WebGL context
  const gl = canvas.getContext("webgl");
  if (!gl) {
    console.error("Your browser does not support WebGL");
    return;
  }

  console.log("WebGL initialized successfully");

  // Set the canvas size to match the window dimensions
  canvas.width = window.innerWidth;
  canvas.height = window.innerHeight;

  // Set the clear color for the WebGL context
  gl.clearColor(0.75, 0.7, 0.8, 1.0); // Light gray background
  gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

  // Create and compile vertex shader
  const vertexShader = gl.createShader(gl.VERTEX_SHADER);
  gl.shaderSource(vertexShader, vertexShaderSource);
  gl.compileShader(vertexShader);

  if (!gl.getShaderParameter(vertexShader, gl.COMPILE_STATUS)) {
    console.error(
      "Error compiling vertex shader:",
      gl.getShaderInfoLog(vertexShader)
    );
    return;
  }

  // Create and compile fragment shader
  const fragmentShader = gl.createShader(gl.FRAGMENT_SHADER);
  gl.shaderSource(fragmentShader, fragmentShaderSource);
  gl.compileShader(fragmentShader);

  if (!gl.getShaderParameter(fragmentShader, gl.COMPILE_STATUS)) {
    console.error(
      "Error compiling fragment shader:",
      gl.getShaderInfoLog(fragmentShader)
    );
    return;
  }

  console.log("Shaders compiled successfully");
};

// Initialize the demo
initializeWebGLApp();
