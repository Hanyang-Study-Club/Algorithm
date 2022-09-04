#!/usr/bin/env python
# -*- coding: utf-8 -*-

import string
import sys
input = sys.stdin.readline

"""
첫번째 시도: 인덱스로 추가/삭제
"""
string_line = list(str(input()))[:-1]
cmd_cnt = int(input())

cursor = len(string_line)
for _ in range(cmd_cnt):
    inputs = str(input()).split(' ')
    if len(inputs) > 1:
        cmd = inputs[0].strip()
        char = inputs[1].strip()
    else:
        cmd = inputs[0].strip()
        char = ""
    if cmd == 'L' and cursor != 0: 
        cursor -= 1 # 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
    if cmd == 'D' and cursor != len(string_line): cursor += 1 # 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
    if cmd == 'B' and cursor != 0: 
        # 커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
        # 삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
        del string_line[cursor-1]
        cursor -= 1
    if cmd == 'P': # $라는 문자를 커서 왼쪽에 추가함
        string_line.insert(cursor, char)
        cursor += 1
for i in range(len(string_line)):
    print(string_line[i], end='')


"""
두번째 시도: 링크드리스트
"""
class DList:
    class Node:
        def __init__(self, item, prev, link):  # 노드 생성자
            self.item = item  # 항목
            self.prev = prev  # 앞노드 레퍼런스
            self.next = link  # 뒤노드 레퍼런스

    def __init__(self):  # 이중 연결 리스트 생성자
        # head, tail, 항목수로 구성
        # 두 더미노드(head, tail)에는 실제 항목 저장하지 않음
        self.head = self.Node(None, None, None)
        self.tail = self.Node(None, self.head, None)
        self.head.next = self.tail
        self.cur = self.tail # 커서는 맨 끝에서 시작

    def insert_before(self, p, item):  # p가 가리키는 노드 앞에 새 노드를 삽입
        t = p.prev # p 앞의 기존 노드
        n = self.Node(item, t, p)  # 삽입할 노드
        p.prev = n  # 새 노드와 뒤 노드 연결
        t.next = n  # 새 노드와 앞 노드 연결

    def delete(self, x):  # 노드 x 삭제
        f = x.prev # x 앞의 기존 노드
        r = x.next # x 뒤의 기존 노드
        f.next = r  # x를 건너뛰고 x의 앞뒤 노드를 연결
        r.prev = f  # x를 건너뛰고 x의 앞뒤 노드를 연결
        return x.item

    def print_list(self):
        p = self.head.next
        while p != self.tail:
            if p.next != self.tail:
                print(p.item, end='')
            else:
                print(p.item)
            p = p.next  # 노드를 차례로 방문
    
# 입력받기
string_line = list(input().strip())
cmd_cnt = int(input())

l_list = DList()
for char in string_line:
    l_list.insert_before(l_list.tail, char) # 입력받은 문자열을 더블 링크드리스트로 만듦

# L: 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
# D: 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
# B: 커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
# P $: $라는 문자를 커서 왼쪽에 추가함

for _ in range(cmd_cnt):
    inputs = str(input()).split(' ')
    if len(inputs) > 1:
        cmd = inputs[0].strip()
        char = inputs[1].strip()
    else:
        cmd = inputs[0].strip()
        char = ""
    if cmd == 'L':
        if l_list.head != l_list.cur.prev: l_list.cur = l_list.cur.prev
    if cmd == 'D':
        if l_list.cur.next != None: l_list.cur = l_list.cur.next
    if cmd == 'B':
        if l_list.head != l_list.cur.prev != None: l_list.delete(l_list.cur.prev)
    if cmd == 'P':
        l_list.insert_before(l_list.cur, char)

l_list.print_list()