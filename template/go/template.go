package main

import (
	"bufio"
	"os"
	"strconv"
)

func main() {
	// STDOUT MUST BE FLUSHED MANUALLY!!!
	defer writer.Flush()
}

var scanner = bufio.NewScanner(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func init() {
	scanner.Split(bufio.ScanWords)
}

func scanf() string { return scanner.Text() }

func gcd(_x, _y int64) int64 {
	if _y == 0 {
		return _x
	}
	return gcd(_y, _x%_y)
}

func getI64() (val int64, more bool) {
	if !scanner.Scan() {
		return 0, false
	}
	x, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return x, true
}

func getUI64() (val uint64, more bool) {
	if !scanner.Scan() {
		return 0, false
	}
	x, _ := strconv.ParseUint(scanner.Text(), 10, 64)
	return x, true
}

func getInt() (val int, more bool) {
	v, k := getI64()
	return int(v), k
}

func getFloat() (float64, bool) {
	if !scanner.Scan() {
		return 0, false
	}
	x, _ := strconv.ParseFloat(scanner.Text(), 64)
	return x, true
}

func getString() (string, bool) {
	if !scanner.Scan() {
		return "", false
	}
	return scanner.Text(), true
}

func getBytes() ([]byte, bool) {
	if !scanner.Scan() {
		return nil, false
	}
	return scanner.Bytes(), true
}
