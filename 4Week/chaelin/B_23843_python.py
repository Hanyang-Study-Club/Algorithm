#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from queue import PriorityQueue
import heapq
input = sys.stdin.readline

N, M = map(int, input().strip().split()) # N: 전자기기 / M: 콘센트수
time = list(map(int, input().strip().split())) # 기기별 충전하는데 걸리는 시간들
time.sort() # 정렬

heapq.heapify(time) # 우선순위 큐로 정렬된 리스트

max_time = 0
remain_time = 0
M_list = PriorityQueue(maxsize=M) # 콘센트 수만큼 우선순위 큐 생성

while time:
    if len(M_list.queue) < M: # 콘센트가 다 차지않으면 충전 넣기
        M_list.put(time.pop())
    else: # 콘센트가 다 차면 제일 작은거부터 빼서 그담에 넣는 충전시간 더해서 넣어주기
        tmp_time = M_list.get()
        input_time = time.pop()
        M_list.put(tmp_time + input_time)
print(max(M_list.queue)) # 제일 긴 충전시간 출력
    