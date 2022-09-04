# #!/usr/bin/env python
# # -*- coding: utf-8 -*-

# import sys
# input = sys.stdin.readline

# N = int(input())

# matrix = []
# for _ in range(N):
#     matrix.append(list(map(int, input().split())))
# print(matrix)

# idx=0
# sub_matrix = []
# for i in range(0, N, 2):
#     sub_matrix.append([])
#     for j in range(0, N, 2):
#         tmp_max = []
#         tmp_max.append(matrix[i][j])
#         tmp_max.append(matrix[i][j+1])
#         tmp_max.append(matrix[i+1][j])
#         tmp_max.append(matrix[i+1][j+1])
#         tmp_max.sort(reverse=True)
#         sub_matrix[idx].append(tmp_max[1])
#         # print("sub: ", tmp_max, sub_matrix)
#     idx+=1
# print("sub: ", sub_matrix)
# answer=sub_matrix[0]+sub_matrix[1]
# answer.sort(reverse=True)
# print(answer[1])




#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

N = int(input())

matrix = []
for _ in range(N):
    matrix.append(list(map(int, input().split())))

mat_len = len(matrix)
while(mat_len>1):
    for i in range(0, mat_len, 2):
        for j in range(0, mat_len, 2):
            tmp_max = []
            tmp_max.append(matrix[i][j])
            tmp_max.append(matrix[i][j+1])
            tmp_max.append(matrix[i+1][j])
            tmp_max.append(matrix[i+1][j+1])
            tmp_max.sort(reverse=True)
            matrix[i//2][j//2]=tmp_max[1]
    mat_len//=2

print(matrix[0][0])
