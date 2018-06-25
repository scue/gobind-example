package hello

import (
	"Java/java/lang/System"
)

func reverseCurrentTime() uint64 {
	return uint64(System.CurrentTimeMillis() / 1000)
}
