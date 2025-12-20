package main

import "fmt"

func greet() {
	fmt.Print("Hello!")
}

func main() {
	go greet()
	fmt.Println("Main thread")
}
