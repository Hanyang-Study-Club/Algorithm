#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

n = int(input()) # 축구를 하기 위해 모인 사람

score = []

for i in range(n):
    score.append(list(map(int, input().split()))) # 능력치 받아서 배열에 넣음

for i in range(len(score)):
    for j in range(len(score)):
        # print(i, j, score[i][j])
        # print(j, i, score[j][i])
        score[i][j] += score[j][i] # s_ij 합산한 값 먼저 계산

result = ""
start = [] # 스타트팀
link = [] # 링크팀
def dfs(index):
    global result
    if len(start) == n//2: # 선수는 무조건 짝수명이므로 한 팀에 선수가 n//2명이면 끝남
        link = [i for i in range(n) if i not in start] # start 팀에서 안 뽑힌 선수들로 link 선수 선발
       
        start_score = 0
        link_score = 0
        
        for i in range(n//2):
            for j in range(i+1,n//2):
                # print(i, j)
                start_score += score[start[i]][start[j]]
                link_score += score[link[i]][link[j]]
                # ij 조합끼리만 더해준다.
        
        temp = abs(start_score - link_score) # 절댓값으로 차를 구함
        
        if result == "":
            result = temp
        elif result > temp: # 차가 최소인 것을 찾아서 result에 넣어줌
            result = temp
        
        if result == 0:
            print(result)
            sys.exit()
            # 차가 0인 조합이 나오면 즉시 종료
        return
    
    for i in range(index,n):
        if i in start:
            continue
        start.append(i) # start에 한명씩 넣고 dfs 돌림
        dfs(i)
        start.pop()
        
dfs(0)
print(result)

"""
4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0

0, 5, 9, 6
9, 0, 6, 10
16, 7, 0, 7
9, 14, 12, 0
"""