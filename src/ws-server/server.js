const express = require('express')
const fs = require('fs')
const https = require('https')
const WebSocket = require('ws')

const app = express()
const server = https.createServer({
    key: fs.readFileSync('/etc/letsencrypt/live/playnox.xyz/privkey.pem'),
    cert: fs.readFileSync('/etc/letsencrypt/live/playnox.xyz/fullchain.pem')
},app)
const wss = new WebSocket.Server({ server })

app.use(express.static('static'))

let clients = {}
let nextid = 1
wss.on('connection', function (ws) {
    ws.id = nextid++
    ws.isAlive = true
    ws.serverData = null
    clients[ws.id] = ws
    ws.on('close', function () {
        delete clients[ws.id]
    })
    ws.on('message', function (data) {
        data = JSON.parse(data)
        console.log(data)

        switch (data.type) {
            case 'ACCEPT': {
                const peer = clients[data.remote]
                if (!peer) break

                peer.send(JSON.stringify({
                    type: 'ACCEPT',
                    remote: ws.id,
                    answer: data.answer
                }))
                break
            }
            case 'BIND': {
                break
            }
            case 'CONNECT': {
                const peer = clients[data.remote]
                if (!peer) break

                peer.send(JSON.stringify({
                    type: 'CONNECT',
                    remote: ws.id,
                    offer: data.offer
                }))
                break
            }
            case 'ICECANDIDATE': {
                const peer = clients[data.remote]
                if (!peer) break

                peer.send(JSON.stringify({
                    type: 'ICECANDIDATE',
                    remote: ws.id,
                    candidate: data.candidate
                }))
                break
            }
            case 'LIST': {
                ws.send(JSON.stringify({
                    type: 'LIST',
                    seqnum: data.seqnum,
                    port: data.port,
                    servers: buildServerList()
                }))
                break
            }
            case 'REGISTER': {
                ws.serverData = data.data
                ws.serverPort = data.port
                ws.serverKey = data.key || ws.id
                ws.serverLatency = data.latency || 0
                break
            }
        }
    })
    ws.on('pong', function () {
        this.isAlive = true
    })
})
function buildServerList() {
    const servers = {}
    wss.clients.forEach(function (ws) {
        if (ws.serverData) {
            if (!servers[ws.serverKey] || servers[ws.serverKey].latency > ws.serverLatency) {
                servers[ws.serverKey] = {
                    id: ws.id,
                    data: ws.serverData,
                    port: ws.serverPort,
                    latency: ws.serverLatency
                }
            }
        }
    })
    return Object.values(servers)
}

const pinger = setInterval(function () {
    wss.clients.forEach(function (ws) {
        if (ws.isAlive === false)
            return ws.terminate()
        ws.isAlive = false
        ws.ping()
    })
}, 10000)

server.listen(443, function () {
    console.log(`Server started on port ${server.address().port} :)`)
})
