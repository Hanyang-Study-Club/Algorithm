#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

def dfs(v, visited):
    visited[v] = True # 방문 여부 True로 변경
    for i in graph[v]:
        if not visited[i]: # i번째 노드가 아직 방문한적이 없으면 dfs
            dfs(i, visited)
    return visited

if __name__ == "__main__":
    T = int(input()) # 테스트 케이스 수

    for _ in range(T):
        N, M = map(int, input().split()) # N: 국가의 수(정점), M: 비행기 종류(간선)

        graph = [[] for _ in range(N+1)]
        for _ in range(M):
            a, b = map(int, input().split())
            graph[a].append(a)
            graph[b].append(b)
        
        visited = [[] for _ in range(N+1)]
        is_visit = [False] * (N+1)
        visit_idx = 0

        cnt = 0
        for i in range(1, N+1):
            if not visited[i]:
                dfs(i, visited)
                cnt += 1
        print(cnt-1)
        # 노드가 N개인 트리는 항상 N-1개의 간선(edge)을 가진다.
        # 즉, 간선은 항상 (정점의 개수 - 1) 만큼을 가진다.

