import sys
input = sys.stdin.readline

from queue import PriorityQueue
# M : 콘센트 개수
N, M = map(int, input().strip().split(' '))

t = sorted(list(map(int, input().strip().split(' '))))

outlet = PriorityQueue(maxsize=M)
for _ in range(M) :
    outlet.put(0)

while t :
    # 콘센트 개수만큼 t에서 get + outlet에서 get 하면서 다시 outlet에 넣어주기
    for _ in range(M) :
        if not t :
            break
        outlet.put(outlet.get() + t.pop())

result = []
while not outlet.empty() :
    result.append(outlet.get())

print(max(result))