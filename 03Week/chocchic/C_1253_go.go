package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)

	n, good, ele := 0, 0, 0
	fmt.Fscan(stdin, &n)

	ns := make([]int, 0, n)

	for i := 0; i < n; i++ {
		fmt.Fscan(stdin, &ele)
		ns = append(ns, ele)
	}
	sort.Slice(ns, func(i, j int) bool { return ns[i] < ns[j] })

	for idx, val := range ns {
		start, end := 0, n-1
		for start < end {
			if idx == start {
				start++
				continue
			}
			if idx == end {
				end--
				continue
			}
			sum := ns[start] + ns[end]
			if sum == val {
				good++
				break
			} else if sum < val {
				start++
			} else {
				end--
			}
		}
	}

	fmt.Fprintln(stdout, good)

	stdout.Flush()
}
