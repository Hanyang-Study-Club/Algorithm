// 카드 합체 놀이
package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"sort"
)

// https://go.dev/src/container/heap/heap.go
// https://go.dev/src/container/heap/heap_test.go

//**** heap 내장함수를 이용하기 위한 인터페이스 ****//
type Heap []int

func (h *Heap) Less(i, j int) bool {
	return (*h)[i] > (*h)[j]
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
	*h = append(*h, v.(int))
}

//************************************************//

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)

	var n, m int
	fmt.Fscan(stdin, &n, &m)

	pq := make(Heap, 0, n)

	for ; n > 0; n-- {
		var c int
		fmt.Fscan(stdin, &c)
		heap.Push(&pq, c)
	}

	sort.Slice(pq, pq.Less) // heap.Init을 사용하면 전체 heap이 정렬되는 것이 아니라 가장 작은 값만 root에 가게 됨
	// 그렇다고 팝을 한번 할 때마다 정렬하기엔 너무 바보같아서 전체 정렬을 더할때마다 해주기로 함

	for ; m > 0; m-- {
		sum := pq.Pop().(int) + pq.Pop().(int)
		heap.Push(&pq, sum)
		heap.Push(&pq, sum)
		sort.Slice(pq, pq.Less)
	}

	sum := 0
	for _, v := range pq {
		sum += v
	}

	fmt.Fprintln(stdout, sum)
	stdout.Flush()
}
