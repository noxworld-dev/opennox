//+build !server

package main

const isDedicatedServer = false

func runLoop() {
	// Due to SDL we need to run all code related to it on the main thread, which prevents
	// us from using async rendering. So we will run Nox on a secondary thread instead.
	go cmainLoop()
	noxRendererS.Loop()
}
