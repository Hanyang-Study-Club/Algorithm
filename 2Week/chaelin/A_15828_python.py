#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

N = int(input())

buffer = [] # 큐
packet = None 
while packet != -1: # -1이 들어올때까지 패킷 입력 받음
    packet = int(input())
    if len(buffer) < N and packet != 0 and packet != -1: buffer.append(packet) # 버퍼 사이즈가 N미만이고 패킷이 0, -1이 아니면 버퍼에 추가
    if packet == 0: buffer.pop(0) # 패킷이 0이면 큐 맨 앞에서부터 팝
    if packet == -1: break # 패킷이 -1이면 종료

if len(buffer) == 0: print("empty") # 버퍼 길이 0이면 empty 출력
else: print(*buffer) # 버퍼 길이가 0보다 크면 버퍼 리스트 언패킹해서 출력