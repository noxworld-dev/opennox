# Customizing translation

Most of the text used in Nox is stored in the CSF files which are encoded and are hard to modify.

This build provides an easier way to customize those texts.

First, decode the original file:

```
noxtools strings csf2json nox.csf
```

This will produce `nox.csf.json` file that you can modify with a regular text editor.
The build will automatically use this file instead of the original `nox.csf`. 

The `nox.csf.json` file will consist of sections similar to this:

```json
    {
      "id": "ParseCmd.c:exithelp",
      "vals": [
        {
          "str": "Exit the game to Main Menu."
        }
      ]
    }
```

For translation Nox texts to a different language (or changing existing texts),
you need to keep the `id` field, but translate all `str` fields.

For adding custom strings, you need to add a new section with a unique `id` add at least one `str`.
Then you should be able to use this new `id` in your map or mod.
