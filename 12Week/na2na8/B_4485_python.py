import sys
input = sys.stdin.readline
import heapq

def dijkstra(graph, N, dc, dr, num) :
    distances= [[1e9]*N for _ in range(N)]

    queue = []
    heapq.heappush(queue, (graph[0][0], 0, 0)) # cost, row, column
    distances[0][0] = 0

    while queue :
        cost, row, column = heapq.heappop(queue)
        if row == N - 1 and column == N - 1 :
            print(f'Problem {num}: {distances[row][column]}')
            break
        for i in range(4) :
            new_row = row + dr[i]
            new_column = column + dc[i]
            if 0 <= new_row < N and 0 <= new_column < N :
                new_cost = cost + graph[new_row][new_column]
                if new_cost < distances[new_row][new_column] :
                    distances[new_row][new_column] = new_cost
                    heapq.heappush(queue, (new_cost, new_row, new_column))
if __name__ == "__main__" :
    dc = [0, 0, -1, 1]
    dr = [-1, 1, 0, 0]
    num = 1
    while True:
        N = int(input().rstrip())
        if N == 0 : break
        graph = [list(map(int, input().rstrip().split(' '))) for _ in range(N)]
        dijkstra(graph, N, dc, dr, num)
        num += 1