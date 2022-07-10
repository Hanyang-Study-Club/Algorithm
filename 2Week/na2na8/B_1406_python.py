import sys
input = sys.stdin.readline

cursor_left = list(input().strip('\n'))
cursor_right = []
M = int(input().strip('\n'))

for m in range(M) :
    command = input().strip('\n')
    if command == 'L' and cursor_left :
        cursor_right.append(cursor_left.pop())
    elif command == 'D' and cursor_right :
        cursor_left.append(cursor_right.pop())
    elif command == 'B' and cursor_left :
        cursor_left.pop()
    elif command[0] == 'P' :
        cursor_left.append(command[2])
cursor_right.reverse()
print(''.join(cursor_left)+''.join(cursor_right))