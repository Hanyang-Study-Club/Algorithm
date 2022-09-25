import sys
input = sys.stdin.readline

def DFS(graph) :
    visited = []
    cnt = 0
    stack = [0]
    while stack :
        country = stack.pop()
        if country not in visited :
            visited.append(country)
            cnt += 1
            temp = list(set(graph[country])-set(visited))
            stack += temp
    return cnt-1
    
if __name__ == "__main__" :
    T = int(input().rstrip())
    for t in range(T) :
        N, M = map(int, input().rstrip().split(' '))
        graph = [[] for n in range(N)]
        for m in range(M) :
            a, b = map(int, input().rstrip().split(' '))
            graph[a-1].append(b-1)
            graph[b-1].append(a-1)
        print(DFS(graph))