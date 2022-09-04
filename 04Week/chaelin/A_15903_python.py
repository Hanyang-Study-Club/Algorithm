#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from queue import PriorityQueue
input = sys.stdin.readline

n, m = map(int, input().strip().split(' ')) # n: 카드수 / m: 합치기 수행 횟수
init_card = list(map(int, input().strip().split(' ')))
que = PriorityQueue(maxsize=n)

for init_num in init_card:
    que.put(init_num) # 우선순위큐

for i in range(m):
    x = que.get() # 젤 작은거 두개 빼서
    y = que.get()
    sum_num = x+y # 더하고
    que.put(sum_num) # 두개만큼 덮어쓰기
    que.put(sum_num)

print(sum(que.queue))
