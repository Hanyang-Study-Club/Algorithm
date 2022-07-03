#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

num_cnt, num_idx = map(int, input().split(' '))
num_list = sorted(map(int, input().split(' ')))
print(num_list[num_idx-1]) # 리스트의 인덱스 접근 시간복잡도는 O(1)임
