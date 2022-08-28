import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

def pooling(r, c, size) :
    global matrix
    mid = size//2
    if size == 2 :
        answer = sorted([matrix[r][c], matrix[r][c+1], matrix[r+1][c], matrix[r+1][c+1]])
        return answer[2]
    left_top = pooling(r, c, mid)
    right_top = pooling(r, c+mid, mid)
    left_bottom = pooling(r+mid, c, mid)
    right_bottom = pooling(r+mid, c+mid, mid)
    answer = sorted([left_top, right_top, left_bottom, right_bottom])
    return answer[2]

if __name__ == "__main__" :
    N = int(input().rstrip())
    matrix = []
    for _ in range(N) :
        matrix.append(list(map(int, input().rstrip().split(' '))))
    print(pooling(0, 0, N))