#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import heapq
input = sys.stdin.readline

N = int(input())

queue = []
for _ in range(N):
    S, T = map(int, input().split())
    queue.append([S, T])
queue.sort() # 시작시간이 빠른 순서대로 정렬

room = []

idx = 0
for q in queue:
    if idx == 0:
        heapq.heappush(room, queue[0][1]) # 첫번째 넣어놓고 시작
    else:
        if room[0] > q[0]: # 현재 강의 끝나는 시간이 다른 강의 시작하는 시간보다 늦으면
            heapq.heappush(room, q[1]) # 다른 강의실에서 강의를 진행해야함
        else: # 아니면 이전강의에 이어서 같은 강의실에서 강의 진행 가능
            heapq.heappop(room) # 기존 강의 끝나는 시간을 팝하고
            heapq.heappush(room, q[1]) # 새로 이어서 하는 강의의 끝나는 시간을 푸시
    idx += 1
    
print(len(room))
"""
3
1 3
2 4
3 5

2
1 6
2 9
"""