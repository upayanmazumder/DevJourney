//go:build prod || dev || test

// single line comment
/*	multi
 * 	line
 * 	comment */

// Packages
package main // Unlike other packages which are libraries, main is special for exes

// Imports
import (
	"fmt" // package math with the alias m
	// web server
	_ "net/http/pprof" // Profiling library imported for side ffects
	// Os functions like working with the file system
	// String conversions
)

// Main function is the entrypoint for the exe
func main() {
	fmt.Println("Hello world")

	beyondHello()
}

// A typical function
func beyondHello() {
	var x int // Variable declaration must be done before use
	x = 3
	y := 4                           // Short declarations use := to infer the type, declaration & assignment
	sum, prod := learnMultiple(x, y) // Functions can return multiple values
	fmt.Println("sum: ", sum, "prod: ", prod)
	learnTypes()
}

// Parameterized functions
func learnMultiple(x, y int) (sum, prod int) {
	return x + y, x - y
}

// Some built-in types
func learnTypes() {
	s1 := "Learn Go" // string type
	s2 := `A "raw" string
	literal can include
	line breaks` // string type

	// Non_ASCII literal. Go source is UTF-8
	g := 'Σ' // rune type, an alias for int32, holds a unicode code point

	f := 3.14159 // float64, an IEEE-754 64-bit floating point number
	c := 3 + 4i  // complex128, representated interally with 2 flaot64s

	// var syntax with initialisers
	var u uint = 7 // Unsigned, but implementation dependent size as with int
	var pi float32 = 22. / 7

	// Conversion syntax with a short declaration
	n := byte('\n')	// byte is an alias for uint8

	// Arrays have size fixed at compile time
	var a4 [4]int											// An array of 4 ints, initialized to all 0
	a5 := [...]int[3, 1, 5, 10, 100]	/* An array initialized with a fixed size of five
																		elements with values 3, 1, 5, 10, 100 */

  // Arrays have value semantics
  a4_cpy := a4										// a4_cpy is a copy of a4, 2 separate instances
  a4_cpy[0] = 25									// only a4_cpy is changed, a4 stays the same
  fmt.Println(a4_cpy[0]) = a4[0])	// false

}
