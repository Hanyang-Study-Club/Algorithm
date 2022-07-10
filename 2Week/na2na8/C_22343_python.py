import sys
input = sys.stdin.readline

def f(bracket, m) :
    vector = [0 for i in range(m+1)]
    cursor = 0
    for i, b in enumerate(bracket) :
        if b == '(' :
            cursor += 1
        else :
            cursor -= 1
            if bracket[i-1] == '(' :
                vector[cursor] += 1
    for i in range(len(vector)-1) :
        vector[i+1] += vector[i]//2
        vector[i] = vector[i]%2
    return vector

def compare(vector1, vector2) :
    len_vector = len(vector1)
    for i in range(len_vector) :
        if vector1[len_vector-i-1] < vector2[len_vector-i-1] :
            return '<'
        elif vector1[len_vector-i-1] > vector2[len_vector-i-1] :
            return '>'

    return '='

# def f(bracket) :
#     l_bracket = []
#     for i, b in enumerate(bracket) :
#         if l_bracket :
#             if len(l_bracket) >= 2 :
#                 if type(l_bracket[-1]) == int and type(l_bracket[-2]) == int :
#                     l_bracket.append(l_bracket.pop() + l_bracket.pop())
#             if l_bracket[-1] == '(' and b == ')' :
#                 l_bracket.pop()
#                 l_bracket.append(1)
#                 continue
#             elif type(l_bracket[-1]) == int and b == ')' :
#                 item = l_bracket.pop()
#                 # 괄호 제거
#                 l_bracket.pop()
#                 l_bracket.append(2*item)
#                 continue
#         l_bracket.append(b)
#     return sum(l_bracket)
            


T = int(input().strip())
ans = []
for t in range(T) :
    A = input().strip()
    B = input().strip()
    m = max(len(A), len(B))//2
    vector_a = f(A, m)
    vector_b = f(B, m)
    print(compare(vector_a, vector_b))
    

