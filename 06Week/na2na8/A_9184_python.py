import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

def w(a, b, c) :
    global memory
    if a <= 0 or b <= 0 or c <= 0 :
        return 1
    if a > 20 or b > 20 or c > 20 :
        return w(20, 20, 20)
    if (a, b, c) in memory :
        return memory[(a, b, c)]
    if a < b and b < c :
        memory[(a, b, c)] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
        return memory[(a, b, c)]
    else :
        memory[(a, b, c)] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
        return memory[(a, b, c)]

if __name__ == "__main__" :
    memory = {}

    while True :
        a, b, c = map(int, input().strip().split(' '))
        if a == -1 and b == -1 and c == -1 :
            break
        print(f'w({a}, {b}, {c}) = {w(a, b, c)}')