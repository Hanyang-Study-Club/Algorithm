#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000) # 재귀 리미트 안풀어주면 런타임 에러남

def dfs(y, x, cnt, d):
    graph[y][x] = 1 # 방문 여부 True로 변경
    for dy, dx in d:
        Y = y + dy
        X = x + dx
        if (0 <= Y < M) and (0 <= X < N) and graph[Y][X] == 0:
            cnt = dfs(Y, X, cnt+1, d)
    return cnt

if __name__ == "__main__": 
    M, N, K = map(int, input().split()) # M: x축 길이, N: y축 길이, K: 직사각형 좌표 갯수
    graph = [[0]*N for _ in range(M)]
    for _ in range(K): # K개의 직사각형 좌표 받기
        x1, y1, x2, y2 = map(int, input().split())
        for i in range(y1, y2): # 좌표 안의 사각형은 1로 색 칠하기
            for j in range(x1, x2):
                graph[i][j] = 1
    d = [(-1, 0), (1, 0), (0, -1), (0, 1)] # A번 그래프 문제와는 달리 동서남북 사방면을 탐색해줘야 함
    answer = []
    for i in range(M): # x축 길이
        for j in range(N): # y축 길이
            if graph[i][j] == 0: # 그래프에 0, 즉 색이 칠해지지 않는 부분이면 dfs
                answer.append(dfs(i, j, 1, d))
    # print("answer: ", answer)
    print(len(answer)) # 영역의 갯수
    print(*sorted(answer)) # 영역 오름차순으로 정렬