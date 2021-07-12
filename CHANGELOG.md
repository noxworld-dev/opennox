# Changelog

## v1.7.0

- Completely reworked input and present pipelines.
- Manual spell casting is now supported. Bind keys to individual spell gestures and become a real wizard/conjurer!
- Input sensitivity should now be fixed in fullscreen mode.
- Wide-screen 16:9 resolutions are now available. Older 4:3 resolutions are still supported via config.
- Added key bindings for:
  - Switching to a specific spell slot.
  - Switching to a specific trap slot.
  - Dropping a trap from your inventory.
  - Controlling spawned creature behavior.

## v1.6.1

- Fix: Prevent freeze when closing the game on Windows. 
- Fix: Prevent crash in `set mana`.
- Fix: Prevent crash when switching shield and bow with `set allow.all` enabled.
- Fix: Ignore item strength requirement when using `allow.all`.
- Fix: Remove restrictions from `cheat gold`, so it's accepted in Quest games.

## v1.6.0

- Rename project to OpenNox to avoid confusion.
- Automatically set Nox data folder. Supports Origin, GoG and Nox Reloaded.
- Keep 4:3 aspect ratio when resizing game window.
- Toggle fullscreen mode with Alt+Enter.
- Add `set health` and `set mana` cheats.
- Add `set allow.all` cheat to remove item class restrictions.
- Allow customizing `gamedata.bin` values without encoding it. See [gamedata.yml](./docs/gamedata-sample.yml).
- LUA now supports trigger events as well as player join/leave events.
- Fix: Detonate traps spell will no longer freeze the game.
- Fix: Fullscreen mode will now be saved correctly.
- Fix: Warriors should now be able to scroll weapons with mouse wheel in multiplayer as well.

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
