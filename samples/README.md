## Samples

ATTYR includes two sample programs that demonstrate how to use ATTYR. The first program is completely contained in `samples/tri.c` and renders a single triangle spinning in space. This isn't very interesting, but it's helpful for testing.

![Spinning triangle](https://github.com/thcopeland/attyr/blob/master/samples/assets/tri.gif)

The second program is far more complicated, mostly because it loads the models and textures from the file system. The `samples/utils/` folder contains functionality to import `.obj` models and raw textures. Most of the actual rendering is done in `samples/scene.c`. This sample demonstrates large models, textures, simple animations, and diffuse lighting.

![A wizard watches the sunset](https://github.com/thcopeland/attyr/blob/master/samples/assets/scene.gif)

Before running the samples, be sure to install ATTYR. Then, to compile the samples, run

```
$ make
```

Then you can run each program individually:

```
$ ./tri
...
$ ./scene
...
```

## Assets

[ImageMagick](https://github.com/ImageMagick/ImageMagick) was used to convert the encoded image files to `.raw` files:

```
$ convert Plant_Texture.png rgb:Plant_Texture.raw
```
The resulting `.raw` image files have no dimension information, however, so you have to check the original file.

The wizard, tree, and plant models, as well as their associated textures, are by [Quaternius](https://www.patreon.com/quaternius) and licensed under CC0. The Immenstadter Horn HDR is from [HDRI Haven](https://hdrihaven.com), and is also licensed under CC0.
