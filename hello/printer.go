package hello

import (
	"fmt"
)

// Passing target language objects to Go

type Printer interface {
	Print(s string)
}

func PrintHello(p Printer) {
	p.Print(fmt.Sprintf(`Hello world! current time: %d`, reverseCurrentTime()))
}
