#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from itertools import combinations
input = sys.stdin.readline

"""
메모이제이션: 일한 계산을 반복해야 할 때, 이전에 계산한 값을 메모리에 저장함으로써 
동일한 계산의 반복 수행을 제거하여 프로그램 실행 속도를 빠르게 하는 기술이다. 
동적 계획법의 핵심이 되는 기술
"""

# a, b, c범위가 하나라도 0 이하이면 1을 반환하고 하나라도 20 이상이면 w(20, 20, 20)을 호출하기 때문에 최대 범위는 20
dp = [[[0]*21 for _ in range(21)] for _ in range(21)]

def w(a,b,c):
    if a <= 0 or b <= 0 or c <= 0:
        return 1

    if a > 20 or b > 20 or c > 20:
        return w(20, 20, 20)

    if dp[a][b][c]: # w[a][b][c] 값 확인해서 0이 아닐때만 반환
        return dp[a][b][c]

    if a < b and b < c:
        dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
        return dp[a][b][c]
    
    dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1) # otherwise
    return dp[a][b][c]

while True:
    a, b, c = map(int, sys.stdin.readline().rstrip().split())
    if a == -1 and b == -1 and c == -1: # 입력의 마지막은 -1 -1 -1
        break
    answer = w(a, b, c)
    print("w({}, {}, {}) = {}".format(a, b, c, answer))
