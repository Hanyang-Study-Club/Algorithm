import sys
input = sys.stdin.readline
from collections import deque, defaultdict

def BFS(graph, node, visited) :
    queue = deque([node])
    # 현재 노드 방문 처리
    visited[node] = True

    while queue :
        out = queue.popleft()
        for i in graph[out] :
            if not visited[i] :
                queue.append(i)
                visited[i] = True
    return graph, visited

if __name__ == "__main__" :
    N, M = map(int, input().rstrip().split(' '))
    if M == 0 :
        print(N)
        exit()
    # graph 생성
    graph = defaultdict(list)
    for _ in range(M) :
        u, v = map(int, input().rstrip().split(' '))
        graph[u].append(v)
        graph[v].append(u)
    
    # visited 생성
    visited = {}
    for key in graph.keys() :
        visited[key] = False
    
    ans = 0
    node = list(graph.keys())[0]
    while False in visited.values() :
        ans += 1
        graph, visited = BFS(graph, node, visited)
        candidates = list(filter(lambda vertex : visited[vertex] == False, visited))
        if candidates :
            node = candidates[0]
    print(ans + N - len(visited))    