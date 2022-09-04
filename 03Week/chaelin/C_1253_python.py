#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from itertools import combinations
input = sys.stdin.readline

""" 시간초과
N = int(input())
num_list = sorted(map(int, input().split(' ')))
comb_list = set()
comb = combinations(num_list, 2)
cnt_set = set()
for c in comb:
    c_sum = sum(c)
    if c_sum in num_list:
        cnt_set.add(c_sum)
print(len(cnt_set))
"""
# combinations가 일단 시간이 오래걸림
# 수의 위치가 다르면 값이 같아도 다른 수임을 간과함 -> combinations 쓰면 안됨


""" 시간초과
N = int(input())
num_list = sorted(map(int, input().split(' ')))
num_dict = {}
for idx in range(len(num_list)):
    num_dict[idx] = [False, str(num_list[idx])] # key: num의 index / value: 좋은 수 여부, num

for i in range(N):
    j = i+1
    while j < N:
        ij_sum = num_list[i] + num_list[j]
        for nd in num_dict:
            if int(num_dict[nd][1]) == ij_sum and nd!=j and nd!=i: 
                num_dict[nd][0] = True
        j+=1

cnt=0
for num in num_dict:
    if num_dict[num][0] == True:
        cnt+=1
print(cnt)
"""


import sys
input = sys.stdin.readline
N = int(input())
arr = list(map(int, input().split()))
arr.sort()

result = 0
for i, num in enumerate(arr):
    temp = arr[:i]+arr[i+1:]
    left, right = 0, len(temp)-1
    while left < right:
        if temp[left]+temp[right] > num:
            right -= 1
        elif temp[left]+temp[right] < num:
            left += 1
        else:
            result += 1
            break

print(result)
