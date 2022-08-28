import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

def S(k) :
    global tot_len
    global N
    moo = 3 + k
    prev = (tot_len - moo)//2
    tot_len = prev
    if 1 <= N - prev <= 3+k :
        return 'm' if N - prev == 1 else 'o'
    elif N - prev < 0 :
        return S(k-1)
    else :
        N = N - (prev + moo)
        return S(k-1)
    
if __name__ == "__main__" :
    N = int(input().rstrip())
    tot_len = 3
    k = 0
    while N > tot_len :
        k += 1
        tot_len = 2 * tot_len + k + 3
    print(S(k))