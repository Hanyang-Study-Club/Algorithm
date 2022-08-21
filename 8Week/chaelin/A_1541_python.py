#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

exp = input().strip().split('-') # 55, 50+40

# 최초로 마이너스가 나오기 전까지 나오는 숫자는 모두 더할 수 밖에 없음
# 이후 마이너스가 나오는 순간 그 뒤에 있는 모든 수들을 빼주면 됨
answer = 0
idx=0
for e in exp:
    tmp_exp = e.split('+') # 1: 55 / 2: 50, 40
    # print(tmp_exp)
    for tmp_e in tmp_exp:
        if idx == 0: # 맨 첫번째 인덱스, 예시로 여기에서 55이면 일단 더해줌
            answer += int(tmp_e)
        else: # 맨 첫번째 인덱스인 55외에는 [50,40]이 +로 묶인 리스트로 들어오기때문에 모두 빼줌
            answer -= int(tmp_e)
    idx+=1

# 55-50+40
print(answer)