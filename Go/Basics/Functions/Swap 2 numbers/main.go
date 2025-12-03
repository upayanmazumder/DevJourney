package main

import "fmt"

func swap(x int, y int) (int, int) {
	return y, x
}

func main() {
	x := 4
	y := 1
	fmt.Println(x, y)
	fmt.Println(swap(x, y))
}
