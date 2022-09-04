#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from queue import PriorityQueue
import heapq
input = sys.stdin.readline

T = int(input()) # 테스트케이스 개수

def get_median_idx(data): # 중앙값 구하는 함수. numpy로 median구하는걸 백준에서 막아놨음.ㅗㅗ
    data = sorted(data)
    centerIndex = len(data)//2
    return int((data[centerIndex ] + data[-centerIndex - 1])/2)

for _ in range(T):
    M = int(input()) # 수열의 크기
    M_list = []
    while len(M_list) < M:
        M_list+=(list(map(int, input().strip().split()))) # 수열 10개씩 잘라서 들어오는거 하나로 붙여줌
    odd_M_list = []
    
    for i in range(len(M_list)):
        if i%2 == 0: 
            mid_idx = 0
            odd_M_list.append(get_median_idx(M_list[:i+1])) # 지금까지 받은것중에서 중앙값 구하기
    median_answer = len(odd_M_list) # 구한 중앙값들 개수
    
    tmp_str = ""
    print(median_answer, end='') # 엔터 공백 나오면 안되기때문에..
    for i in range(len(odd_M_list)): # 출력도 10개씩 끊어서 해주기
        if (i)%10 != 0 : 
            tmp_str+= str(odd_M_list[i]) + ' '
        else:
            print(tmp_str)
            tmp_str = ""
            tmp_str+= str(odd_M_list[i]) + ' '
        if i == len(odd_M_list)-1:
            print(tmp_str)