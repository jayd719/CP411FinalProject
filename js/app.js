const canvas = document.getElementById('webglCanvas');
const gl = canvas.getContext('webgl') || canvas.getContext('experimental-webgl');

if (!gl) {
    alert('Your browser does not support WebGL');
    throw new Error('WebGL not supported');
}

// Vertex Shader
const vertexShaderSource = `
    attribute vec3 position;
    attribute vec3 color;
    uniform mat4 modelViewMatrix;
    uniform mat4 projectionMatrix;
    varying vec3 vColor;

    void main() {
        gl_Position = projectionMatrix * modelViewMatrix * vec4(position, 1.0);
        vColor = color;
    }
`;

// Fragment Shader
const fragmentShaderSource = `
    precision mediump float;
    varying vec3 vColor;

    void main() {
        gl_FragColor = vec4(vColor, 1.0);
    }
`;

// Compile Shader
function compileShader(gl, source, type) {
    const shader = gl.createShader(type);
    gl.shaderSource(shader, source);
    gl.compileShader(shader);
    if (!gl.getShaderParameter(shader, gl.COMPILE_STATUS)) {
        console.error('Shader compilation failed:', gl.getShaderInfoLog(shader));
        gl.deleteShader(shader);
        return null;
    }
    return shader;
}

// Program Setup
const vertexShader = compileShader(gl, vertexShaderSource, gl.VERTEX_SHADER);
const fragmentShader = compileShader(gl, fragmentShaderSource, gl.FRAGMENT_SHADER);

const program = gl.createProgram();
gl.attachShader(program, vertexShader);
gl.attachShader(program, fragmentShader);
gl.linkProgram(program);

if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
    console.error('Program linking failed:', gl.getProgramInfoLog(program));
}

// Cube Data
const vertices = new Float32Array([
    // Front face
    -0.5, -0.5, 0.5,   1, 0, 0,
     0.5, -0.5, 0.5,   0, 1, 0,
     0.5,  0.5, 0.5,   0, 0, 1,
    -0.5,  0.5, 0.5,   1, 1, 0,
    // Back face
    -0.5, -0.5, -0.5,  1, 0, 1,
     0.5, -0.5, -0.5,  0, 1, 1,
     0.5,  0.5, -0.5,  1, 1, 1,
    -0.5,  0.5, -0.5,  0, 0, 0,
]);

const indices = new Uint16Array([
    // Front face
    0, 1, 2, 0, 2, 3,
    // Back face
    4, 5, 6, 4, 6, 7,
    // Left face
    0, 3, 7, 0, 7, 4,
    // Right face
    1, 2, 6, 1, 6, 5,
    // Top face
    3, 2, 6, 3, 6, 7,
    // Bottom face
    0, 1, 5, 0, 5, 4,
]);

// Buffers
const vertexBuffer = gl.createBuffer();
const indexBuffer = gl.createBuffer();

gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer);
gl.bufferData(gl.ARRAY_BUFFER, vertices, gl.STATIC_DRAW);

gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, indexBuffer);
gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, indices, gl.STATIC_DRAW);

// Attribute Pointers
const positionLoc = gl.getAttribLocation(program, 'position');
const colorLoc = gl.getAttribLocation(program, 'color');

gl.vertexAttribPointer(positionLoc, 3, gl.FLOAT, false, 6 * Float32Array.BYTES_PER_ELEMENT, 0);
gl.enableVertexAttribArray(positionLoc);

gl.vertexAttribPointer(colorLoc, 3, gl.FLOAT, false, 6 * Float32Array.BYTES_PER_ELEMENT, 3 * Float32Array.BYTES_PER_ELEMENT);
gl.enableVertexAttribArray(colorLoc);

// Matrices
const modelViewMatrix = mat4.create();
const projectionMatrix = mat4.create();

mat4.perspective(projectionMatrix, Math.PI / 4, canvas.width / canvas.height, 0.1, 10);
mat4.translate(modelViewMatrix, modelViewMatrix, [0, 0, -2]);

const modelViewMatrixLoc = gl.getUniformLocation(program, 'modelViewMatrix');
const projectionMatrixLoc = gl.getUniformLocation(program, 'projectionMatrix');

// Rendering Loop
function render() {
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
    gl.useProgram(program);

    mat4.rotateY(modelViewMatrix, modelViewMatrix, 0.01);

    gl.uniformMatrix4fv(modelViewMatrixLoc, false, modelViewMatrix);
    gl.uniformMatrix4fv(projectionMatrixLoc, false, projectionMatrix);

    gl.drawElements(gl.TRIANGLES, indices.length, gl.UNSIGNED_SHORT, 0);

    requestAnimationFrame(render);
}

// Initialize WebGL
gl.clearColor(0.9, 0.9, 0.9, 1.0);
gl.enable(gl.DEPTH_TEST);

render();
