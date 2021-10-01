# Changelog

## v1.8.1

- Fix: Back walls rendering in high-resolution mode.
- Fix: Center in-game menu in high-resolution mode.
- Fix: Possible crash after running for some time.

## v1.8.0

### New

- High-resolution support (up to 4K)! You'll need to run `opennox-hd.exe` for it.
- A lot faster OpenGL-based rendering (partially offloaded to GPU).
- Add `cheat charm.all` to charm any creature (including humanoids).
- Automated end-to-end testing mode, see [opennox-e2e](https://github.com/noxworld-dev/opennox-e2e) for details.
- Simple HTTP-based [Server API](./docs/server-api.md) for controlling game servers.
- Allow disabling image smoothing in the video options.
- Allow enabling image stretching in the video options.
- Other minor optimizations.

### Fixes

- Bug with creatures being "deaf" (not reacting to footsteps, etc).
- Properly show the last character in long server names.
- Error when manually saving player in online games.
- Banish of captured creatures (like vampire bats) leading to scripts being stuck.
- Properly forward ports when server port is changed via a flag.
- Disabling soft shadows via `-soft` flag.
- LUA scripts when reloading the same map from the console.
- Nox Reloaded failing to join OpenNox Quest games.
- OpenNox changing `user.rul` file permissions.
- Potential crash on hosting Quest games.
- Potential crash when leaving the game.
- Crash when opening advanced server setting without admin rights.

## v1.7.1

- Fix: Hide OS mouse cursor in windowed mode as well.
- Fix: Rename "Back" button in input config menu to "Accept".
- Fix: Prevent crash on audio errors.
- Fix: Avoid collision of new health and mana cheats with old ones.

## v1.7.0

- Completely reworked input and present pipelines.
- Manual spell casting is now supported. Bind keys to individual spell gestures and become a real wizard/conjurer!
- Gamma and mouse sensitivity sliders were added to the options menu.
- Wide-screen 16:9 resolutions are now available. Older 4:3 resolutions are still supported via config.
- Fix: Input sensitivity should now work correctly in fullscreen mode.
- Fix: Gamma setting in the config is now respected.
- Fix: Stretched video setting in the config is now respected.
- Added key bindings for:
  - Switching to a specific spell slot.
  - Switching to a specific trap slot.
  - Dropping a trap from your inventory.
  - Controlling spawned creature behavior.
  - Accepting item buy/sell/drop.
- Breaking change: `set allow.all` was renamed to `cheat equip.all`
- Breaking change: `set mana` was renamed to `cheat mana`
- Breaking change: `set health` was renamed to `cheat health`

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
