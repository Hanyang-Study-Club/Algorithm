#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

K = int(input())
c_i = list(map(int, input().split()))
a, b, N = map(int, input().split())

def integral(a, b, n, c):
    return ((b**(n+1) - a**(n+1))/(n+1))*c
def calc_integral():
    tmp_K = K
    integral_ans = 0
    for c in c_i:
        integral_ans += integral(a, b, tmp_K, c)
        tmp_K-=1
    return integral_ans

integral_answer = calc_integral()

def calc_exp(c_i, K, xx):
    ans = 0.0
    for c in c_i:
        ans += c * (xx ** K)
        K -= 1
    return ans
def sigma(c_i, a, b, K, N, epsilon):
    ans = 0.0
    for k in range(0, N):
        delta_x = (b - a) / N
        xx = a + k * delta_x + epsilon
        ans += calc_exp(c_i, K, xx) * delta_x
    return ans

def find_epsilon(integral_answer, left, right) : # 이분탐색
    mid = (left+right)/2 # 중간 인덱스
    sigma_ans = sigma(c_i, a, b, K, N, mid)
    if left > right: return -1
    abs_error = abs(integral_answer - sigma_ans)
    rel_error = abs_error / sigma_ans
    if abs_error < 0.0001 or rel_error < 0.0001: return mid # 중간값보다 타겟이 같으면 해당 중간값 인덱스 반환
    elif sigma_ans > integral_answer : # 중간값보다 타겟이 작으면 왼쪽 부분만 비교
        return find_epsilon(integral_answer, left, mid-0.000001)
    else : # 중간값보다 타겟이 같거나 크면 오른쪽 부분만 비교
        return find_epsilon(integral_answer, mid+0.000001, right)

epsilon = find_epsilon(integral_answer, 0, (b - a) / N)
print(epsilon)


"""
1
1 0
0 1 2

s_0_1 1x + 0 
"""