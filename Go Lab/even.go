package main

import (
  "fmt"
  "os"
  "strconv"
)

func iseven(x int64) bool{
  if x % 2 == 0{
    return true
  }else{
    return false
  }
}
func evenint(l, u int64, c chan int64){
  for i := l; i <= u; i++{
    if iseven(i){
      c <- i
    }
  }
  close(c)
}
func main(){
  var n int64
  var err error
  
  if len(os.Args) < 2 {
    panic(fmt.Sprintf("Usage: must a number as an argument"))
  }

  if n, err = strconv.ParseInt(os.Args[1],10,64) ; err != nil {
    panic(fmt.Sprintf("Can't parse first argument"))
  }

  c := make(chan int64) 

  go evenint(1,n,c)

  for i:= range c{
    fmt.Println(i)
  }
}

