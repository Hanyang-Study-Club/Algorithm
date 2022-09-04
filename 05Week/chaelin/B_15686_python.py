#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from itertools import combinations
input = sys.stdin.readline

N, M = map(int, input().split()) # N: 행 개수 / M: 치킨집 개수
city = []

for _ in range(N):
    city.append(list(map(int, input().split()))) # 0은 빈 칸, 1은 집, 2는 치킨집
# print(N, M, city)

chicken = [] # 치킨집 좌표 모음
house = [] # 집 좌표 모음 
for i in range(N):
    for j in range(N): 
        if city[i][j] == 1: # 1이면 집
            house.append((i+1, j+1)) # 집의 좌표를 따로 받는다
        elif city[i][j] == 2: # 2면 치킨집
            chicken.append((i+1, j+1)) # 치킨집의 좌표를 따로 받는다
            
result = N*2 * len(house) # 문제 조건: 집의 개수는 2N개를 넘지 않음
for comb in list(combinations(chicken, M)): # 조합 써서 M개의 치킨집의 조합에 대해 치킨 거리 구하기
    dist = 0
    for a, b in house:
        # print(a,b)
        temp = N*2 # 최대거리
        # print(temp)
        for x, y in comb:
            temp = min(temp, abs(a-x) + abs(b-y)) # 치킨집좌표와 집 좌표 거리 비교
            # print(temp)
        dist += temp
    result = min(result, dist)
        
print(result)