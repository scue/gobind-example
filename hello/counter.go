package hello

const (
	defaultValue = 10
)

type Counter struct {
	Value int
}

func (c *Counter) Inc() {
	c.Value++
}

func (c *Counter) Dec() {
	c.Value--
}

func NewCounter() *Counter {
	return &Counter{defaultValue}
}
