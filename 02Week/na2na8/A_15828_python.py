import sys
input = sys.stdin.readline
# N
N = int(input())
buffer = []
while True :
    info = input().strip()
    if info == '-1' :
        break
    elif info == '0' :
        buffer.pop(0)
    elif len(buffer) < N :
        buffer.append(info)

if not buffer :
    print('empty')
else :
    print(' '.join(buffer))
