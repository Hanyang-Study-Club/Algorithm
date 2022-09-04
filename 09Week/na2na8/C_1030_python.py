import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

def fractal(r, c, s) :
    global N
    global K
    if s == 0 :
        return '0'
    prev_len = N**(s-1)
    pad = int(N/2 - K/2)
    # black
    span1, span2 = prev_len * pad, prev_len * (N-pad)
    if span1 <= r < span2 and span1 <= c < span2 :
        return '1'
    r, c = r % prev_len, c % prev_len
    return fractal(r, c, s-1)

if __name__ == "__main__" :
    s, N, K, r1, r2, c1, c2 = map(int, input().rstrip().split(' '))
    for r in range(r1, r2 + 1) :
        row = ''
        for c in range(c1, c2 + 1) :
            row += fractal(r, c, s)
        print(row)
    