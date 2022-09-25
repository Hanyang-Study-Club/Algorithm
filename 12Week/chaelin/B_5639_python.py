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
    while True:
        pre = int(input())
        dfs()