package main

import (
	"fmt"
)
// Function to be written to compute the factorial of n
//
// factorial 0 = 1
// factorial n = n * factorial (n-1)

func factorial(n int64, c chan int64) int64 {
  var temp int64 = n
  var sum int64 = 1
  for (n!=0){
    sum = sum*n
    n--
  }
 fmt.Println("Should be a factorial function")
 return sum
}
func main() {
 // Compute and output
  c := make(chan int64)
  go factorial(n,c)
 fmt.Println("Factorial 16", factorial(16))
}
