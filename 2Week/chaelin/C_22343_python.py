#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

T = int(input()) # 테스트 케이스 개수

symbol_list = []

counter = 0
for _ in range(T*2):
    symbol_list.append(input().strip())

a=0
b=0
a_finish = False
b_finish = False
max_length=0
counter = 0
for symbol_idx in range(len(symbol_list)):
    depth = 0
    binary_num = [0] * (max( len(symbol_list[counter]), len(symbol_list[counter + 1])) // 2 + 1)
    for c_idx in range(len(symbol_list[symbol_idx])):
        if symbol_list[symbol_idx][c_idx] == '(': # 여는 괄호이면
            depth += 1
        elif symbol_list[symbol_idx][c_idx] == ')': # 닫는 괄호이면
            depth -= 1
            if symbol_list[symbol_idx][c_idx-1] == '(':
                binary_num[depth] += 1
    for binary_idx in range(len(binary_num)-1):
        binary_num[binary_idx+1] += binary_num[binary_idx]//2
        binary_num[binary_idx]%=2 
        
    if symbol_idx%2==0:
        a = binary_num
        a_finish = True
    if symbol_idx%2!=0:
        b = binary_num
        b_finish = True
    if a_finish and b_finish:
        a_idx = len(a)-1
        while a_idx >= 0:
            if a[a_idx] > b[a_idx]: 
                print(">")
                break
            if a[a_idx] < b[a_idx]: 
                print("<")
                break
            a_idx -=1 
        else: 
            print("=")
        a_finish = False
        b_finish = False
        counter += 2