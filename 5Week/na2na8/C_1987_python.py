import sys
input = sys.stdin.readline

R, C = map(int, input().strip().split(' '))

board = []
for i in range(R) :
    board.append([char for char in input().strip()])
visited = set()

num_alphabets = 0
operate = [(-1, 0), (1, 0), (0, -1), (0, 1)] # 상 하 좌 우
def get_path(loc) :
    global num_alphabets
    true_nums = len(visited)
    if true_nums > num_alphabets :
        num_alphabets = true_nums
    for op_idx in range(4) :
        x, y = loc[0]+operate[op_idx][0], loc[1]+operate[op_idx][1]
        if x >= 0 and x < R and y >= 0 and y < C and board[x][y] not in visited :
            visited.add(board[x][y])
            get_path([x,y])
            visited.remove(board[x][y])

visited.add(board[0][0])
get_path([0, 0])
print(num_alphabets)