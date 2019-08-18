const dgram = require('dgram')
const net = require('net')
const readline = require('readline')
const { RTCIceCandidate, RTCPeerConnection } = require('wrtc')
const WebSocket = require('ws')

class WOLAPIClient {
    constructor(options) {
        this.options = options
        this.connect()
    }

    connect() {
        this.socket = new net.createConnection(this.options.port, this.options.host, () => {
            this.socket.write('CVERS 11015 9472\r\n')
            this.socket.write('PASS supersecret\r\n')
            this.socket.write('NICK zoaedk\r\n')
            this.socket.write('apgar WaFeapIG 0\r\n')
            this.socket.write('USER UserName HostName irc.westwood.com :RealName\r\n')
            this.socket.write('verchk 32512 720911\r\n')
            this.socket.write('SETOPT 17,33\r\n')

            this.timer = setInterval(() => {
                this.socket.write('LIST 37 37\r\n')
            }, 5000)
        })
        this.socket.setEncoding('latin1')
        this.socket.on('close', () => {
            this.rl.close()
            this.rl = null

            clearInterval(this.timer)
            this.timer = null

            console.log('Lost connection to WOL')
        })
        this.rl = readline.createInterface({
            input: this.socket
        })
        this.rl.on('line', (input) => this.parseLine(input))
    }

    parseLine (input) {
        const tokens = input.split(' ')
        tokens.shift()
        const code = tokens.shift()|0
        // console.log(code)
        tokens.shift()
        switch (code) {
            case 326: {
                const chan = tokens.shift() // channel name
                tokens.shift()
                tokens.shift()
                tokens.shift() // game (37 = Nox)
                tokens.shift()
                tokens.shift()
                const ip = tokens.shift() // ip
                const data = Buffer.from(tokens.join(' '), 'latin1')
                this.parseServerInfo(chan, ip, data)
                break;
            }
        }
    }

    parseServerInfo (chan, ip, data) {
        const ntoa = (ip) => (
            ((ip >> 24) & 0xff) + '.' +
            ((ip >> 16) & 0xff) + '.' +
            ((ip >> 8) & 0xff) + '.' +
            ((ip >> 0) & 0xff)
        )
        // skip 12 bytes and remove bit stuffing
        let decoded = Buffer.alloc(69)
        let x = 0
        let cnt = 0
        for (let i = 12; i < data.length; i++) {
            for (let j = 0; j < 7; j++) {
                x |= ((data[i] >> j) & 1) << (cnt & 7)
                if ((++cnt & 7) == 0) {
                    decoded[cnt / 8 - 1] = x
                    x = 0
                }
            }
        }

        // extract fields
        // console.log(decoded.toString('hex'))
        let player_cnt = decoded.readUInt8(3)
        let player_max = decoded.readUInt8(4)
        let port = decoded.readUInt16LE(9)
        let map = decoded.toString('latin1', 11, Math.min(Math.max(decoded.indexOf(0, 11), 11), 20))
        let name = decoded.toString('latin1', 20, Math.min(Math.max(decoded.indexOf(0, 20), 20), 35))
        let type = decoded.readUInt16LE(63)

        // console.log(player_cnt, player_max, ntoa(ip), port, map, name)

        // convert to local network response
        let info = Buffer.alloc(73 + name.length)
        info.writeUInt8(0, 0)
        info.writeUInt8(0, 1)
        info.writeUInt8(13, 2)
        info.writeUInt8(player_cnt, 3)
        info.writeUInt8(player_max, 4)
        info.writeUInt8(decoded.readUInt8(2), 19) // resolution
        info.writeUInt32LE(type, 28) // game type
        info.writeUInt32LE(decoded.readUInt32LE(35), 48) // allowed spells / weapons / armor
        info.writeUInt32LE(decoded.readUInt32LE(39), 52)
        info.writeUInt32LE(decoded.readUInt32LE(43), 56)
        info.writeUInt32LE(decoded.readUInt32LE(47), 60)
        info.writeUInt32LE(decoded.readUInt32LE(51), 64)
        info.writeUInt32LE(decoded.readUInt32LE(55), 7)
        info.writeUInt32LE(decoded.readUInt32LE(59), 32)

        map += '\0'
        info.write(map, 10, map.length, 'latin1')
        name += '\0'
        info.write(name, 72, name.length, 'latin1')

        this.options.onserver && this.options.onserver(chan, ntoa(ip), port, info)
    }
}

class Network {
    constructor(options) {
        this.options = options
        this.peers = {}
        this.recvQueue = {}
        this.state = null

        const onclose = () => {
            this.ws = null
            setTimeout(connect, 5000)
        }
        const onmessage = ({ data }) => {
            this.onmessage(JSON.parse(data))
        }
        const onopen = () => options.onopen && options.onopen()
        const connect = () => {
            const ws = this.ws = new WebSocket(options.url)
            ws.addEventListener('open', onopen)
            ws.addEventListener('close', onclose)
            ws.addEventListener('message', onmessage)
        }
        connect()
    }

    close () {
        if (this.ws) {
            console.log('ws close.')
            this.ws.removeAllListeners()
            this.ws.close()
            this.ws = null
        }

        for (let id in this.peers) {
            const peer = this.peers[id]
            if (peer.connection) {
                peer.connection.close()
            }
        }
        this.peers = null
    }

    isready () {
        return this.ws !== null && this.ws.readyState == this.ws.OPEN
    }

    onopen () {
    }

    onmessage (data) {
        switch (data.type) {
            case 'ACCEPT': {
                const peer = this.peers[data.remote]
                peer.connection.setRemoteDescription(data.answer)
                break
            }
            case 'CONNECT': {
                const remote = data.remote
                const peerConnection = new RTCPeerConnection(this.options.webrtc)
                const peerChannel = peerConnection.createDataChannel('nox-game', {
                    negotiated: true,
                    id: 0
                })
                peerConnection.addEventListener('icecandidate', ({ candidate }) => {
                    if (candidate) {
                        this.ws.send(JSON.stringify({
                            type: 'ICECANDIDATE',
                            remote,
                            candidate
                        }))
                    }
                })
                peerConnection.addEventListener('connectionstatechange', () => {
                    switch (peerConnection.connectionState) {
                    case 'disconnected':
                    case 'failed':
                    case 'closed':
                        this.options.onclose && this.options.onclose(remote)
                        break
                    }
                })
                peerConnection.setRemoteDescription(data.offer)
                peerConnection.createAnswer().then((answer) => {
                    peerConnection.setLocalDescription(answer)
                    this.accept(remote, answer)
                    peerChannel.addEventListener('message', ({ data }) => this.onpacket(remote, data))
                })
                this.peers[remote] = {
                    id: remote,
                    connection: peerConnection,
                    channel: peerChannel
                }
                break
            }
            case 'ICECANDIDATE': {
                const peer = this.peers[data.remote]
                peer.connection.addIceCandidate(new RTCIceCandidate(data.candidate))
                break
            }
            case 'LIST': {
                for (let i = 0; i < data.servers.length; i++) {
                    this.recvQueue[data.port].push({
                        id: data.servers[i].id,
                        srcport: data.servers[i].port,
                        data: this.updateListSeq(data.seqnum, Buffer.from(data.servers[i].data, 'base64'))
                    })
                    this.options.onavailable && this.options.onavailable(data.port)
                }
                break
            }
        }
    }

    onpacket(id, data) {
        data = new Uint8Array(data);
        const srcport = (data[0] << 8) | data[1];
        const dstport = (data[2] << 8) | data[3];
        this.recvQueue[dstport].push({ id, srcport, data: data.subarray(4) })
        this.options.onavailable && this.options.onavailable(dstport)
    }

    updateListSeq (seqnum, data) {
        data[44] = seqnum >> 0
        data[45] = seqnum >> 8
        data[46] = seqnum >> 16
        data[47] = seqnum >> 24
        return data
    }

    listServers (seqnum, port) {
        this.ws.send(JSON.stringify({
            type: 'LIST',
            seqnum,
            port
        }))
    }

    registerServer (data, key, latency) {
        this.ws.send(JSON.stringify({
            type: 'REGISTER',
            data: data ? data.toString('base64') : null,
            port: this.lastDestPort,
            key,
            latency
        }))
    }

    accept (remote, answer) {
        this.ws.send(JSON.stringify({
            type: 'ACCEPT',
            remote,
            answer
        }))
    }

    bind (destport) {
        // XXX HACK
        this.lastDestPort = destport
/*
        this.ws.send(JSON.stringify({
            type: 'BIND'
        }))
*/
        this.recvQueue[destport] = []
    }

    connect (remote) {
        const peerConnection = new RTCPeerConnection(this.options.webrtc)
        const peerChannel = peerConnection.createDataChannel('nox-game', {
            negotiated: true,
            id: 0
        })
        peerConnection.addEventListener('connectionstatechange', function () {
            switch (peerConnection.connectionState) {
            case 'disconnected':
            case 'failed':
            case 'closed':
                this.options.onclose && this.options.onclose(remote)
                break
            }
        })
        peerChannel.addEventListener('message', ({ data }) => this.onpacket(remote, data))
        peerConnection.addEventListener('icecandidate', ({ candidate }) => {
            if (candidate) {
                this.ws.send(JSON.stringify({
                    type: 'ICECANDIDATE',
                    remote,
                    candidate
                }))
            }
        })
        peerChannel.addEventListener('open', () => {
            const peer = this.peers[remote]
            peer.channel = peerChannel
            for (let i = 0; i < peer.sendQueue.length; i++)
                peer.channel.send(peer.sendQueue[i])
            peer.sendQueue = null
        })
        peerConnection.createOffer().then((offer) => {
            peerConnection.setLocalDescription(offer)
            this.ws.send(JSON.stringify({
               type: 'CONNECT',
               remote,
               offer
            }))
        })
        this.peers[remote] = {
            id: remote,
            connection: peerConnection,
            channel: null,
            sendQueue: []
        }
    }

    available (destport) {
        if (!this.recvQueue[destport].length)
            return 0
        return this.recvQueue[destport][0].data.length
    }

    recvfrom (destport) {
        if (!this.recvQueue[destport].length)
            return null, null
        const { id, srcport, data } = this.recvQueue[destport].shift()
        return [id, srcport, data]
    }

    sendto (srcport, id, destport, data) {
        data = Uint8Array.of(srcport >> 8, srcport, destport >> 8, destport, ...data)
        if (!this.peers[id])
            this.connect(id)

        const peer = this.peers[id]
        if (peer.channel) {
            if (this.peers[id].channel.readyState == 'open')
                this.peers[id].channel.send(data)
        } else {
            peer.sendQueue.push(data)
        }
    }
}

class RelayServer {
    constructor(addr, port, info) {
        this.addr = addr
        this.port = port
        this.info = info
        this.registered = false
        this.timer = null
        this.timeouts = 0

        const clients = this.clients = {}
        const pingSocket = dgram.createSocket('udp4')
        pingSocket.bind({})
        const network = this.network = new Network({
            url: "wss://playnox.xyz:443",
            webrtc: {
                iceServers: [
                    { urls: "stun:stun.l.google.com:19302" }
                ]
            },
            onopen: () => {
                const ping = () => {
                    this.timer = setTimeout(() => {
                        this.timeouts += 1
                        console.log('Timeout', this.timeouts, this.addr, this.port)
                        if (this.registered) {
                            network.registerServer(null)
                            this.registered = false
                        }
                        if (this.timeouts >= 10 && this.ontimeout) {
                            this.ontimeout()
                        } else {
                            ping()
                        }
                    }, 5000)

                    const ms = (new Date()) & 0x7fffffff
                    pingSocket.send(new Uint8Array([0xff, 0, 5, ms, ms >> 8, ms >> 16, ms >> 24]), this.port, this.addr, (err) => {})
                }

                network.bind(1024)
                pingSocket.removeAllListeners('message')
                pingSocket.on('message', (msg) => {
                    const now = (new Date()) & 0x7fffffff
                    const prev = msg[3] | (msg[4] << 8) | (msg[5] << 16) | (msg[6] << 24)
                    const latency = now - prev

                    if (this.timer !== null) {
                        clearTimeout(this.timer)
                        this.timer = null
                    }
                    this.timeouts = 0

                    network.registerServer(info, this.addr + ':' + this.port, latency)
                    this.registered = true

                    setTimeout(ping, 5000)
                })
                ping()
            },
            onavailable: (dstport) => {
                while (network.available(dstport)) {
                    const [srcid, srcport, data] = network.recvfrom(dstport)
                    let client = clients[srcid] && clients[srcid][srcport]
                    if (!client) {
                        if (!clients[srcid]) {
                            clients[srcid] = {}
                        }
                        client = clients[srcid][srcport] = {
                            sendQueue: [],
                            socket: dgram.createSocket('udp4'),
                        }
                        client.socket.on('message', (msg) => {
                            network.sendto(dstport, srcid, srcport, msg)
                        })
                        client.socket.bind({}, () => {
                            for (let x in client.sendQueue)
                                client.socket.send(client.sendQueue[x], this.port, this.addr, (err) => {})
                            client.sendQueue = null
                        })
                    }
                    if (client.sendQueue) {
                        client.sendQueue.push(data)
                    } else {
                        client.socket.send(data, this.port, this.addr, (err) => {})
                    }
                }
            },
            onclose: (id) => {
                if (!clients[id])
                    return;
                for (const port in clients[id]) {
                    const client = clients[id][port]
                    if (client.socket) {
                        console.log('Closing ' + id + ' ' + port)
                        client.socket.close()
                    }
                }
                delete clients[id]
            }
        })
    }

    close () {
        this.network.close()
        delete this.network

        for (id in this.clients) {
            for (port in this.clients[id]) {
                const socket = clients[id][port].socket
                if (socket) {
                    socket.close()
                }
            }
        }
        delete this.clients

        if (this.timer !== null) {
            clearTimeout(this.timer)
            delete this.timer
        }

        pingSocket.close()
    }

    updateInfo (info) {
        if (this.info.compare(info) != 0) {
            this.info = info
            this.registered = false
        }
    }
}

servers = {}
const wolapiClient = new WOLAPIClient({
    host: 'xwis.net',
    port: 4000,
    onserver (key, addr, port, info) {
        let server = servers[key]
        if (server && (server.addr != addr || server.port != port)) {
            console.log('Closing relay for ' + key + ' @ ' + addr + ':' + port)
            server.close()
            servers[key] = server = null
        }
        if (port == 0)
            return
        if (!server) {
            console.log('Opening relay for ' + key + ' @ ' + addr + ':' + port)
            servers[key] = server = new RelayServer(addr, port, info)
            server.ontimeout = () => {
                console.log('Closing relay for ' + key + ' @ ' + addr + ':' + port)
                if (servers[key]) {
                    servers[key].close()
                    servers[key] = server = null
                }
            }
        } else {
            server.updateInfo(info)
        }
    }
})
