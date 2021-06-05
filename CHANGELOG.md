# Changelog

## v1.5.0

- Automatically open/forward ports when hosting a game (no need to configure firewall).
- Fixed the bug that prevented warriors from scrolling weapons with mouse wheel.
- Blazing-fast map downloads. Both client and the server should use this version.
- Experimental support for [LUA map scripts](./docs/maps-lua.md).
- Maps will now be transferred with other related files when possible (`.txt`, `.rul`, `.lua`, `.png`).

## v1.4.0

- First public release!
- Compatible with Nox Reloaded.
- Native SDL and OpenAL support (no workarounds required for Win10, streaming, etc).
- Builtin XWIS integration. No need for account in order to host or join games.
- More [Nox Quest](./docs/game-quest.md) options (skip levels, keep portal forever, etc).
- Native Linux build (no Wine).
- Experimental gamepad support.
- Dedicated "headless" server.
