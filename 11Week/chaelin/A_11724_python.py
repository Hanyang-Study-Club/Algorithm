#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000) # 재귀 리미트 안풀어주면 런타임 에러남
N, M = map(int, input().split()) # N: 정점, M: 간선

def dfs(v, visited):
    visited[v] = True # 방문 여부 True로 변경
    for i in graph[v]:
        if not visited[i]: # i번째 노드가 아직 방문한적이 없으면 dfs
            dfs(i, visited)
    return visited

if __name__ == "__main__":
    graph = [[] for _ in range(N+1)]
    for _ in range(M):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)

    visited = [[] for _ in range(N+1)] # 방문한 노드를 넣어줄 리스트
    is_visit = [False]*(N+1) # 방문 여부를 표시할 리스트 
    visit_idx = 0

    cnt = 0
    for i in range(1, N+1):
        if not visited[i]: # i번째 노드가 아직 방문한적이 없으면 dfs
            dfs(i, visited)
            cnt += 1 # 한번 dfs가 끌나서 더이상 간선으로 이어지지 않는 연결 묶음이 생길 때마다 cnt += 1
    print(cnt)


"""
6 5
1 2
2 5
5 1
3 4
4 6

2
"""