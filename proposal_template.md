# CP411 Project: 3D Object Rendering Application with Enhanced Controls

Author(s): Jashandeep Singh

Date: 2024-11-19


## Introduction

This project invloves on the development of a 3D Object Rendering Application using OpenGL. The primary objective is to build a robust interactive system for rendering and manipulating 3D objects with real-time controls. The application will support multiple object types and provide dynamic user interactions such as rotation, zoom, translation, and custom model uploads

Key features of the project include:

- Support for custom 3D models in binary STL format.
- Real-time rendering of 3D objects
- Enhanced user controls via keyboard and mouse inputs.
- Screenshot functionality to capture the current frame.
- Depth-First Search (DFS).

  
 
## Problem solving and algorithms

The project aims to acts as a learning resource for understanding transformations and rendering techniques in OpenGL.


## Design consideration 


  
The system would be implemented using the Model-View-Controller (MVC) architecture to ensure modularity and scalability.

- Model: 
	- Maintains data structures for objects (vertices, faces) and transformations.
	- Supports binary STL file loading and parsing.
	- Implements global state variables (rotation, translation, zoom).
- View:
	- Handles graphical rendering using OpenGL.
	- Renders objects with dynamic lighting and perspective adjustments.

- Controller:
	- Acts as an intermediary between the Model and View..
	- Processes user inputs (keyboard, mouse).
	- Updates the state of the Model and triggers redisplay in the View.





## References

- STB Image Write Library
Sean Barrett. stb_image_write.h: Single-File Public Domain Library for Writing Images.
https://github.com/nothings/stb

- 3D File Formats: STL
ISO/ASTM. Additive Manufacturing File Format (AMF) Specification. ISO/ASTM 52915:2016.
https://en.wikipedia.org/wiki/STL_(file_format)

- Interactive graphics with OpenGL: Tutorials and resources for GLUT and OpenGL integration.
- FreeGLUT Documentation
FreeGLUT Development Team. The FreeGLUT API Documentation.
https://freeglut.sourceforge.net/docs/

