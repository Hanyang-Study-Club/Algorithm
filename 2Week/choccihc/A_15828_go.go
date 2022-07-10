package main

// go의 list
// http://pyrasis.com/book/GoForTheReallyImpatient/Unit55
// go의 큐 자료형 구현
// https://dev-yakuza.posstree.com/ko/golang/data-structure/
// go struct
// https://goldenrabbit.co.kr/2021/10/07/%E1%84%80%E1%85%AE%E1%84%8C%E1%85%A9%E1%84%8E%E1%85%A6%E1%84%8B%E1%85%A6-%E1%84%89%E1%85%A2%E1%86%BC%E1%84%89%E1%85%A5%E1%86%BC%E1%84%8C%E1%85%A1%E1%84%85%E1%85%B3%E1%86%AF-%E1%84%83%E1%85%AE%E1%86%AF/
import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

type Queue struct {
	queue      *list.List
	q_max_size int
	q_size     int
}

func NewQueue(size int) *Queue {
	return &Queue{queue: list.New(), q_max_size: size, q_size: 0}
}

func (q *Queue) Push(v interface{}) {
	q.queue.PushBack(v)
	q.q_size++
}

func (q *Queue) Pop() interface{} {
	front := q.queue.Front()
	if front == nil {
		return nil
	}
	q.q_size--
	return q.queue.Remove(front)
}

// 버퍼로 읽기 : https://hellominchan.tistory.com/39
func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)

	num := 0
	fmt.Fscan(stdin, &num)
	queue := NewQueue(num)

	for {
		fmt.Fscan(stdin, &num)
		if num == 0 {
			queue.Pop()
			continue
		}
		if num == -1 {
			break
		}
		if queue.q_size < queue.q_max_size {
			queue.Push(num)
		}
	}

	last := queue.queue.Front()
	if last == nil {
		fmt.Fprint(stdout, "empty")
	} else {
		for ; last != nil; last = last.Next() {
			//stdout.Write(last.Value)
			fmt.Fprintf(stdout, "%v ", last.Value)
		}
	}

	stdout.Flush()
}
