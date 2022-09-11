import sys
input = sys.stdin.readline
from collections import deque

def BFS(matrix, node) :
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    cnt = 1

    matrix[node[1]][node[0]] = 1
    queue = deque([node])
    
    while queue :
        out = queue.popleft()
        for idx in range(4) :
            x = out[0] + dx[idx]
            y = out[1] + dy[idx]
            if 0 <= x < N and 0 <= y < M and matrix[y][x] == 0 :
                queue.append((x, y))
                matrix[y][x] = 1
                cnt += 1
    return cnt, matrix

if __name__ == "__main__" :
    M, N, K = map(int, input().rstrip().split(' '))
    matrix = [[0] * N for _ in range(M)]
    for _ in range(K) :
        lb_x, lb_y, rt_x, rt_y = map(int, input().rstrip().split(' '))
        for y in range(lb_y, rt_y) :
            for x in range(lb_x, rt_x) :
                matrix[y][x] = 1
    ans = []
    for y in range(M) :
        for x in range(N) :
            node = (x, y)
            if matrix[y][x] == 0 :
                cnt, matrix = BFS(matrix, node)
                ans.append(cnt)
    print(len(ans))
    print(*sorted(ans))
    