#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
from itertools import combinations
input = sys.stdin.readline

def one_cnt(n):
    count = 0

    k = 0
    while 2**k <= n: # 이진수 각 자리를 돌면서
        p = 2**(k+1) # 패턴의 길이. 예를들어 0011의 패턴이 반복되면 p=4가 됨
        p_count = (n+1)//p # 패턴이 나오는 수

        # (완성된 패턴의 갯수) * (패턴의 길이의 절반 = 한 패턴에서 1은 절반이 나오기 때문)
        count += p_count * (p//2)

        # 완성되지 않은 곳의 길이... 0011001에서 left는 3이다. 패턴 0011을 제외하면 001이 남기 때문
        left = (n+1) % p

        # 001에서, 00의 길이는 p/2
        count += max(0, left - p//2) # left가 p/2보다 작을 때에는 음수값이 나오게 되므로, max(0, left - p//2)를 통해 식을 완성
        k += 1
    return count

A, B = map(int, input().split())
print(one_cnt(B)-one_cnt(A-1))

"""
0: 0 0 0 0 
1: 0 0 0 1
2: 0 0 1 0
3: 0 0 1 1
4: 0 1 0 0
5: 0 1 0 1
6: 0 1 1 0
7: 0 1 1 1
8: 1 0 0 0
9: 1 0 0 1
10: 1 0 1 0
11: 1 0 1 1
12: 1 1 0 0
"""