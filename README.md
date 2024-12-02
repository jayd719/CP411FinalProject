
  <h1><strong>3D Model Viewer and Renderer</strong></h1>
  <p>
    An intuitive and lightweight 3D model viewer and renderer built with
    <strong>OpenGL</strong> and <strong>Assimp</strong>, designed for anyone who
    needs to visualize and interact with 3D models. This project supports
    multiple popular file formats, provides real-time rendering, and offers
    simple yet powerful controls for exploring 3D objects.
  </p>
  <hr />
  <h2><strong>Features</strong></h2>
  <ul>
    <li>
      <strong>Multi-Format Support</strong>:
      <ul>
        <li>
          Load 3D files in formats like <strong>STL</strong>,
          <strong>OBJ</strong>, <strong>FBX</strong>, and <strong>GLTF</strong>.
        </li>
      </ul>
    </li>
    <li>
      <strong>Real-Time Rendering</strong>:
      <ul>
        <li>
          Smooth and fast rendering of 3D models with interactive controls.
        </li>
      </ul>
    </li>
    <li>
      <strong>Interactive User Controls</strong>:
      <ul>
        <li>Rotate, zoom, and move the model using your mouse and keyboard.</li>
        <li>Reset or load new files easily.</li>
      </ul>
    </li>
    <li>
      <strong>Cross-Platform</strong>:
      <ul>
        <li>
          Runs seamlessly on <strong>Windows</strong>, <strong>macOS</strong>,
          and <strong>Linux</strong>.
        </li>
      </ul>
    </li>
    <li>
      <strong>Lightweight and Free</strong>:
      <ul>
        <li>
          No unnecessary bloat—just the essentials for visualizing 3D models.
        </li>
      </ul>
    </li>
  </ul>
  <hr />
  <h2><strong>Installation</strong></h2>
  <h3><strong>Prerequisites</strong></h3>
  <ul>
    <li>
      <strong>OpenGL</strong> and <strong>FreeGLUT</strong> for rendering.
    </li>
    <li><strong>Assimp</strong> for 3D file format support.</li>
  </ul>
  <h4><strong>Linux</strong></h4>
  <pre
    class="!overflow-visible"
  ><div class="contain-inline-size rounded-md border-[0.5px] border-token-border-medium relative bg-token-sidebar-surface-primary dark:bg-gray-950"><div class="flex items-center text-token-text-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md h-9 bg-token-sidebar-surface-primary dark:bg-token-main-surface-secondary select-none">bash</div><div class="sticky top-9 md:top-[5.75rem]"><div class="absolute bottom-0 right-2 flex h-9 items-center"><div class="flex items-center rounded bg-token-sidebar-surface-primary px-2 font-sans text-xs text-token-text-secondary dark:bg-token-main-surface-secondary"><span class="" data-state="closed"><button class="flex gap-1 items-center select-none py-1"><svg width="24" height="24" viewBox="0 0 24 24" fill="none" xmlns="http://www.w3.org/2000/svg" class="icon-sm"><path fill-rule="evenodd" clip-rule="evenodd" d="M7 5C7 3.34315 8.34315 2 10 2H19C20.6569 2 22 3.34315 22 5V14C22 15.6569 20.6569 17 19 17H17V19C17 20.6569 15.6569 22 14 22H5C3.34315 22 2 20.6569 2 19V10C2 8.34315 3.34315 7 5 7H7V5ZM9 7H14C15.6569 7 17 8.34315 17 10V15H19C19.5523 15 20 14.5523 20 14V5C20 4.44772 19.5523 4 19 4H10C9.44772 4 9 4.44772 9 5V7ZM5 9C4.44772 9 4 9.44772 4 10V19C4 19.5523 4.44772 20 5 20H14C14.5523 20 15 19.5523 15 19V10C15 9.44772 14.5523 9 14 9H5Z" fill="currentColor"></path></svg>Copy code</button></span></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-bash">sudo apt-get install libassimp-dev freeglut3-dev
</code></div></div></pre>
  <h4><strong>macOS</strong></h4>
  <pre
    class="!overflow-visible"
  ><div class="contain-inline-size rounded-md border-[0.5px] border-token-border-medium relative bg-token-sidebar-surface-primary dark:bg-gray-950"><div class="flex items-center text-token-text-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md h-9 bg-token-sidebar-surface-primary dark:bg-token-main-surface-secondary select-none">bash</div><div class="sticky top-9 md:top-[5.75rem]"><div class="absolute bottom-0 right-2 flex h-9 items-center"><div class="flex items-center rounded bg-token-sidebar-surface-primary px-2 font-sans text-xs text-token-text-secondary dark:bg-token-main-surface-secondary"><span class="" data-state="closed"><button class="flex gap-1 items-center select-none py-1"><svg width="24" height="24" viewBox="0 0 24 24" fill="none" xmlns="http://www.w3.org/2000/svg" class="icon-sm"><path fill-rule="evenodd" clip-rule="evenodd" d="M7 5C7 3.34315 8.34315 2 10 2H19C20.6569 2 22 3.34315 22 5V14C22 15.6569 20.6569 17 19 17H17V19C17 20.6569 15.6569 22 14 22H5C3.34315 22 2 20.6569 2 19V10C2 8.34315 3.34315 7 5 7H7V5ZM9 7H14C15.6569 7 17 8.34315 17 10V15H19C19.5523 15 20 14.5523 20 14V5C20 4.44772 19.5523 4 19 4H10C9.44772 4 9 4.44772 9 5V7ZM5 9C4.44772 9 4 9.44772 4 10V19C4 19.5523 4.44772 20 5 20H14C14.5523 20 15 19.5523 15 19V10C15 9.44772 14.5523 9 14 9H5Z" fill="currentColor"></path></svg>Copy code</button></span></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-bash">brew install assimp freeglut
</code></div></div></pre>
  <h4><strong>Windows</strong></h4>
  <ul>
    <li>Download and set up Assimp and FreeGLUT libraries.</li>
    <li>
      Ensure the OpenGL libraries are linked in your development environment.
    </li>
  </ul>
  <hr />
  <h3><strong>Build Instructions</strong></h3>
  <h4>Linux/macOS</h4>
  <pre
    class="!overflow-visible"
  ><div class="contain-inline-size rounded-md border-[0.5px] border-token-border-medium relative bg-token-sidebar-surface-primary dark:bg-gray-950"><div class="flex items-center text-token-text-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md h-9 bg-token-sidebar-surface-primary dark:bg-token-main-surface-secondary select-none">bash</div><div class="sticky top-9 md:top-[5.75rem]"><div class="absolute bottom-0 right-2 flex h-9 items-center"><div class="flex items-center rounded bg-token-sidebar-surface-primary px-2 font-sans text-xs text-token-text-secondary dark:bg-token-main-surface-secondary"><span class="" data-state="closed"><button class="flex gap-1 items-center select-none py-1"><svg width="24" height="24" viewBox="0 0 24 24" fill="none" xmlns="http://www.w3.org/2000/svg" class="icon-sm"><path fill-rule="evenodd" clip-rule="evenodd" d="M7 5C7 3.34315 8.34315 2 10 2H19C20.6569 2 22 3.34315 22 5V14C22 15.6569 20.6569 17 19 17H17V19C17 20.6569 15.6569 22 14 22H5C3.34315 22 2 20.6569 2 19V10C2 8.34315 3.34315 7 5 7H7V5ZM9 7H14C15.6569 7 17 8.34315 17 10V15H19C19.5523 15 20 14.5523 20 14V5C20 4.44772 19.5523 4 19 4H10C9.44772 4 9 4.44772 9 5V7ZM5 9C4.44772 9 4 9.44772 4 10V19C4 19.5523 4.44772 20 5 20H14C14.5523 20 15 19.5523 15 19V10C15 9.44772 14.5523 9 14 9H5Z" fill="currentColor"></path></svg>Copy code</button></span></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-bash">g++ -o 3d_viewer main.cpp -lGL -lGLU -lglut -lassimp
</code></div></div></pre>
  <h4>Windows</h4>
  <pre
    class="!overflow-visible"
  ><div class="contain-inline-size rounded-md border-[0.5px] border-token-border-medium relative bg-token-sidebar-surface-primary dark:bg-gray-950"><div class="flex items-center text-token-text-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md h-9 bg-token-sidebar-surface-primary dark:bg-token-main-surface-secondary select-none">bash</div><div class="sticky top-9 md:top-[5.75rem]"><div class="absolute bottom-0 right-2 flex h-9 items-center"><div class="flex items-center rounded bg-token-sidebar-surface-primary px-2 font-sans text-xs text-token-text-secondary dark:bg-token-main-surface-secondary"><span class="" data-state="closed"><button class="flex gap-1 items-center select-none py-1"><svg width="24" height="24" viewBox="0 0 24 24" fill="none" xmlns="http://www.w3.org/2000/svg" class="icon-sm"><path fill-rule="evenodd" clip-rule="evenodd" d="M7 5C7 3.34315 8.34315 2 10 2H19C20.6569 2 22 3.34315 22 5V14C22 15.6569 20.6569 17 19 17H17V19C17 20.6569 15.6569 22 14 22H5C3.34315 22 2 20.6569 2 19V10C2 8.34315 3.34315 7 5 7H7V5ZM9 7H14C15.6569 7 17 8.34315 17 10V15H19C19.5523 15 20 14.5523 20 14V5C20 4.44772 19.5523 4 19 4H10C9.44772 4 9 4.44772 9 5V7ZM5 9C4.44772 9 4 9.44772 4 10V19C4 19.5523 4.44772 20 5 20H14C14.5523 20 15 19.5523 15 19V10C15 9.44772 14.5523 9 14 9H5Z" fill="currentColor"></path></svg>Copy code</button></span></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-bash">g++ -o 3d_viewer main.cpp -lfreeglut -lopengl32 -lglu32 -lassimp
</code></div></div></pre>
  <hr />
  <h2><strong>Usage</strong></h2>
  <h3><strong>Run the Application</strong></h3>
  <pre
    class="!overflow-visible"
  ><div class="contain-inline-size rounded-md border-[0.5px] border-token-border-medium relative bg-token-sidebar-surface-primary dark:bg-gray-950"><div class="flex items-center text-token-text-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md h-9 bg-token-sidebar-surface-primary dark:bg-token-main-surface-secondary select-none">bash</div><div class="sticky top-9 md:top-[5.75rem]"><div class="absolute bottom-0 right-2 flex h-9 items-center"><div class="flex items-center rounded bg-token-sidebar-surface-primary px-2 font-sans text-xs text-token-text-secondary dark:bg-token-main-surface-secondary"><span class="" data-state="closed"><button class="flex gap-1 items-center select-none py-1"><svg width="24" height="24" viewBox="0 0 24 24" fill="none" xmlns="http://www.w3.org/2000/svg" class="icon-sm"><path fill-rule="evenodd" clip-rule="evenodd" d="M7 5C7 3.34315 8.34315 2 10 2H19C20.6569 2 22 3.34315 22 5V14C22 15.6569 20.6569 17 19 17H17V19C17 20.6569 15.6569 22 14 22H5C3.34315 22 2 20.6569 2 19V10C2 8.34315 3.34315 7 5 7H7V5ZM9 7H14C15.6569 7 17 8.34315 17 10V15H19C19.5523 15 20 14.5523 20 14V5C20 4.44772 19.5523 4 19 4H10C9.44772 4 9 4.44772 9 5V7ZM5 9C4.44772 9 4 9.44772 4 10V19C4 19.5523 4.44772 20 5 20H14C14.5523 20 15 19.5523 15 19V10C15 9.44772 14.5523 9 14 9H5Z" fill="currentColor"></path></svg>Copy code</button></span></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-bash">./3d_viewer
</code></div></div></pre>
  <h3><strong>Load a 3D Model</strong></h3>
  <ul>
    <li>
      Press <code>l</code> and provide the file path of the 3D model (e.g.,
      <code>models/cube.obj</code>).
    </li>
  </ul>
  <h3><strong>Controls</strong></h3>
  <ul>
    <li>
      <strong>Keyboard</strong>:
      <ul>
        <li><code>Arrow Keys</code>: Move the model (translate).</li>
        <li><code>+/-</code>: Zoom in/out.</li>
        <li><code>Space</code>: Pause/resume model rotation.</li>
        <li><code>l</code>: Load a new 3D model.</li>
        <li><code>ESC</code>: Exit the application.</li>
      </ul>
    </li>
    <li>
      <strong>Mouse</strong>:
      <ul>
        <li>Drag: Rotate the model.</li>
        <li>Scroll: Zoom in/out.</li>
      </ul>
    </li>
    <li>
      <strong>Right-Click Menu</strong>:
      <ul>
        <li>Reset view, load STL files, or exit.</li>
      </ul>
    </li>
  </ul>
  <hr />
  <h2><strong>File Formats Supported</strong></h2>
  <ul>
    <li>
      <strong>STL</strong>: Widely used in 3D printing and CAD applications.
    </li>
    <li>
      <strong>OBJ</strong>: Common for 3D modeling and design, supports
      materials.
    </li>
    <li>
      <strong>FBX</strong>: Advanced format for animations and detailed models.
    </li>
    <li>
      <strong>GLTF</strong>: Modern, lightweight format optimized for
      performance.
    </li>
  </ul>
  <hr />
  <h2><strong>Examples</strong></h2>
  <p>Test the application with included sample models:</p>
  <ul>
    <li><code>models/cube.obj</code></li>
    <li><code>models/sphere.stl</code></li>
  </ul>
  <hr />
  <h2><strong>Future Enhancements</strong></h2>
  <ul>
    <li>Add support for texturing and material rendering.</li>
    <li>Implement animations for dynamic models.</li>
    <li>Integrate a GUI-based file picker for easier file loading.</li>
    <li>
      Enhance the rendering pipeline with physically-based rendering (PBR).
    </li>
  </ul>
  <hr />
  <h2><strong>Contributing</strong></h2>
  <p>Contributions are welcome! Here's how you can help:</p>
  <ol>
    <li>Fork the repository.</li>
    <li>Create a new branch: <code>git checkout -b feature-name</code>.</li>
    <li>Commit your changes: <code>git commit -m 'Add feature-name'</code>.</li>
    <li>Push to the branch: <code>git push origin feature-name</code>.</li>
    <li>Open a pull request.</li>
  </ol>
  <hr />
  <h2><strong>License</strong></h2>
  <p>
    This project is licensed under the MIT License. See the
    <a
      rel="noopener"
      style="
        --streaming-animation-state: var(--batch-play-state-1);
        --animation-rate: var(--batch-play-rate-1);
      "
      ><span
        style="
          --animation-count: 34;
          --streaming-animation-state: var(--batch-play-state-2);
        "
        >LICENSE</span
      ></a
    >
    file for details.
  </p>
  <hr />
  <h2><strong>Acknowledgments</strong></h2>
  <ul>
    <li><strong>OpenGL</strong>: For providing robust tools for rendering.</li>
    <li><strong>Assimp</strong>: For handling multi-format 3D file support.</li>
    <li><strong>FreeGLUT</strong>: For window and user input management.</li>
    <li>
      Sample models sourced from
      <a
        rel="noopener"
        target="_new"
        style="
          --streaming-animation-state: var(--batch-play-state-1);
          --animation-rate: var(--batch-play-rate-1);
        "
        href="https://www.thingiverse.com/"
        ><span
          style="
            --animation-count: 36;
            --streaming-animation-state: var(--batch-play-state-2);
          "
          >Thingiverse</span
        ></a
      >
      and
      <a
        rel="noopener"
        target="_new"
        style="
          --streaming-animation-state: var(--batch-play-state-1);
          --animation-rate: var(--batch-play-rate-1);
        "
        href="https://free3d.com/"
        ><span
          style="
            --animation-count: 38;
            --streaming-animation-state: var(--batch-play-state-2);
          "
          >Free3D</span
        ></a
      >.
    </li>
  </ul>
  <hr />
  <h2><strong>Contact</strong></h2>
  <p>For questions, suggestions, or feedback, feel free to reach out:</p>
  <ul>
    <li>
      <strong>Email</strong>:
      <a
        rel="noopener"
        style="
          --streaming-animation-state: var(--batch-play-state-1);
          --animation-rate: var(--batch-play-rate-1);
        "
        ><span
          style="
            --animation-count: 39;
            --streaming-animation-state: var(--batch-play-state-2);
          "
          >your</span
        ><span
          style="
            --animation-count: 40;
            --streaming-animation-state: var(--batch-play-state-2);
          "
          >-email</span
        ><span
          style="
            --animation-count: 41;
            --streaming-animation-state: var(--batch-play-state-2);
          "
          >@example.com</span
        ></a
      >
    </li>
    <li>
      <strong>GitHub</strong>:
      <a
        rel="noopener"
        target="_new"
        style="
          --streaming-animation-state: var(--batch-play-state-1);
          --animation-rate: var(--batch-play-rate-1);
        "
        href="https://github.com/your-profile"
        ><span
          style="
            --animation-count: 41;
            --streaming-animation-state: var(--batch-play-state-2);
          "
          >Your</span
        ><span
          style="
            --animation-count: 42;
            --streaming-animation-state: var(--batch-play-state-2);
          "
        >
          GitHub</span
        ><span
          style="
            --animation-count: 43;
            --streaming-animation-state: var(--batch-play-state-2);
          "
        >
          Profile</span
        ></a
      >
    </li>
  </ul>
  <hr />
  
