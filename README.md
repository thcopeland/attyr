## About

ATTYR is pronounced "attire" and stands for A TeleTYpe Rasterizer. ATTYR is a single-threaded software rasterizer, written in C, that roughly follows the OpenGL vertex shader + fragment shader architecture and can be used to output to a terminal. Despite the name, ATTYR writes images to a framebuffer, so you can render to anything you want.

## Why?

ATTYR adds a whole new dimension to terminal graphics.

![A wizard watches the sunset](https://github.com/thcopeland/attyr/blob/master/samples/assets/scene.gif)

## Requirements

ATTYR doesn't depend on any other libraries. To build the source (currently, this is the only way to install ATTYR), however, you'll need GNU Autotools. If you're using `apt`, you should be able to install them with

```
sudo apt install automake libtool
```

You'll also probably want a fast terminal emulator that supports [truecolor](https://en.wikipedia.org/wiki/ANSI_escape_code#24-bit) and Unicode. `gnome-terminal` is a good candidate, and is preinstalled on Ubuntu. `xterm` also works.

However, the best terminal emulator for ATTYR is [Alacritty](https://github.com/alacritty/alacritty), "the fastest terminal emulator in existence". ATTYR is fast, and often the biggest bottleneck is actually the terminal. ATTYR runs several times as faster on Alacritty as `gnome-terminal`. At the time of writing, however, the Alacritty Snap package is broken, so you'll have to build Alacritty from source. (When running the ATTYR samples, you may notice that Alacritty renders Unicode LOW HALF BLOCK characters incorrectly, see [here](https://github.com/alacritty/alacritty/issues/2500) for a fix).

## Installation

Clone or download this repository and `cd` into the main directory. Make sure you have GNU Autotools and Libtool installed, then run

```
$ ./autogen.sh
Running libtoolize...done
Running aclocal...done
Running autoconf...done
Running autoheader...donefast
Running automake...done
Autotools setup complete!
```

If this fails, make sure that everything's installed. Otherwise, you can continue with the usual `./configure && make && sudo make install` chain to build and install ATTYR. Create an Issue if you have any problems installing ATTYR.

## Samples

After you install ATTYR, you can run the samples! This is a good way to check your installation. `cd` to `attyr/samples` and run `make` to compile them. See `samples/README.md` for more information.

## Features

* Includes four functions to render a framebuffer with Unicode or ASCII, and 8 or 24 bit color.
* Since this is a software rasterizer, ATTYR makes no restrictions on how or where you store vertex and texture data. No VAOs or VBOs.
* ATTYR uses the OpenGL vertex shader + fragment shader pattern. Instead of GLSL programs, though, you write an ordinary C function.
* Perspective correct interpolation is an essential part of rendering, and ATTYR implements it!
* Perspective and orthographic cameras are both possible.
* Includes a small matrix library.
* Many software rasterizers drop near-plane tris (faces partially in front of and behind the camera) instead of clipping them properly. This is a serious problem if you're writing a game. ATTYR uses the [Olano-Greer rasterization algorithm](https://www.csee.umbc.edu/~olano/papers/2dh-tri/2dh-tri.pdf) and handles near-plane tris correctly.
* ATTYR is fast (particularly on Alacritty). In one test, ATTYR rendered 54,619 faces at 85 FPS at a resolution of 136x70.

## Usage

### Matrices and Vectors

For speed, ATTYR implements fixed-size matrices. All matrix dimensions supported in OpenGL are supported in ATTYR: 2x2, 2x3, 2x4, 3x2, 3x3, 3x4, 4x2, 4x3, 4x4, and vectors, 2x1, 3x1, and 4x1. If you're writing code for low-memory devices, you might want to consider dropping the 2x2, 2x4, 3x2, 4x2, and 4x3 matrices, which are mostly included for completeness. See `src/matrices.h` for available operations.

### Rasterization

ATTYR uses the OpenGL vertex shader + fragment shader architecture. A vertex shader, in ATTYR, is a function of the type `attyr_vertex_shader_f`:

```c
typedef int (*attyr_vertex_shader_f)(attyr_vec4 *vert1,
                                     attyr_vec4 *vert2,
                                     attyr_vec4 *vert3,
                                     void *data);
```

A vertex shader is an iterator. It loads three vertices belonging to a single face, generally from `data`, and copies them to `vert1`, `vert2`, and `vert3`. A vertex shader is the place to apply transformations, including the perspective or orthographic camera transforms. If there are no vertices remaining to render, it returns `0`, otherwise, `1`. (Implementation note: `vert1`, `vert2`, `vert3` are stored in consecutive memory addresses, i.e. `vert1+1 == vert2`.)

A vertex shader provides ATTYR with vertices of a triangle to draw, a fragment shader determines the colors of the triangle.

```c
typedef void (*attyr_fragment_shader_f)(attyr_vec4 *fragment,
                                        attyr_vec3 *coords,
                                        attyr_vec3 *pos,
                                        void *data);
```

The first parameter, `fragment`, is the output color. The `x`, `y`, and `z` fields are the RGB components of the color, from `0` to `1`. The last is the alpha component, though it is not complete: If the alpha value is zero, the color is considered 100% transparent, otherwise, it is 100% opaque. `coords` specifies the perspective-correct [barycentric coordinates](https://www.scratchapixel.com/lessons/3d-basic-rendering/rasterization-practical-implementation/perspective-correct-interpolation-vertex-attributes) of the fragment (a pixel, more or less) being rendered, which is essential for interpolation. `pos` contains the coordinates of the fragment *in camera space* (after transformations). `data` is the same pointer that is passed to the vertex shader.

ATTYR outputs to a framebuffer, declared as the following structure:

```c
typedef struct {
    attyr_color_t *color;
    float *depth;
    unsigned int width;
    unsigned int height;
} attyr_framebuffer_t;
```

`color` is the color buffer, and `depth` is the depth buffer. They should have enough memory to contain `width*height` elements.


Most of the work in ATTYR is done by `attyr_rasterize`:

```c
void attyr_rasterize(attyr_framebuffer_t *buffer,
                     attyr_vertex_shader_f vert_shader,
                     attyr_fragment_shader_f frag_shader,
                     void *shader_data);
```

This accepts a pointer to a framebuffer, a vertex shader, and a fragment shader. The final parameter, `shader_data`, is passed to the vertex and fragment shaders to facilitate data and state sharing.

Finally, once you've successfully rasterized a scene to a framebuffer, you'll want to render it. ATTYR contains several functions that output a framebuffer to `stdout`. Most often, `attyr_render_truecolor` is the best choice.

```c
void attyr_render_truecolor(attyr_framebuffer_t *buffer);
```

See the header files for additional documentation, and the sample files for example usage.
