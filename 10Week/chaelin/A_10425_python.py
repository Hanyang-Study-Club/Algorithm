#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

fibo = [0, 1] # 피보나치 초기값 저장
for i in range(100000) : # 문제 조건에서 최대 100000번째 피보나치 수까지 계산 가능하므로
    fibo.append(fibo[-1]+fibo[-2]) # 피보나치 값 찾아서 저장

def find(fibo, val, left, right) : # 이분탐색
    mid = (left+right)//2 # 중간 인덱스
    if fibo[mid] == val : return mid # 중간값보다 타겟이 같으면 해당 중간값 인덱스 반환
    elif fibo[mid] > val : # 중간값보다 타겟이 작으면 왼쪽 부분만 비교
        return find(fibo, val, left, mid)
    else : # 중간값보다 타겟이 같거나 크면 오른쪽 부분만 비교
        return find(fibo, val, mid, right)

T = int(input()) # 테스트케이스 수
for i in range(T) :
    f = int(input())
    if f == 0 : print(0) # 피보나치 수가 0인건 무조건 0번째
    if f == 1 : print(2) # 피보나치 수가 1인건 첫번째 혹은 두번째 -> 가장 큰 인덱스인 2 출력
    else :
        print(find(fibo, f, 0, len(fibo)-1)) # 문제 조건에서 최대 100000번째 피보나치 수까지 계산 가능하므로