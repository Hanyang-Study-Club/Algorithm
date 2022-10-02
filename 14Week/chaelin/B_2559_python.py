#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

# 시간초과
# if __name__ == "__main__":
#     n, k= map(int, input().split())
#     temp = list(map(int, input().split())) #길이 n
#     max_sum = 0
#     for i in range(len(temp)-1):
#         tmp_sum = sum(temp[i:k+i])
#         if max_sum < tmp_sum: max_sum = tmp_sum
#     print(max_sum)

if __name__ == "__main__":
    n, k= map(int, input().split())

    temp = list(map(int, input().split())) #길이 n

    max_sum = sum(temp[:k]) # 처음 k번째까지 sum 구해놓은 것을 max 초기값으로 지정
    tmp_sum = max_sum 
    for i in range(len(temp)):
        if i >= k: # k인덱스 이상이면 지금까지의 인덱스 다 더한것에서 이전 시작 인덱스 빼주기
            tmp_sum += (temp[i] - temp[i-k])
        if max_sum < tmp_sum: max_sum = tmp_sum # max값 업데이트
    print(max_sum)

"""
시작인덱스  끝 인덱스
0   k-1
1   k
2   k+1
3   k+2
...
n-k-2   n-2
n-k-1   n-1
"""