#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from itertools import combinations
input = sys.stdin.readline

N, M = map(int, input().split())
# 표의 크기 N과 합을 구해야 하는 횟수 M

""" 시간초과
matrix = []
for _ in range(N):
    matrix.append(list(map(int, input().split())))

for _ in range(M):
    x1, y1, x2, y2 = map(int, input().split())
    answer = 0
    for x in range(x1, x2+1):
        for y in range(y1, y2+1):
            # print(x, y)
            answer+=matrix[x-1][y-1]
    print(answer)
"""

matrix = []
for _ in range(N):
    matrix.append(list(map(int, input().split()))) # 2차원 배열을 받음
    
dp = [[0]*(N+1) for i in range(N+1)] # (N+1)x(N+1) dp 매트릭스
# N+1해주는 이유: 안그러면 밑에서 인덱스 계산해주기 불편함. 문제는 인덱스가 0부터가아닌 1부터 시작함.

for i in range(0, N+1):
    for j in range(0, N+1):
        dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + matrix[i-1][j-1]

for k in range(M):
    x1, y1, x2, y2 = map(int, input().split())
    result = dp[x2][y2] - dp[x2][y1-1] -dp[x1-1][y2] + dp[x1-1][y1-1] # 점화식
    print(result)