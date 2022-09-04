from itertools import combinations

N = int(input())
cards = list(map(int, input().strip().split(' ')))
total = sum(cards)
sums = set([])
for i in range(1,N+1) :
    for c in list(combinations(cards, i)) :
        sums.add(sum(c))
print(total-len(sums))
