#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

"""
N: 영어 지문에 나오는 단어의 개수
M: 외울 단어의 길이 기준
"""
N, M = map(int, input().split(' '))

"""
다음과 같은 우선순위로 배치
1. 자주 나오는 단어일수록 앞에 배치한다. -> 내림차순
2. 해당 단어의 길이가 길수록 앞에 배치한다. -> 내림차순
3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다 -> 오름차순
"""
word_dict = {}
for _ in range(N):
    word = input().strip()
    word_len = len(word)
    if word_len >= M:
        if word in word_dict:
            word_dict[word]['cnt'] += 1
        else:
            word_dict[word] = {
                'cnt': 1,
                'len': word_len
            }

# print((lambda x : x)(word_dict)) # (lambda 매개변수 : 표현식)(파라미터)
# item[0]은 word_dict의 key, item[1]은 word_dict의 value
# -이면 내림차순, 아니면 오름차순
sorted_dict = sorted(word_dict.items(), key = lambda item: (-item[1]['cnt'], -item[1]['len'], item[0]))
for word in sorted_dict: print(word[0])