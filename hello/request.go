package hello

import (
	"os"
	"time"

	"encoding/json"
	"log"
)

type Request struct {
	Uid        int      `json:"uid"`        // 调用者的UID
	Command    []string `json:"command"`    // 执行的命令
	Background bool     `json:"background"` // 0 前台运行，1 后台运行
	Timeout    int      `json:"timeout"`    // 超时时间，秒
	Timestamp  int64    `json:"timestamp"`  // 时间戳，秒
}

func NewRequest(command string, background bool, timeout int) *Request {
	var cmdArray []string

	e := json.Unmarshal([]byte(command), &cmdArray)
	if e != nil {
		log.Println(`NewRequest: json decode error:`, e)
		return nil
	}

	return &Request{
		Uid:        os.Getuid(),
		Command:    cmdArray,
		Background: background,
		Timeout:    timeout,
		Timestamp:  time.Now().Unix(),
	}
}

func (r *Request) JsonEncode() string {
	content, _ := json.Marshal(r)
	return string(content)
}
