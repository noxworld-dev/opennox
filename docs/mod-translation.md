# Customizing translation

Most of the text used in Nox is stored in the CSF files which are encoded and are hard to modify.

This build provides an easier way to customize those texts.

First, decode the original file:

```
noxtools strings csf2json nox.csf
```

This will produce `nox.csf.json` file that you can modify with a regular text editor.
The build will automatically use this file instead of the original `nox.csf`. 
