# OpenNox features

## Vanilla features

All vanilla features are supported. You should be able to complete the campaign and play online with OpenNox.
If something doesn't work, please [open an issue](https://github.com/noxworld-dev/opennox/issues/new/choose).

## Compatibility

OpenNox will work out-of-the-box on any recent Windows version. This includes proper graphics and online multiplayer.

OpenNox also works natively on Linux.

OpenNox doesn't provide Nox assets. You must own and install vanilla Nox in order to run it.
OpenNox will attempt to find Nox installation automatically.

OpenNox is able to connect to regular Nox servers, as well as Nox players will be able to connect to OpenNox servers.
This is only true for regular version of OpenNox. OpenNox HD will refuse to connect with non-HD players.

## Graphics

OpenNox can load vanilla Nox content and should work on any recent Windows and Linux versions with no graphical issues.

Additionally, OpenNox provides an OpenNox HD version, that will run in resolution up to 4K. This mode is experimental.
OpenNox HD will refuse connections from non-HD version and from vanilla Nox, because fairness considerations.

OpenNox supports custom TTF and OTF fonts to replace vanilla raster fonts.

## Multiplayer

Vanilla Nox distinguishes between online and LAN multiplayer. It uses XWIS server and requires login/password for it.

OpenNox joins both online and LAN games into a single list. It doesn't require XWIS password, while still able to join XWIS servers.

OpenNox will also attempt to automatically forward ports, when hosting a game online.
This requires UPnP to be enabled on your router (which is enabled by default in most cases).

There's initial work done for supporting [campaign in multiplayer](game-console.md#load).

## Server

OpenNox provides a headless dedicated server for Linux and Windows.

OpenNox servers expose simple [HTTP API](server-api.md) for getting server information,
which allows to easily integrate it with websites, Discord bots, etc.
OpenNox uses this API to provide simple Web control panel for the server.

## Game

OpenNox improves a few aspects of the game to make it more convenient to players, or to provide more options.

Apart from a simpler [online games list](#multiplayer), automatic port-forwarding and more [graphical options](#graphics),
OpenNox additionally provides:

- More controls for [Nox Quest](game-quest.md).
- [Manual spell casting](game-manual-cast.md) similar to Magicka.

## Modding

OpenNox aims to greatly improve modding support. It is still mostly work-in-progress, but there are already a few improvements:

- New [console commands](game-console.md).
- Support for safe [LUA map scripts](maps-lua.md).
- Easier way to change [game balance](mod-balance.md) values.
- Support for [changing or replacing spells](mod-spells.md).
- Initial support for [loading custom sprites](mod-sprites.md).
- Support for [custom translations](mod-translation.md).
