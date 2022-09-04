N = int(input())
numbers = sorted(list(map(int, input().split(' '))))
answer = 0

for k in range(N) :
    good = numbers[k]
    p1, p2 = 0, N-1
    while p1 < p2 :
        if p1 == k :
            p1 += 1
            continue
        elif p2 == k :
            p2 -= 1
            continue
        sum_ = numbers[p1] + numbers[p2]
        if sum_ == good :
            answer += 1
            break
        if sum_ < good :
            p1 += 1
        elif sum_> good :
            p2 -= 1

print(answer)
