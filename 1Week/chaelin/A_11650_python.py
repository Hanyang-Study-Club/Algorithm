#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

n = int(input())

arr = []
for i in range(n):
    a, b = map(int, input().split(' '))
    arr.append([a, b]) # [[1, 1], [2, 2]]
    
def quick_sort(arr):
    if len(arr) <= 1: return arr # arr에 하나 남을때까지 재귀 반복
    pivot = arr[len(arr) // 2] # 피봇은 arr 중앙값으로 설정
    lesser_arr, equal_arr, greater_arr = [], [], [] # 피봇보다 작은거/같은거/큰거
    for num in arr:
        print("@@", num, pivot, arr)
        if num < pivot:
            lesser_arr.append(num) # 피봇보다 작으면 피봇보다 작은값 리스트에 넣기
        elif num > pivot:
            greater_arr.append(num) # 피봇보다 크면 피봇보다 큰값 리스트에 넣기
        else:
            equal_arr.append(num) # 피봇과 같으면 피봇과 같은값 리스트에 넣기
    return quick_sort(lesser_arr) + equal_arr + quick_sort(greater_arr) # 작은거+같은거+큰거 순서대로 리스트 조율해서 재귀

s_arr = quick_sort(arr)

for s in s_arr:
  print('{} {}'.format(s[0], s[1]))

# 참고
# import numpy
# a = numpy.array([1,2])
# b = numpy.array([1,1])