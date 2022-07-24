import sys
input = sys.stdin.readline

from queue import PriorityQueue

n, m = map(int, input().strip().split(' '))
cards = PriorityQueue(maxsize=n)
# 우선순위 큐 넣기
for card in list(map(int, input().strip().split(' '))) :
    cards.put(card)

# m번의 놀이
for _ in range(m) :
    # 두 번 빼서 합 구하기
    card1 = cards.get()
    card2 = cards.get()
    sum_ = card1 + card2
    cards.put(sum_)
    cards.put(sum_)

total = 0
while not cards.empty() :
    total += cards.get()

print(total)