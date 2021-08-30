# Server HTTP API

## Server info

```
GET /api/v0/game/info
```

Or in terms of `curl`:

```
curl 'http://127.0.0.1:18580/api/v0/game/info'
```

Example response:

```json
{
  "name":"OpenNox",
  "map":"estate",
  "mode":"arena",
  "vers":"v1.8.0",
  "players":{
    "cur":1,
    "max":32,
    "list":[
      {
        "name":"Jack",
        "class":"wizard"
      }
    ]
  }
}
```

## Setting the token

You need to run the server with `NOX_API_TOKEN=<some-random-string>` to allow using control APIs.

All examples below assume `NOX_API_TOKEN=xyz`.

## Change map

```
POST /api/v0/game/map
X-Token: xyz

estate
```

Or in terms of `curl`:

```
curl -X POST -H 'X-Token: xyz' -d 'estate' 'http://127.0.0.1:18580/api/v0/game/map'
```

## Run console command

```
POST /api/v0/game/cmd
X-Token: xyz

load estate
```

Or in terms of `curl`:

```
curl -X POST -H 'X-Token: xyz' -d 'load estate' 'http://127.0.0.1:18580/api/v0/game/cmd'
```

## Run LUA script

```
POST /api/v0/game/lua
X-Token: xyz

p = Nox.Players[1];
apple = Nox.ObjectType("RedApple");
apple:Create(p);
```

Or in terms of `curl`:

```
curl -X POST -H 'X-Token: xyz' -d 'p = Nox.Players[1]; apple = Nox.ObjectType("RedApple"); apple:Create(p)' 'http://127.0.0.1:18580/api/v0/game/lua'
```
