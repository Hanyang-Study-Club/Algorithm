#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from itertools import combinations
input = sys.stdin.readline

N, K = map(int, input().split())
# N: 온도를 측정한 전체 날짜의 수
# K: 합을 구하기 위한 연속적인 날짜의 수

temp_list = list(map(int, input().split())) # 길이 N
cum_sum = [] # 누적합 리스트

# N = [3, -2, -4, -9, 0, 3, 7, 13, 8, -3]
for i in range(N-K+1): # ex: 전체 날짜 수(10) - 연속적인 날짜 수(2) + 1 = 9, 인덱스는 0~8까지
    tmp_sum = 0
    for j in range(i, i+K): # ex: i=0 ~ i+K=2, 인덱스는 0~1까지
        tmp_sum += temp_list[j]
    cum_sum.append(tmp_sum)
print(max(cum_sum))