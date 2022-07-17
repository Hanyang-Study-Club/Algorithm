#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from itertools import combinations
input = sys.stdin.readline

N = int(input()) # 카드의 개수
num_list = list(map(int, input().split(' ')))

M = sum(num_list) # 숫자 리스트의 모든 수 합

comb_list = set()
for num in range(N):
    comb = combinations(num_list, num+1) # 순서 상관없이 모든 가능한 조합
    for c in comb:
        num_sum = sum(c)
        if num_sum <= M: # 조합의 합이 M보다 작으면 set에 추가(중복 제거됨)
            comb_list.add(num_sum)

print(M - len(comb_list))