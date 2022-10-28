package main
import (
 "fmt"
 "os"
 "strconv"
 "time"
)
// Determine whether n is a perfect number
func perfect(n int64) bool {
  var sum,i int64
  sum = 0
  for i = 1; i <= n/2 ; i++ {
    if n%i == 0{
      sum = sum+i
    }
  }

  if sum == n {
    return true 
  } else {
    return false
  }
}
func main() {
 start := time.Now()
 var n,i int64
 var err error
 // Read and argument
 if len(os.Args) < 2 {
 panic(fmt.Sprintf("Usage: must provide number as an argument"))
 }
 if n, err = strconv.ParseInt(os.Args[1],10,64) ; err != nil {
 panic(fmt.Sprintf("Can't parse first argument"))
 }
 // Compute and output whether n is perfect
  for i = 2; i <= n ;i++ {
 fmt.Println(i, "is", perfect(i))
    }
 t := time.Now()
 elapsed := t.Sub(start)
 fmt.Println(elapsed)
}