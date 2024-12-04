<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" href="https://jayd719.github.io/staticfiles/j.png" type="image/x-icon">
    <title>Documentation - Render 3D Objects</title>
    <style>
        *{
            margin: 0;
        }

        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            padding-left: 10%;
            padding-right: 10%;
            padding-bottom: 20%;
            margin: 0;
            background-color: #f9f9f9;
        }

        h1 {
            font-size: 50px;
            font-weight: bolder;
            color: #2c3e50;
        }
        h2{
            font-size: 30px;
            font-weight: bolder;
            color: #2c3e50;
        }
        h3 {
            font-size: x-large;
            margin-top: 50px;
            font-weight: bolder;
        }
        p{
            margin-left: 40px;   
        }

        h4 {
            font-size: large;
            margin-left: 40px;
            margin-top: 12.5px;
        }

        ul, ol {
            padding-top: 2.5px;
            padding-left: 100px;
        }

        pre {
            margin-left: 50px;
            background-color: #e3dfdfcb;
            padding: 10px;
            border-radius: 5px;
            overflow-x: auto;
        }

        table {
            width: 75%;
            margin-left: 50px;
            margin-top: 10px;
            margin-bottom: 25px;
            border-collapse: collapse;

        }

        th, table td {
            padding: 10px;
            text-align: left;
            border: 1px solid #ddd;
        }

        th {
            background-color: #e3dfdfcb;
        }

        code {
            font-weight: bolder;
            color: rgb(255, 0, 102);
            padding: 2px 4px;
            border-radius: 3px;
        }

        figure {
            padding-top: 25px;
            padding-bottom: 50px;
            padding-left: 20%;
            padding-right: 20%;
            text-align: center;
        }

        figcaption {
            font-style: italic;
            font-size: 0.9em;
        }

        a {
            color: #008eed;
            text-decoration: none;
        }

        a:hover {
            text-decoration: underline;
        }

        strong {
            color: #09141f;
        }

    </style>
</head>

<body>

    <h2 style="transform: translateY(15px);">Documentation</h2>
    <h1>Render 3D Objects</h1>
    <span style="font-weight: bold; color: #fc0000;">CP411 Computer Graphics: Final Project</span>
    <hr>
    <br>
    <div id="index" style="margin-bottom: 50px;"></div>
    <hr>

    <h3>1. Introduction</h3>
    <p>
        This project is a real-time 3D object rendering application built using OpenGL. It provides users with the
        ability to visualize and interact with 3D shapes, such as cubes, pyramids, spheres, and custom STL models.
        The application offers intuitive controls for rotation, zoom, and translation, accompanied by dynamic lighting
        effects. Additionally, users can capture the current rendering view and save it as a high-quality PNG file.
    </p>

    <h3>2. Installation</h3>
    <h4>Prerequisites</h4>
    <ul>
        <li>A C++ compiler compatible with OpenGL and GLUT (e.g., GCC or MinGW)</li>
        <li>Windows operating system</li>
        <li>A command-line interface (CLI) such as Command Prompt or a terminal</li>
    </ul>

    <h4>Installation Steps</h4>
    <ol>
        <li>
            <strong>Download the Source Files:</strong> Obtain the project files in a zip archive from the provided
            <a href="#">link</a>.
        </li>
        <li><strong>Navigate to the Source Directory:</strong> Open a terminal and navigate to the <code>src</code> folder.</li>
        <li><strong>Build the Application:</strong> Execute the following command to compile the project:
            <pre><code>g++ Main.cpp -o render3D -lfreeglut -lComdlg32 -lopengl32 -lglu32</code></pre>
        </li>
        <li><strong>Run the Application:</strong> Execute the compiled binary with:
            <pre><code>./render3D</code></pre>
        </li>
    </ol>

    <h4>Sample Output</h4>
    <p>The application launches with a rotating cube rendered by default. Below is a sample rendering of a custom STL object:</p>
    <figure>
        <video width="80%"  autoplay>
            <source src="images/ss2.mp4" type="video/mp4">
          </video>
        <figcaption>Initial Startup Screen <code>video</code></figcaption>
    </figure>

    <h3>3. Project Structure</h3>
    <pre>
CP411-FinalProject/
├── Assets      #SAMPLE STL FILES FOR TESTING
├── Binaries/
├── Includes/
├── src/
│   ├── Controller/
│   │   ├── controller.cpp
│   │   ├── controller.hpp
│   │   ├── menu.cpp
│   │   ├── menu.hpp
│   ├── include/
│   │   ├── assimp/
│   │   ├── stb_image_write.h
│   ├── config.hpp
│   ├── Main.cpp
│   ├── model_loader.cpp
│   ├── model_loader.hpp
│   ├── model.cpp
│   ├── model.hpp
│   ├── utilities.cpp
│   ├── utilities.hpp
│   ├── view.cpp
│   ├── view.hpp
├── Debug/
├── Release/
├── docs/
    </pre>

    <h3>4. Features</h3>
    <ul>
        <li><strong>Predefined 3D Objects:</strong> Visualize and interact with predefined shapes, including cubes,
            pyramids, and spheres.</li>
        <li><strong>Custom Model Support:</strong> Load and render user-provided binary STL files.</li>
        <li><strong>Dynamic Viewpoints:</strong> Switch between predefined views like Isometric, Reverse Isometric, Top,
            Bottom, and Front Views.</li>
        <li><strong>Real-Time Interactions:</strong> Utilize keyboard and mouse inputs to rotate, zoom, and translate
            objects dynamically.</li>
        <li><strong>Right-Click Menu:</strong> Access essential functions such as resetting views, saving screenshots,
            and switching between shapes.</li>
        <li><strong>PNG Export:</strong> Capture and save the current scene as a high-resolution PNG image with a
            timestamp.</li>
        <li><strong>Responsive Design:</strong> The application adjusts seamlessly to window resizing.</li>
        <li><strong>Extensibility:</strong> Modular architecture allows easy integration of additional features and
            shapes.</li>
    </ul>

    <h3>5. Usage Guide</h3>
    <h4>Launching the Application</h4>
    <ol>
        <li>Execute the compiled binary to launch the application.</li>
        <li>A default rotating cube will be displayed.</li>
    </ol>

    <h4>Switching Shapes</h4>
    <ol>
        <li>Right-click to open the context menu.</li>
        <li>Choose one of the available shapes: Cube, Pyramid, Sphere, or Load Custom Model.</li>
    </ol>

    <h4>Loading Custom Models</h4>
    <ol>
        <li>Select the "Load Custom Model" option from the menu.</li>
        <li>Use the file dialog to select a binary STL file.</li>
        <li>The chosen model will be rendered in the viewport.</li>
    </ol>

    <h4>Saving as PNG</h4>
    <ol>
        <li>Select the "Save As PNG" option from the menu.</li>
        <li>The current frame will be saved in the working directory with a timestamped filename.</li>
    </ol>


    <h3>6. Controls</h3>
        <p>The 3D Object Rendering Application provides enhanced controls for interacting with and viewing 3D objects.
        </p>
        <h4>Keyboard Controls</h4>
        <table>
            <thead>
                <tr>
                    <th>Key</th>
                    <th>Action</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td><code>+</code></td>
                    <td>Increase rotation speed</td>
                </tr>
                <tr>
                    <td><code>-</code></td>
                    <td>Decrease rotation speed</td>
                </tr>
                <tr>
                    <td>Space</td>
                    <td>Pause/Resume rotation</td>
                </tr>
                <tr>
                    <td><code>w</code></td>
                    <td>Rotate the object upward</td>
                </tr>
                <tr>
                    <td><code>s</code></td>
                    <td>Rotate the object downward</td>
                </tr>
                <tr>
                    <td><code>a</code></td>
                    <td>Rotate the object to the left</td>
                </tr>
                <tr>
                    <td><code>d</code></td>
                    <td>Rotate the object to the right</td>
                </tr>
                <tr>
                    <td><code>q</code></td>
                    <td>Rotate the object counterclockwise along Z-axis</td>
                </tr>
                <tr>
                    <td><code>e</code></td>
                    <td>Rotate the object clockwise along Z-axis</td>
                </tr>
                <tr>
                    <td><code>i</code></td>
                    <td>Set <strong>Isometric view</strong> (35.26° X-axis, 45° Y-axis)</td>
                </tr>
                <tr>
                    <td><code>r</code></td>
                    <td>Set <strong>Reverse isometric view</strong> (-35.26° X-axis, -45° Y-axis)</td>
                </tr>
                <tr>
                    <td><code>t</code></td>
                    <td>Set <strong>Top view</strong> (-90° X-axis)</td>
                </tr>
                <tr>
                    <td><code>b</code></td>
                    <td>Set <strong>Bottom view</strong> (90° X-axis)</td>
                </tr>
                <tr>
                    <td><code>f</code></td>
                    <td>Set <strong>Front view</strong> (0° X, Y, Z axes)</td>
                </tr>
                <tr>
                    <td><code>p</code></td>
                    <td>Save the current frame as a PNG file</td>
                </tr>
            </tbody>
        </table>

        <h4>Mouse Controls</h4>
        <table>
            <thead>
                <tr>
                    <th>Action</th>
                    <th>Description</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td><strong>Horizontal Movement</strong></td>
                    <td>Rotate the object left or right based on mouse X-axis movement.</td>
                </tr>
                <tr>
                    <td><strong>Vertical Movement</strong></td>
                    <td>Rotate the object up or down based on mouse Y-axis movement.</td>
                </tr>
                <tr>
                    <td><strong>Scroll Up/Down</strong></td>
                    <td>Zoom in/out.</td>
                </tr>
                <tr>
                    <td><strong>Right-click</strong></td>
                    <td>Open the context menu.</td>
                </tr>
            </tbody>
        </table>

        <h4>Mouse Options</h4>
        <p>The <strong>right-click menu</strong> provides the following functionalities:</p>
        <ul>
            <li><strong>Reset</strong>: Reset all transformations to their default values.</li>
            <li><strong>Pause/Resume</strong>: Toggle rotation.</li>
            <li><strong>Speed</strong>: Adjust the rotation speed dynamically.</li>
            <li><strong>Zoom</strong>: Increase or decrease the zoom level.</li>
            <li><strong>Load Custom Model</strong>: Load and render a binary STL model.</li>
            <li><strong>Save As PNG</strong>: Save the current frame as an image file.</li>
            <li><strong>Exit</strong>: Close the application.</li>
        </ul>


    <h3>7. Implementation Details</h3>
    <p>The implementation of the 3D Object Rendering Application focuses on modularity, maintainability, and efficiency, leveraging OpenGL for real-time rendering and modern C++ for backend logic</p>
    <h4>Modular Architecture</h4>
    <p>The application follows the Model-View-Controller (MVC) design pattern for modularity:</p>
    <ol>
        <li>
            Model:
            <ul>
                <li>Manages data structures for object vertices, transformations, and global states.</li>
                <li>Handles STL file loading</li>
            </ul>

        </li>


        <li>
            View:
            <ul>
                <li>Responsible for rendering objects and managing visual elements like lighting</li>
                <li>Handles perspective adjustments and redisplay logic</li>
            </ul>
        </li>

        <li>
            Controller:
            <ul>
                <li>Processes user inputs (keyboard, mouse) and updates the model accordingly</li>
                <li>Communicates state changes to the view for rendering updates</li>
            </ul>
        </li>
    </ol>

    <h4>Core Compenents</h4>
    <ol>
        <li>
            OpenGL Initialization
            <ul>
                <li>The OpenGL environment is initialized using <code>initializeOpenGL()</code></li>
                <li>Sets up the viewport and perspective projection matrix for rendering</li>
                <li>Sets up default background color and depth testing for realistic rendering</li>
            </ul>
        </li>

        <li>Lighting Configuration
            <ul>
                <li>Lighting is initialized using <code>initializeLighting()</code></li>
                <li>It sets up Ambient lighting to illuminate all objects uniformly.</li>
                <li>Also sets up Material properties through <code>glColorMaterial()</code> for rendering faces with dynamic colors.</li>
            </ul>
        </li>


        <li>
            Rendering Pipeline
            <ul>
                <li>The <code>onDisplay()</code> function handles the rendering pipeline</li>
                <li>It clears the screen with glClear for each frame.</li>
                <li>Applies transformations (translation, rotation, scaling).</li>
                <li>Renders objects based on the currently selected shape (currentShape) using helper functions:
                    <ul>
                        <li><code>drawCube()</code> </li>
                        <li><code>drawPyramid()</code> </li>
                        <li><code>drawSphere()</code> </li>
                        <li><code>drawSTL()</code> </li>
                    </ul>
                </li>
            </ul>
        </li>


        <li>User Interaction
            <ul>
                <li><strong>Keyboard Input:</strong> <code>handleKeyboard()</code> captures keystrokes for rotation, zoom, and special views (e.g., Isometric, Top).</li>
                <li><strong>Mouse Motion:</strong> <code>handleMouseMotion()</code> allows smooth real-time rotation by mapping mouse movement to rotational axes.</li>
                <li><strong>Right-Click Menu:</strong> The context menu provides options for resetting, saving, and loading models.</li>
            </ul>
        </li>


        <li>File Handling
            <ul>
                <li><strong>Custom Model Loading:</strong>Binary STL files are parsed using <code>loadSTL()</code>, which extracts vertex and normal data for rendering.</li>
                <li><strong>Saving As PNG:</strong>Framebuffer data is captured using <code>glReadPixels</code> and saved as a PNG file using <code>stb_image_write</code></li>
            </ul>
        </li>
        

        <li>
            Dynamic Rendering
            <ul>
                <li><code>glTranslatef()</code>: Moves objects in 3D space.</li>
                <li><code>glRotatef()</code>: Applies rotations around the X, Y, and Z axes.</li>
                <li><code>gluPerspective()</code>: Adjusts the zoom level dynamically.</li>
            </ul>
        </li>


    </ol>


    <h3>8. Dependencies</h3>
    <table>
  <thead>
    <tr>
      <th><strong>Dependency</strong></th>
      <th><strong>Purpose</strong></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>OpenGL</strong></td>
      <td>Core rendering pipeline.</td>
    </tr>
    <tr>
      <td><strong>GLUT</strong></td>
      <td>Window creation, input, and event management.</td>
    </tr>
    <tr>
      <td><strong>GLU</strong></td>
      <td>Utility functions for perspective and transformations.</td>
    </tr>
    <tr>
      <td><strong>STB Image Write</strong></td>
      <td>Saves PNG screenshots from the framebuffer.</td>
    </tr>
    <tr>
      <td><strong>iostream, fstream, cstdlib</strong></td>
      <td>Console I/O, file handling, random number generation.</td>
    </tr>
    <tr>
      <td><strong>cmath, ctime, cstring</strong></td>
      <td>Math operations, timestamps, string manipulation.</td>
    </tr>
    <tr>
      <td><strong>windows.h, commdlg.h</strong></td>
      <td>File dialog support on Windows.</td>
    </tr>
    <tr>
      <td><strong>g++</strong></td>
      <td>Compiles the project.</td>
    </tr>
  </tbody>
</table>


    <h3>9. Screenshots of the Application in Action</h3>

    <div>
        <figure>
            <video width="80%"  autoplay>
                <source src="images/ss1.mp4" type="video/mp4">
              </video>
            <figcaption>Custom Model Loaded in Application, Zoom in/out with mouse wheel  <code>video</code></figcaption>
        </figure>
        <figure>
            <video width="80%"  autoplay>
                <source src="images/ss3.mp4" type="video/mp4">
              </video>
            <figcaption>Switch between standard veiws using keyboard <code>video</code></figcaption>
        </figure>
        <figure>
            <video width="80%"  autoplay>
                <source src="images/ss4.mp4" type="video/mp4">
              </video>
            <figcaption>Use the context menu to switch between shapes or load a custom model  <code>video</code></figcaption>
        </figure>

        <figure>
            <img src="images/img1.png"width="80%" alt="">
            <figcaption>Custom STL model in application</figcaption>
        </figure>

        <figure>
            <img src="images/img2.png" width="80%" alt="">
            <figcaption>Custom STL model in application</figcaption>
        </figure>

        <figure>
            <img src="images/img3.png" width="80%"alt="">
            <figcaption>Context Menu</figcaption>
        </figure>
    </div>




    <h3>10. References</h3>
    <ol>
        <li>CP411 Course Notes</li>
        <li>CP411 Project Details</li>
        <li><a href="https://www.opengl.org/documentation/">OpenGL Programming Guide</a></li>
        <li><a href="https://freeglut.sourceforge.net/docs/">FreeGLUT Documentation</a></li>
        <li><a href="https://github.com/nothings/stb">STB Image Write Library</a></li>
        <li><a href="https://learnopengl.com/">Learn OpenGL</a></li>
    </ol>
<script src="docs/index.js"></script>  
</body>

</html>
