function initfs() {
    FS.mkdir('/assets');
    FS.mount(IDBFS, {}, '/assets');

    let preload = [
        "/assets/audio.bag",
        "/assets/audio.idx",
        "/assets/default.cfg",
        "/assets/gamedata.bin",
        "/assets/large.fnt",
        "/assets/mapcycle.txt",
        "/assets/monster.bin",
        "/assets/modifier.bin",
        "/assets/number.fnt",
        "/assets/otquest.rul",
        "/assets/small.fnt",
        "/assets/save",
        "/assets/soundset.bin",
        "/assets/thing.bin",
        "/assets/video.bag",
        "/assets/video.idx",
        "/assets/window",
        "/assets/window/access.wnd",
        "/assets/window/advanced.wnd",
        "/assets/window/advidop2.wnd",
        "/assets/window/advidopt.wnd",
        "/assets/window/advserv.wnd",
        "/assets/window/arnamain.wnd",
        "/assets/window/audtest.wnd",
        "/assets/window/briefing.wnd",
        "/assets/window/chared2.wnd",
        "/assets/window/charedit.wnd",
        "/assets/window/conninfo.wnd",
        "/assets/window/conntype.wnd",
        "/assets/window/dialog.wnd",
        "/assets/window/discon.wnd",
        "/assets/window/dlg.wnd",
        "/assets/window/filters.wnd",
        "/assets/window/filter.wnd",
        "/assets/window/gamesel.wnd",
        "/assets/window/gameset.wnd",
        "/assets/window/general.wnd",
        "/assets/window/ggover.wnd",
        "/assets/window/guichat.wnd",
        "/assets/window/gui_ctf.wnd",
        "/assets/window/gui_fb.wnd",
        "/assets/window/guifps.wnd",
        "/assets/window/guikick.wnd",
        "/assets/window/identify.wnd",
        "/assets/window/inputcfg.wnd",
        "/assets/window/journal.wnd",
        "/assets/window/laccess.wnd",
        "/assets/window/ladvserv.wnd",
        "/assets/window/ldlg.wnd",
        "/assets/window/legal.wnd",
        "/assets/window/lgeneral.wnd",
        "/assets/window/load.wnd",
        "/assets/window/locale.wnd",
        "/assets/window/lplayers.wnd",
        "/assets/window/lsanchlp.wnd",
        "/assets/window/lservopt.wnd",
        "/assets/window/lwadvsrv.wnd",
        "/assets/window/lwgenerl.wnd",
        "/assets/window/mainbg.wnd",
        "/assets/window/mainmenu.wnd",
        "/assets/window/mapdnld.wnd",
        "/assets/window/modify.wnd",
        "/assets/window/motd.wnd",
        "/assets/window/multiopt.wnd",
        "/assets/window/multmove.wnd",
        "/assets/window/noxgamex.wnd",
        "/assets/window/noxworld.wnd",
        "/assets/window/objlst.wnd",
        "/assets/window/options.wnd",
        "/assets/window/optsback.wnd",
        "/assets/window/players.wnd",
        "/assets/window/playrlst.wnd",
        "/assets/window/proxlist.wnd",
        "/assets/window/quitmenu.wnd",
        "/assets/window/recplay.wnd",
        "/assets/window/rulelist.wnd",
        "/assets/window/rules.wnd",
        "/assets/window/sanchlp.wnd",
        "/assets/window/save.wnd",
        "/assets/window/selchar.wnd",
        "/assets/window/selclass.wnd",
        "/assets/window/selcolor.wnd",
        "/assets/window/servlist.wnd",
        "/assets/window/servopts.wnd",
        "/assets/window/shop.wnd",
        "/assets/window/skey.wnd",
        "/assets/window/spelllst.wnd",
        "/assets/window/trade.wnd",
        "/assets/window/videoopt.wnd",
        "/assets/window/waccess.wnd",
        "/assets/window/wadvserv.wnd",
        "/assets/window/wgeneral.wnd",
        "/assets/window/wolapi.wnd",
        "/assets/window/wolchan.wnd",
        "/assets/window/wolchat.wnd",
        "/assets/window/woldisc.wnd",
        "/assets/window/wolfind.wnd",
        "/assets/window/wolopt.wnd",
        "/assets/window/wolprog.wnd",
        "/assets/window/wolreg.wnd",
        "/assets/window/wservopt.wnd",
        "/assets/window/yesno.wnd",
        "/assets/maps",
        "/assets/maps/con01a",
        "/assets/maps/con01a/con01a.map",
        "/assets/maps/con02a",
        "/assets/maps/con02a/con02a.map",
        "/assets/maps/con03a",
        "/assets/maps/con03a/con03a.map",
        "/assets/maps/con03b",
        "/assets/maps/con03b/con03b.map",
        "/assets/maps/con04a",
        "/assets/maps/con04a/con04a.map",
        "/assets/maps/con04b",
        "/assets/maps/con04b/con04b.map",
        "/assets/maps/con04c",
        "/assets/maps/con04c/con04c.map",
        "/assets/maps/con05a",
        "/assets/maps/con05a/con05a.map",
        "/assets/maps/con05b",
        "/assets/maps/con05b/con05b.map",
        "/assets/maps/con05c",
        "/assets/maps/con05c/con05c.map",
        "/assets/maps/con06a",
        "/assets/maps/con06a/con06a.map",
        "/assets/maps/con06b",
        "/assets/maps/con06b/con06b.map",
        "/assets/maps/con07a",
        "/assets/maps/con07a/con07a.map",
        "/assets/maps/con07b",
        "/assets/maps/con07b/con07b.map",
        "/assets/maps/con07c",
        "/assets/maps/con07c/con07c.map",
        "/assets/maps/con07d",
        "/assets/maps/con07d/con07d.map",
        "/assets/maps/con07e",
        "/assets/maps/con07e/con07e.map",
        "/assets/maps/con07f",
        "/assets/maps/con07f/con07f.map",
        "/assets/maps/con07g",
        "/assets/maps/con07g/con07g.map",
        "/assets/maps/con07h",
        "/assets/maps/con07h/con07h.map",
        "/assets/maps/con08a",
        "/assets/maps/con08a/con08a.map",
        "/assets/maps/con08b",
        "/assets/maps/con08b/con08b.map",
        "/assets/maps/con08c",
        "/assets/maps/con08c/con08c.map",
        "/assets/maps/con08d",
        "/assets/maps/con08d/con08d.map",
        "/assets/maps/con08e",
        "/assets/maps/con08e/con08e.map",
        "/assets/maps/con09a",
        "/assets/maps/con09a/con09a.map",
        "/assets/maps/con09b",
        "/assets/maps/con09b/con09b.map",
        "/assets/maps/con09c",
        "/assets/maps/con09c/con09c.map",
        "/assets/maps/con09d",
        "/assets/maps/con09d/con09d.map",
        "/assets/maps/con10a",
        "/assets/maps/con10a/con10a.map",
        "/assets/maps/con10b",
        "/assets/maps/con10b/con10b.map",
        "/assets/maps/con10c",
        "/assets/maps/con10c/con10c.map",
        "/assets/maps/con10d",
        "/assets/maps/con10d/con10d.map",
        "/assets/maps/con11a",
        "/assets/maps/con11a/con11a.map",
        "/assets/maps/estate",
        "/assets/maps/estate/estate.map",
        "/assets/maps/estate/estate.nxz",
        "/assets/maps/estate/estate.rul",
        "/assets/maps/g_castld",
        "/assets/maps/g_castld/g_castld.map",
        "/assets/maps/g_castld/g_castld.nxz",
        "/assets/maps/g_castle",
        "/assets/maps/g_castle/g_castle.map",
        "/assets/maps/g_castle/g_castle.nxz",
        "/assets/maps/g_cryptd",
        "/assets/maps/g_cryptd/g_cryptd.map",
        "/assets/maps/g_cryptd/g_cryptd.nxz",
        "/assets/maps/g_crypts",
        "/assets/maps/g_crypts/g_crypts.map",
        "/assets/maps/g_crypts/g_crypts.nxz",
        "/assets/maps/g_foresd",
        "/assets/maps/g_foresd/g_foresd.map",
        "/assets/maps/g_foresd/g_foresd.nxz",
        "/assets/maps/g_forest",
        "/assets/maps/g_forest/g_forest.map",
        "/assets/maps/g_forest/g_forest.nxz",
        "/assets/maps/g_lava",
        "/assets/maps/g_lava/g_lava.map",
        "/assets/maps/g_lava/g_lava.nxz",
        "/assets/maps/g_lotd",
        "/assets/maps/g_lotd/g_lotd.map",
        "/assets/maps/g_lotd/g_lotd.nxz",
        "/assets/maps/g_lotdd",
        "/assets/maps/g_lotdd/g_lotdd.map",
        "/assets/maps/g_lotdd/g_lotdd.nxz",
        "/assets/maps/g_mines",
        "/assets/maps/g_mines/g_mines.map",
        "/assets/maps/g_mines/g_mines.nxz",
        "/assets/maps/g_swamp",
        "/assets/maps/g_swamp/g_swamp.map",
        "/assets/maps/g_swamp/g_swamp.nxz",
        "/assets/maps/g_templd",
        "/assets/maps/g_templd/g_templd.map",
        "/assets/maps/g_templd/g_templd.nxz",
        "/assets/maps/g_temple",
        "/assets/maps/g_temple/g_temple.map",
        "/assets/maps/g_temple/g_temple.nxz",
        "/assets/maps/so_beach",
        "/assets/maps/so_beach/so_beach.map",
        "/assets/maps/so_beach/so_beach.nxz",
        "/assets/maps/so_brin",
        "/assets/maps/so_brin/so_brin.map",
        "/assets/maps/so_brin/so_brin.nxz",
        "/assets/maps/so_druid",
        "/assets/maps/so_druid/so_druid.map",
        "/assets/maps/so_druid/so_druid.nxz",
        "/assets/maps/so_dun",
        "/assets/maps/so_dun/so_dun.map",
        "/assets/maps/so_dun/so_dun.nxz",
        "/assets/maps/so_fov",
        "/assets/maps/so_fov/so_fov.map",
        "/assets/maps/so_fov/so_fov.nxz",
        "/assets/maps/so_galav",
        "/assets/maps/so_galav/so_galav.map",
        "/assets/maps/so_galav/so_galav.nxz",
        "/assets/maps/so_grok",
        "/assets/maps/so_grok/so_grok.map",
        "/assets/maps/so_grok/so_grok.nxz",
        "/assets/maps/so_ix",
        "/assets/maps/so_ix/so_ix.map",
        "/assets/maps/so_ix/so_ix.nxz",
        "/assets/maps/so_lod",
        "/assets/maps/so_lod/so_lod.map",
        "/assets/maps/so_lod/so_lod.nxz",
        "/assets/maps/so_mines",
        "/assets/maps/so_mines/so_mines.map",
        "/assets/maps/so_mines/so_mines.nxz",
        "/assets/maps/so_mount",
        "/assets/maps/so_mount/so_mount.map",
        "/assets/maps/so_mount/so_mount.nxz",
        "/assets/maps/so_open",
        "/assets/maps/so_open/so_open.map",
        "/assets/maps/so_open/so_open.nxz",
        "/assets/maps/so_swamp",
        "/assets/maps/so_swamp/so_swamp.map",
        "/assets/maps/so_swamp/so_swamp.nxz",
        "/assets/maps/so_waste",
        "/assets/maps/so_waste/so_waste.map",
        "/assets/maps/so_waste/so_waste.nxz",
        "/assets/maps/so_woods",
        "/assets/maps/so_woods/so_woods.map",
        "/assets/maps/so_woods/so_woods.nxz",
        "/assets/maps/war01a",
        "/assets/maps/war01a/war01a.map",
        "/assets/maps/war02a",
        "/assets/maps/war02a/war02a.map",
        "/assets/maps/war02b",
        "/assets/maps/war02b/war02b.map",
        "/assets/maps/war03a",
        "/assets/maps/war03a/war03a.map",
        "/assets/maps/war03b",
        "/assets/maps/war03b/war03b.map",
        "/assets/maps/war03c",
        "/assets/maps/war03c/war03c.map",
        "/assets/maps/war03d",
        "/assets/maps/war03d/war03d.map",
        "/assets/maps/war04a",
        "/assets/maps/war04a/war04a.map",
        "/assets/maps/war04b",
        "/assets/maps/war04b/war04b.map",
        "/assets/maps/war04c",
        "/assets/maps/war04c/war04c.map",
        "/assets/maps/war05a",
        "/assets/maps/war05a/war05a.map",
        "/assets/maps/war05b",
        "/assets/maps/war05b/war05b.map",
        "/assets/maps/war05c",
        "/assets/maps/war05c/war05c.map",
        "/assets/maps/war06a",
        "/assets/maps/war06a/war06a.map",
        "/assets/maps/war06b",
        "/assets/maps/war06b/war06b.map",
        "/assets/maps/war07a",
        "/assets/maps/war07a/war07a.map",
        "/assets/maps/war07b",
        "/assets/maps/war07b/war07b.map",
        "/assets/maps/war07c",
        "/assets/maps/war07c/war07c.map",
        "/assets/maps/war07d",
        "/assets/maps/war07d/war07d.map",
        "/assets/maps/war07e",
        "/assets/maps/war07e/war07e.map",
        "/assets/maps/war07f",
        "/assets/maps/war07f/war07f.map",
        "/assets/maps/war07g",
        "/assets/maps/war07g/war07g.map",
        "/assets/maps/war07h",
        "/assets/maps/war07h/war07h.map",
        "/assets/maps/war08a",
        "/assets/maps/war08a/war08a.map",
        "/assets/maps/war08b",
        "/assets/maps/war08b/war08b.map",
        "/assets/maps/war08c",
        "/assets/maps/war08c/war08c.map",
        "/assets/maps/war08d",
        "/assets/maps/war08d/war08d.map",
        "/assets/maps/war08e",
        "/assets/maps/war08e/war08e.map",
        "/assets/maps/war09a",
        "/assets/maps/war09a/war09a.map",
        "/assets/maps/war09b",
        "/assets/maps/war09b/war09b.map",
        "/assets/maps/war09c",
        "/assets/maps/war09c/war09c.map",
        "/assets/maps/war09d",
        "/assets/maps/war09d/war09d.map",
        "/assets/maps/war10a",
        "/assets/maps/war10a/war10a.map",
        "/assets/maps/war10b",
        "/assets/maps/war10b/war10b.map",
        "/assets/maps/war10c",
        "/assets/maps/war10c/war10c.map",
        "/assets/maps/war10d",
        "/assets/maps/war10d/war10d.map",
        "/assets/maps/war11a",
        "/assets/maps/war11a/war11a.map",
        "/assets/maps/wiz01a",
        "/assets/maps/wiz01a/wiz01a.map",
        "/assets/maps/wiz02a",
        "/assets/maps/wiz02a/wiz02a.map",
        "/assets/maps/wiz02b",
        "/assets/maps/wiz02b/wiz02b.map",
        "/assets/maps/wiz02c",
        "/assets/maps/wiz02c/wiz02c.map",
        "/assets/maps/wiz03a",
        "/assets/maps/wiz03a/wiz03a.map",
        "/assets/maps/wiz03b",
        "/assets/maps/wiz03b/wiz03b.map",
        "/assets/maps/wiz03c",
        "/assets/maps/wiz03c/wiz03c.map",
        "/assets/maps/wiz04a",
        "/assets/maps/wiz04a/wiz04a.map",
        "/assets/maps/wiz04b",
        "/assets/maps/wiz04b/wiz04b.map",
        "/assets/maps/wiz04c",
        "/assets/maps/wiz04c/wiz04c.map",
        "/assets/maps/wiz05a",
        "/assets/maps/wiz05a/wiz05a.map",
        "/assets/maps/wiz05b",
        "/assets/maps/wiz05b/wiz05b.map",
        "/assets/maps/wiz05c",
        "/assets/maps/wiz05c/wiz05c.map",
        "/assets/maps/wiz06a",
        "/assets/maps/wiz06a/wiz06a.map",
        "/assets/maps/wiz06b",
        "/assets/maps/wiz06b/wiz06b.map",
        "/assets/maps/wiz06c",
        "/assets/maps/wiz06c/wiz06c.map",
        "/assets/maps/wiz07a",
        "/assets/maps/wiz07a/wiz07a.map",
        "/assets/maps/wiz07b",
        "/assets/maps/wiz07b/wiz07b.map",
        "/assets/maps/wiz07c",
        "/assets/maps/wiz07c/wiz07c.map",
        "/assets/maps/wiz07d",
        "/assets/maps/wiz07d/wiz07d.map",
        "/assets/maps/wiz07e",
        "/assets/maps/wiz07e/wiz07e.map",
        "/assets/maps/wiz07f",
        "/assets/maps/wiz07f/wiz07f.map",
        "/assets/maps/wiz08a",
        "/assets/maps/wiz08a/wiz08a.map",
        "/assets/maps/wiz08b",
        "/assets/maps/wiz08b/wiz08b.map",
        "/assets/maps/wiz08c",
        "/assets/maps/wiz08c/wiz08c.map",
        "/assets/maps/wiz08d",
        "/assets/maps/wiz08d/wiz08d.map",
        "/assets/maps/wiz08e",
        "/assets/maps/wiz08e/wiz08e.map",
        "/assets/maps/wiz09a",
        "/assets/maps/wiz09a/wiz09a.map",
        "/assets/maps/wiz09b",
        "/assets/maps/wiz09b/wiz09b.map",
        "/assets/maps/wiz09c",
        "/assets/maps/wiz09c/wiz09c.map",
        "/assets/maps/wiz09d",
        "/assets/maps/wiz09d/wiz09d.map",
        "/assets/maps/wiz10a",
        "/assets/maps/wiz10a/wiz10a.map",
        "/assets/maps/wiz10b",
        "/assets/maps/wiz10b/wiz10b.map",
        "/assets/maps/wiz10c",
        "/assets/maps/wiz10c/wiz10c.map",
        "/assets/maps/wiz10d",
        "/assets/maps/wiz10d/wiz10d.map",
        "/assets/maps/wiz11a",
        "/assets/maps/wiz11a/wiz11a.map",
        "/assets/maps/beneath",
        "/assets/maps/beneath/beneath.map",
        "/assets/maps/beneath/beneath.nxz",
        "/assets/en",
        "/assets/ko",
        "/assets/en/default.fnt",
        "/assets/en/nox.csf",
        "/assets/ko/default.fnt",
        "/assets/ko/nox.csf",
    ];
    addRunDependency('syncfs');
    FS.syncfs(true, function (err) {
        preload.forEach(function (path) {
            try {
                if (FS.lookupPath(path).node)
                    return;
            } catch (err) {
            }
            if (!path.includes('.'))
                FS.mkdir(path, 0777);
            else
                FS.createPreloadedFile(path, null, path, true, true);
        });
        removeRunDependency('syncfs');
    });
}
Module.preRun = [initfs];

function atou8(data) {
    return new Uint8Array(atob(data).split('').map(function (c) { return c.charCodeAt(0) }))
}
function u8toa(data) {
    return btoa(String.fromCharCode.apply(null, data))
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
        const onopen = () => this.onopen()
        const connect = () => {
            const ws = this.ws = new WebSocket(options.url)
            ws.addEventListener('open', onopen)
            ws.addEventListener('close', onclose)
            ws.addEventListener('message', onmessage)
        }
        connect()
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
                peerChannel.binaryType = 'arraybuffer'
                peerConnection.addEventListener('icecandidate', ({ candidate }) => {
                    if (candidate) {
                        this.isready() && this.ws.send(JSON.stringify({
                            type: 'ICECANDIDATE',
                            remote,
                            candidate
                        }))
                    }
                })
                peerConnection.addEventListener('iceconnectionstatechange', function () {
                    console.log(peerConnection.iceConnectionState)
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
                        data: this.updateListSeq(data.seqnum, atou8(data.servers[i].data))
                    })
                }
                break
            }
        }
    }

    onpacket(id, data) {
        data = new Uint8Array(data);
        const srcport = (data[0] << 8) | data[1];
        const dstport = (data[2] << 8) | data[3];
        if (this.recvQueue[dstport] === undefined)
            this.recvQueue[dstport] = []
        this.recvQueue[dstport].push({ id, srcport, data: data.subarray(4) })
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

    registerServer (data) {
        this.ws.send(JSON.stringify({
            type: 'REGISTER',
            data: data ? u8toa(data) : null,
            port: this.lastDestPort
        }))
    }

    accept (remote, answer) {
        this.isready() && this.ws.send(JSON.stringify({
            type: 'ACCEPT',
            remote,
            answer
        }))
    }

    bind (destport) {
        // XXX workaround
        this.lastDestPort = destport

        this.recvQueue[destport] = []
    }

    connect (remote) {
        const peerConnection = new RTCPeerConnection(this.options.webrtc)
        const peerChannel = peerConnection.createDataChannel('nox-game', {
            negotiated: true,
            id: 0
        })
        peerChannel.binaryType = 'arraybuffer'
        peerChannel.addEventListener('message', ({ data }) => this.onpacket(remote, data))
        peerConnection.addEventListener('icecandidate', ({ candidate }) => {
            if (candidate) {
                this.isready() && this.ws.send(JSON.stringify({
                    type: 'ICECANDIDATE',
                    remote,
                    candidate
                }))
            }
        })
        peerChannel.addEventListener('open', () => {
            clearTimeout(timer)
            const peer = this.peers[remote]
            peer.channel = peerChannel
            for (let i = 0; i < peer.sendQueue.length; i++)
                peer.channel.send(peer.sendQueue[i])
            peer.sendQueue = null
        })
        peerConnection.createOffer().then((offer) => {
            peerConnection.setLocalDescription(offer)
            this.isready() && this.ws.send(JSON.stringify({
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
        let timer = setTimeout(() => {
            console.log('Peer connection timed out.')
            delete this.peers[remote]
            peerChannel.close()
            peerConnection.close()
        }, 5000)
    }

    close () {
    }

    available (destport) {
        if (this.recvQueue[destport] === undefined)
            this.recvQueue[destport] = []
        if (!this.recvQueue[destport].length)
            return 0
        return this.recvQueue[destport][0].data.length
    }

    recvfrom (destport) {
        if (this.recvQueue[destport] === undefined)
            this.recvQueue[destport] = []
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
        if (peer.channel)
            this.peers[id].channel.send(data)
        else
            peer.sendQueue.push(data)
    }
}

network = new Network({
    url: document.location.protocol.replace('http', 'ws') + '//' + document.location.host,
    webrtc: {
        iceServers: [
            { urls: "stun:stun.l.google.com:19302" }
        ]
    }
})
