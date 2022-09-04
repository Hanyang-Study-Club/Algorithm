package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Words struct {
	word   string
	repeat int
}

func main() {
	stdin := bufio.NewReader(os.Stdin)
	stdout := bufio.NewWriter(os.Stdout)

	n, m := 0, 0
	fmt.Fscan(stdin, &n)
	fmt.Fscan(stdin, &m)

	wordsmap := make(map[string]int)

	var word string

	for ; n > 0; n-- {
		word = ""
		fmt.Fscan(stdin, &word)
		if len(word) >= m {
			_, exists := wordsmap[word]
			if exists {
				wordsmap[word]++
			} else {
				wordsmap[word] = 1
			}
		}
	}

	wordslice := make([]Words, 0, len(wordsmap))
	for k, v := range wordsmap {
		wordslice = append(wordslice, Words{k, v})

	}

	sort.Slice(wordslice, func(i, j int) bool {
		if wordslice[i].repeat != wordslice[j].repeat {
			return wordslice[i].repeat > wordslice[j].repeat
		}
		if len(wordslice[i].word) != len(wordslice[j].word) {
			return len(wordslice[i].word) > len(wordslice[j].word)
		}
		return wordslice[i].word < wordslice[j].word
	})

	for _, v := range wordslice {
		fmt.Fprintln(stdout, v.word)
	}

	stdout.Flush()
}
