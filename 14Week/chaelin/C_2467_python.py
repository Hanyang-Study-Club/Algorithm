#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
from itertools import combinations
input = sys.stdin.readline

# 메모리 초과
# if __name__ == "__main__":
#     N = int(input())
#     li = list(map(int, input().split()))
#     comb_li = list(combinations(li, 2))
#     answer_idx = [comb_li[0][0], comb_li[0][1]]
#     answer_abs = abs(sum(comb_li[0]))
#     for c in comb_li[1:]:
#         tmp = abs(sum(c))
#         if tmp < answer_abs:
#             answer_abs = tmp
#             answer_idx[0] = c[0]
#             answer_idx[1] = c[1]
#     print(*answer_idx)

def twopointer(left_idx, right_idx, li):
    ans = abs(li[left_idx] + li[right_idx])
    ans_left = left_idx # 0, 맨 처음값
    ans_right = right_idx # n-1, 맨 마지막 값

    while left_idx < right_idx:
        tmp = li[left_idx] + li[right_idx]

        if abs(tmp) < ans: # 절대값이 제일 작은것을 계속 저장
            ans_left = left_idx
            ans_right = right_idx
            ans = abs(tmp)

            if ans == 0: break

        # 각 포인터갸 움직여야 할 상황: 두 포인터가 가르키는 값을 더한 값이 0보다 크냐/작냐
        if tmp < 0: left_idx += 1 # 작으면 더한 값을 증가시키기 위해 왼쪽을 += 1 (오름차순이므로)
        else: right_idx -= 1 # 크면 더한 값을 감소시키기 위해 오른쪽을 -= 1 (오름차순이므로)

    return ans_left, ans_right

if __name__ == "__main__":
    n = int(input())
    li = list(map(int, input().split()))

    left_idx = 0
    right_idx = n-1
    ans_left, ans_right = twopointer(left_idx, right_idx, li)

    print (li[ans_left], li[ans_right])
