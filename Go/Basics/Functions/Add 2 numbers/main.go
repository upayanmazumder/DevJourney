package main

import "fmt"

func add(x int, y int) int {
	return x + y
}

func main() {
	x := 1
	y := 2
	fmt.Print(add(x, y))
}
