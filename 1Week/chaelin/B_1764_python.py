#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

a, b = map(int, input().split(' '))

name_list1 = []
name_list2 = []

for a_idx in range(a):
    name = input().strip() # 개행 제거
    name_list1.append(name)
name_list1 = set(name_list1) # set으로 중복제거

for b_idx in range(b):
    name = input().strip() # 개행 제거
    name_list2.append(name)
name_list2 = set(name_list2) # set으로 중복제거

result = sorted(name_list1 & name_list2)  # 교집합 + 소트

print(len(result))
for name in result:
    print(name)
    