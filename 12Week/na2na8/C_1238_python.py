import sys
input = sys.stdin.readline
import heapq

def dijkstra(graph, start, end, N) :
    distances = [1e9] * N
    distances[start] = 0

    queue = []
    heapq.heappush(queue, (0, start))
    while queue :
        distance, now = heapq.heappop(queue)
        if distances[now] < distance : continue

        for path in graph[now] :
            cost = distance + path[1]
            if distances[path[0]] > cost :
                distances[path[0]] = cost
                heapq.heappush(queue, (cost, path[0]))
    return distances[end]

if __name__ == "__main__" :
    N, M, X = map(int, input().rstrip().split(' '))
    graph = [[] for _ in range(N)]
    for _ in range(M) :
        start, end, time = map(int, input().rstrip().split(' '))
        graph[start-1].append((end-1, time))
    
    result = 0
    for n in range(N) :
        if n == (X-1) : continue
        go = dijkstra(graph, n, X-1, N)
        back = dijkstra(graph, X-1, n, N)
        result = max(result, go+back)
        
    print(result)