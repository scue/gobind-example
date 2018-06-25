// +build ios

package hello

import (
	"ObjC/Foundation/NSDate"
)

func reverseCurrentTime() uint64 {
	return uint64(NSDate.Date().TimeIntervalSince1970())
}
