from itertools import combinations as c
import sys
input = sys.stdin.readline

n = int(input().strip())
array = [i for i in range(n)]
matrix = []
for _ in range(n):
    matrix.append((list(map(int, input().strip().split()))))
result = int(1e9)
for r1 in c(array, n//2):
    start, link = 0, 0
    r2 = list(set(array) - set(r1))
    for r in c(r1, 2):
        start += matrix[r[0]][r[1]]
        start += matrix[r[1]][r[0]]
    for r in c(r2, 2):
        link += matrix[r[0]][r[1]]
        link += matrix[r[1]][r[0]]
    result = min(result, abs(start-link))
print(result)


# N = int(input().strip())
# S = []
# for i in range(N) :
#     S.append(list(map(int, input().strip().split(' '))))

# visited = [False] * N
# min_gap = 1000000

# def DFS(idx, depth) :
#     global min_gap
#     # print(str(idx).zfill(2), str(depth).zfill(2), visited, min_gap)
#     if depth == N//2 :
#         start_team, link_team = 0, 0
#         for i in range(N) :
#             for j in range(N) :
#                 if visited[i] and visited[j] :
#                     start_team += S[i][j]
#                 elif not visited[i] and not visited[j] :
#                     link_team += S[i][j]
#         min_gap = min(min_gap, abs(start_team - link_team))
#         return
#     for i in range(idx, N) :
#         if not visited[i] :
#             visited[i] = True
#             DFS(idx+1, depth+1)
#             visited[i] = False

# DFS(0,0)
# print(min_gap)