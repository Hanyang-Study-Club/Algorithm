# #!/usr/bin/env python
# # -*- coding: utf-8 -*-

# 시간초과
# import sys
# import sys
# # sys.setremid_idxsionlimit(2**(10**9))
# input = sys.stdin.readline

# """
# S(0) = "m o o"
# S(1) = "m o o m o o o m o o"
# S(2) = "m o o m o o o m o o m o o o o m o o m o o o m o o"
# S(k) = S(k-1) + o가 k+2개인 수열 mo...o + S(k-1)
# """

# N = 0
# idx = 0

# """
# 1. S(k-1)
# 2. 'm' + 'o'*(k+2)
# 3. S(k-1)
# "m o o m o o o m o o m o o o o m o o m o o o m o o"
# 1000000000
# """
# def moo(n):
#     global N
#     global idx
#     # print("n, N, idx", n, N, idx) 
    
#     if n == 1: # 입력이 1일 경우 
#         if idx+1 == N: # N번째 위치까지 idx++가 완료되었으면
#             print('m') # 입력이 1이므로 무조건 moo의 첫번째인 m 출력
#             exit(0)
#         elif idx+2 == N or idx+3 == N: 
#             print('o') # 입력이 1이므로 무조건 moo의 두번째, 세번째인 d 출력
#             exit(0)
#         idx += 3 # 입력이 1일경우 무조건 moo이기 때문에 인덱스를 한꺼번에 3개 +
#         return 0

#     moo(n-1) # 1. 재귀

#     # 2. 'm' + (k+2) * 'o'를 수행하는 부분
#     if idx+1 == N: # N번째 위치까지 idx++가 완료되었으면 (일단 위에서 moo 까지는 계산이 완료되었으므로)
#         print('m') # 다시 m부터 시작
#         exit(0)
#     idx += 1
#     for i in range(n+1): # 그다음 n개만큼 o 가 붙음
#         if idx+1 == N:
#             print('o')
#             exit(0)
#         idx += 1

#     moo(n-1) # 3. 재귀

# N = int(input())
# moo(30)



#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 1. moo(k-1)
# 2. 'm' + 'o'*(k+2)
# 3. moo(k-1)
N = int(input()) # 찾고자 하는 인덱스 위치

def moo(total_idx, mid_idx, N):
    prev = (total_idx-mid_idx)//2 # (총길이 - 가운데 moooo...ooo 길이)//2 -> moo(n-1)부분의 길이
    if N <= prev: return moo(prev, mid_idx-1, N) # moo(n-1)에서 찾고자 하는 인덱스 위치까지 재귀 (왼쪽 moo(n-1)에서 찾는게 가능한 경우)
    elif N > prev+mid_idx: 
        # 왼쪽 moo(n-1)길이 + 가운데m oooo...ooo 길이가 찾고자하는 인덱스 위치보다 작으면,
        # 즉 오른쪽 moo(n-1)에 찾고자 하는 인덱스가 있다면 왼쪽 moo(n-1)에서 찾는 것과 같은 효과를 주도록
        # 찾고자 하는 인덱스를 N-왼쪽길이-중간길이 로 조정해서 재귀를 돌림 (오른쪽 moo(n-1)에서 찾는게 가능한 경우)
        return moo(prev, mid_idx-1, N-prev-mid_idx) 
    else: 
        # (가운데 moooo....ooo에서 찾아야 하는 경우)
        if N-prev-1 == 0: # 찾고자 하는 인덱스 위치 - 왼쪽 길이 - 1가 0이면 첫번째 자리이므로 m 리턴
            return 'm'
        else: # 그다음부턴 쭉 o만 나오므로 o 리턴
            return 'o'

total_idx, n = 3, 0 # 전체 문자열 길이를 나타내는 인덱스 total_idx는 초기 moo로부터 시작하므로 3(S(0) = "m o o" ), n 0으로 초기화
while N > total_idx:
    n += 1
    total_idx = (total_idx*2) + (n+3) # moo 수열의 총 길이(누적 문자열 인덱스)
    # total_idx*2 -> moo(k-1) 두개 분량의 길이 
    # n+3 -> moo(1)일때 mooo(길이: 1+3), S(2)일때 moooo(길이: 2+3), ...

# n+3이 초기값 인덱스 길이(moo)
print(moo(total_idx, n+3, N))