# Replacing in-game sprites

The main build supports a way to replace sprites used by the game.

For it to work, you may first need to get original sprites:

```
cd Nox
noxtools videobag extract -z --out ./video.bag.zip
```

Find sprites that you want to replace and put them into `Nox/images` (create if not exists).
Make the changes to the sprite in this directory and run the game to test it.

Note that it will ONLY work with this Nox version. Original Nox, GoG version or Nox Reloaded doesn't support this.

## Adjusting sprite offsets

If you decide to change the sprite significantly, e.g. changing its size or completely redrawing the image,
you may need to change the sprite offset used by the engine.

First, get the original sprite metadata:

```
cd Nox
noxtools videobag extract -z --out ./video.bag.zip --json
```

Now this archive will contain `.json` files that correspond to each sprite. Copy selected ones to `Nox/images`,
adjust the offsets using the text editor and check them in game.
