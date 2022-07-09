package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

type Stack struct {
	stack  *list.List
	cursor *list.Element // 커서가 가리키는 list내 element
	front  bool          // 커서가 맨 앞인지
}

func NewEditor(editstring string) *Stack {
	new_stack := list.New()
	for _, v := range editstring {
		new_stack.PushBack(v)
	}
	new_cursor := new_stack.Back()
	return &Stack{stack: new_stack, cursor: new_cursor, front: false}
}

func (s *Stack) Push(v interface{}) {
	if s.front {
		s.stack.InsertBefore(v, s.cursor)
		s.cursor = s.cursor.Prev()
		s.front = false
	} else {
		s.stack.InsertAfter(v, s.cursor)
		s.cursor = s.cursor.Next() // 넣어진 것을 현재 커서로
	}
}

func (s *Stack) Pop() {
	if !s.front {
		prev_cursor := s.cursor.Prev()
		next_cursor := s.cursor.Next()
		if prev_cursor == nil {
			s.stack.Remove(s.cursor)
			s.cursor = next_cursor
			s.front = true
		} else {
			s.stack.Remove(s.cursor)
			s.cursor = prev_cursor
		}
	}
}

func (s *Stack) L() {
	if !s.front {
		if s.cursor.Prev() != nil {
			s.cursor = s.cursor.Prev()
		} else {
			s.front = true
		}
	}
}

func (s *Stack) D() {
	if s.front {
		s.front = !s.front
	} else {
		if s.cursor.Next() != nil {
			s.cursor = s.cursor.Next()
		}
	}
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)

	edit := ""
	fmt.Fscan(stdin, &edit)
	editor := NewEditor(edit)

	num := 0
	fmt.Fscan(stdin, &num)

	for ; num > 0; num-- {
		command := "a"
		fmt.Fscan(stdin, &command)
		switch command {
		case "L":
			editor.L()
			break
		case "D":
			editor.D()
			break
		case "B":
			editor.Pop()
			break
		default:
			fmt.Fscan(stdin, &command)
			editor.Push(command[0])
			break
		}
	}

	last := editor.stack.Front()
	for ; last != nil; last = last.Next() {
		fmt.Fprintf(stdout, "%c", last.Value)
	}

	stdout.Flush()
}
