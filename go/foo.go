// Use `go run foo.go` to run your program

package main

import (
	. "fmt"
	"runtime"
	"time"
)

var i = 0

const ITERATIONS = 1000000

func incrementing() {
	for a := 0; a < ITERATIONS; a++ {
		i++
	}
}

func decrementing() {
	for a := 0; a < ITERATIONS; a++ {
		i--
	}
}

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU()) // I guess this is a hint to what GOMAXPROCS does...
	// Try doing the exercise both with and without it!

	// TODO: Spawn both functions as goroutines
	go incrementing()
	go decrementing()

	// We have no way to wait for the completion of a goroutine (without additional synchronization of some sort)
	// We'll come back to using channels in Exercise 2. For now: Sleep.
	time.Sleep(500 * time.Millisecond)
	Println("The magic number is:", i)
}
