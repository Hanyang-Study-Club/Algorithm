import sys
input = sys.stdin.readline

if __name__ == "__main__" :
    N, M = map(int, input().strip().split(' '))
    mat = [[0]*(N+1)]
    for _ in range(N) :
        mat.append([0] + list(map(int, input().strip().split(' '))))

    for r in range(1, N+1) :
        for c in range(1, N+1) :
            mat[r][c] = mat[r][c-1] + mat[r][c]
    for c in range(1, N+1) :
        for r in range(1, N+1) :
            mat[r][c] = mat[r-1][c] + mat[r][c]
    for _ in range(M) :
        x1, y1, x2, y2 = map(int, input().strip().split(' '))
        print(mat[x2][y2] - mat[x2][y1-1] - mat[x1-1][y2] + mat[x1-1][y1-1])