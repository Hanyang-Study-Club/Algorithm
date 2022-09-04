// 콘센트
package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"sort"
)

//**** heap 내장함수를 이용하기 위한 인터페이스 ****//
type Heap [][17]int

func (h *Heap) Less(i, j int) bool {
	for idx := 16; idx > 0; idx-- {
		if (*h)[i][idx] != (*h)[j][idx] {
			return (*h)[i][idx] < (*h)[j][idx]
		}
	}
	return (*h)[i][0] < (*h)[j][0]
}

func (h *Heap) Swap(i, j int) {
	(*h)[i], (*h)[j] = (*h)[j], (*h)[i]
}

func (h *Heap) Len() int {
	return len(*h)
}

func (h *Heap) Pop() (v any) {
	*h, v = (*h)[:h.Len()-1], (*h)[h.Len()-1]
	return
}

func (h *Heap) Push(v any) {
	*h = append(*h, v.([17]int))
}

//************************************************//

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)

	var n, m int
	fmt.Fscan(stdin, &n, &m)

	power_socket := make(Heap, m)
	electronics := make([]int, 0, n)

	for ; n > 0; n-- {
		var hour int
		fmt.Fscan(stdin, &hour)
		electronics = append(electronics, hour)
	}
	sort.Slice(electronics, func(i, j int) bool { return electronics[i] > electronics[j] })

	for _, v := range electronics {
		var r uint8 = 0

		for ; v > 1; v >>= 1 {
			r++
		}

		poped := heap.Pop(&power_socket).([17]int)
		poped[r]++

		for r < 16 {
			if poped[r] >= 2 {
				poped[r+1] += poped[r] / 2
				poped[r] %= 2
			}
			r++
		}

		heap.Push(&power_socket, poped)
		sort.Slice(power_socket, power_socket.Less)

	}
	var sum int = 0

	for idx, v := range power_socket[m-1] {
		sum += (1 << idx) * v
	}

	fmt.Fprintln(stdout, sum)

	stdout.Flush()
}
