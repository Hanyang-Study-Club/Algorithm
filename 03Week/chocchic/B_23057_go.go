// 도전숫자왕
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)

	n, m, ele := 0, 0, 0
	fmt.Fscan(stdin, &n)

	addmap := make(map[int]int)

	for i := 0; i < n; i++ {
		addsubset := make([]int, 0, n)
		fmt.Fscan(stdin, &ele)
		m += ele
		addsubset = append(addsubset, ele)

		for k, _ := range addmap {
			sum := k + ele
			addsubset = append(addsubset, sum)
		}
		for _, v := range addsubset {
			addmap[v] = 1
		}
	}

	fmt.Fprintln(stdout, m-len(addmap))

	stdout.Flush()
}
