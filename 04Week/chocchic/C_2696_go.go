// 중앙값 구하기

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

	var T int
	fmt.Fscan(stdin, &T)
	result_seq := make([][]int, 0, T)
	for T > 0 {
		var M, i int = 0, 0
		fmt.Fscan(stdin, &M)

		seq := make([]int, 0, M)
		current_seq := make([]int, 0, M/2+1)

		for i < M {
			var element int
			fmt.Fscan(stdin, &element)
			seq = append(seq, element)
			sort.Slice(seq, func(i, j int) bool { return seq[i] < seq[j] })
			if i%2 == 0 {
				current_seq = append(current_seq, seq[len(seq)/2])
			}
			i++
		}
		result_seq = append(result_seq, current_seq)
		T--
	}

	for i, v := range result_seq {
		fmt.Fprintln(stdout, len(v))
		for idx, v := range result_seq[i] {
			fmt.Fprint(stdout, v, " ")
			if (idx+1)%10 == 0 {
				fmt.Fprintln(stdout)
			}
		}
		fmt.Fprintln(stdout)
	}
	stdout.Flush()
}
