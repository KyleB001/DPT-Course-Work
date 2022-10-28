// perfectLoopPar.go 

package main

import (
  "fmt"
  "os"
  "time"
  "strconv"
)
 
func perfect(n int64) bool {
  var i, sum int64
  sum = 0
  for i = 1; i<=(n/2); i++ {
    if n%i == 0 {
      sum = sum+i
    }
  }
  if sum == n {
    return true
  } else {
    return false}
}

func perfectInterval(l,u int64, c chan int64) {
  for i := l; i <= u; i++ {
    if perfect(i) {
      c <- i
    }
  }
  close(c)
}

func main() {
  var n int64
  var err error
                                             // Read and validate arguments
  if len(os.Args) < 2 {
    panic(fmt.Sprintf("Usage: must a number as an argument"))
  }

  if n, err = strconv.ParseInt(os.Args[1],10,64) ; err != nil {
    panic(fmt.Sprintf("Can't parse first argument"))
  }
                                             // create channel
  c := make(chan int64) 
                                             // Record start time
  start := time.Now() 
                                             // Start goroutine
  fmt.Println("Perfect numbers between", 1, "and", n)
  go perfectInterval(1,n,c)
                                             // receive and print perfect numbers
  for i := range c {
    fmt.Println(i)
  }
                                             // Record the elapsed time 
  t := time.Now()
  elapsed := t.Sub(start)
  fmt.Println("Elapsed time", elapsed)   
}