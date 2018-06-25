package hello

import "fmt"

func Greeting(nick string) string {
	return fmt.Sprintf(`Hello, %s!`, nick)
}
