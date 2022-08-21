# from collections import deque
from queue import PriorityQueue
import sys
input = sys.stdin.readline

if __name__ == "__main__" :
    N = int(input().rstrip())
    classes = sorted([list(map(int, input().rstrip().split(' '))) for _ in range(N)], key=lambda x: (x[0], x[1]))
    rooms = PriorityQueue()
    rooms.put(classes[0][1])
    for j in range(1, len(classes)) :
        # 먼저 room의 T_i 정보 확인
        T_i = rooms.get()
        S_j = classes[j][0]
        if T_i <= S_j :
            # T_j 넣기
            rooms.put(classes[j][1])
        else :
            rooms.put(T_i)
            # T_j 넣기
            rooms.put(classes[j][1])
    print(rooms.qsize())


# if __name__ == "__main__" :
#     N = int(input().rstrip())
#     classes = deque(sorted([list(map(int, input().strip().split(' '))) for _ in range(N)], key=lambda x : (x[1], x[0])))
#     occupied = deque([])
#     read = deque([])
#     ans = 0
#     while classes or read :
#         c = classes.popleft()
#         if not occupied :
#             occupied.append(c)
#             if classes :
#                 continue
#         elif occupied[len(occupied)-1][1] <= c[0] :
#             occupied.append(c)
#             if classes :
#                 continue
#         else :
#             read.append(c)
#         if not classes :
#             ans += 1
#             occupied = deque([])
#             classes = deque([_ for _ in read])
#             read = deque([])
        
#     print(ans)