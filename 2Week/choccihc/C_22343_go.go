package main

import (
	"bufio"
	"fmt"
	"os"
)

func bracket_calc(bracket string, size int) []int{
	stack := make([]int, size + 1)
	open := 0

	for i, v := range bracket {
		if v == '(' {
			open++
		} else {
			open--
			if bracket[i-1] == '(' {
				stack[open]++
			}
		}
	}

	// 계산 안하고 stack을 2진수를 담도록 만들어줌
	for idx := 0; idx < len(stack) - 1; idx++ {
		stack[idx+1] += stack[idx] / 2
		stack[idx] %= 2
	}

	return stack
}

// 2진수 배열 두개를 비교
func comp(sumA []int, sumB []int) rune{
	for i := len(sumA)-1 ; i >= 0 ; i--{
		if sumA[i] > sumB[i] {
			return '>'
		}
		if sumA[i] < sumB[i] {
			return '<'
		} 
	}
	return '=' // 밖에 꺼내기 싫었는데 계속 오류나서 그냥 뽑아버림
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)
	
	n := 0
	fmt.Fscan(stdin, &n)
	out := make([]rune, n)

	for i:=0; i < n; i++ {
		A := ""
		fmt.Fscan(stdin, &A)

		B := ""
		fmt.Fscan(stdin, &B)

		var size int 
		// A와 B 둘 중 큰 문자열의 길이만큼 숫자를 담을 배열 생성하여 비교시 out of range안나오도록
		if len(A) > len(B){
			size = len(A)/2
		} else{
			size = len(B)/2
		}

		calc_A := bracket_calc(A, size)
		calc_B := bracket_calc(B, size)
		out[i] = comp(calc_A, calc_B)
	}

	for _, v := range out{
		fmt.Fprintln(stdout, string(v))
	}

	stdout.Flush()
}
