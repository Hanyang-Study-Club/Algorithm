#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from itertools import combinations
input = sys.stdin.readline

n, k = map(int, input().split())
w_list = [] # 각 코인별 가치
for _ in range(n):
    w_list.append(int(input()))

dp = [0 for i in range(k+1)] # 사이즈 k+1만큼의 리스트 선언
dp[0] = 1
# dp[i]: i원을 만들때 가능한 경우의 수
# dp[0]: 동전 하나를 사용하는 경우 무조건 1

for i in w_list:
    for j in range(i, k+1):
        # i원 동전으로 j원 만들기: j-i원을 만든 후 i원을 추가
        if j-i >= 0:
            dp[j] += dp[j-i] # 점화식
print(dp[k])