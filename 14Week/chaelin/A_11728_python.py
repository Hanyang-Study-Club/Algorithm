#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

N, M = map(int, input().split())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

print(*sorted(A+B)) # 배열 합쳐서 소팅...