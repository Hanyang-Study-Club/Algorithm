import sys
input = sys.stdin.readline
import heapq

if __name__ == "__main__" :
    N, D = map(int, input().rstrip().split(' '))
    
    graph = [[] for _ in range(D+1)]
    for i in range(D) :
        graph[i].append((i+1, 1))

    for i in range(N) :
        start, end, distance = map(int, input().rstrip().split(' '))
        if end > D : continue
        graph[start].append((end, distance))
    INF = 1e9
    distances = [INF] * (D+1)
    distances[0] = 0

    queue = []
    heapq.heappush(queue, (0, 0)) # (distance, start)
    while queue :
        distance, now = heapq.heappop(queue)
        if distances[now] < distance : continue

        for shortcut in graph[now] :
            cost = distance + shortcut[1]
            if distances[shortcut[0]] > cost :
                distances[shortcut[0]] = cost
                heapq.heappush(queue, (cost, shortcut[0]))
    print(distances[D])

        
