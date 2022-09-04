import sys
input = sys.stdin.readline

import heapq

T = int(input().strip())

for t in range(T) :
    M = int(input().strip())
    seq = []
    for _ in range(M//10+1) :
        seq += list(map(int, input().strip().split(' ')))
    
    median = []
    mini_seq = []
    for i, s in enumerate(seq) :
        heapq.heappush(mini_seq, s)
        temp = [s for s in mini_seq]
        if i % 2 == 0 :
            for _ in range(i//2 + 1) :
                last = heapq.heappop(temp)
            median.append(last)

    print(len(median))
    # rest = len(median)%10
    quotient = len(median)//10
    for d in range(quotient) :
        print(*median[d*10:(d+1)*10])
    print(*median[quotient*10:])