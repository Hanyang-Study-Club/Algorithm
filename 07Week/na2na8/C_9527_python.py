import sys
import math
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

def f(x) :
    if x <= 0 :
        return 0
    jegob = int(math.log2(x))
    two_jegob = 2 ** jegob
    if x == two_jegob :
        return jegob * two_jegob // 2 + 1
    diff = x - two_jegob
    return f(two_jegob) + diff + f(diff)


if __name__ == "__main__" :
    A, B = map(int, input().rstrip().split(' '))
    print(f(B) - f(A-1))

# def f(x) :
#     jegob = int(math.log2(x))
#     two_jegob = 2**(jegob+1)
#     if x == two_jegob-1 :
#         return (jegob+1) * two_jegob // 2
#     elif x == two_jegob//2 :
#         return f(x-1) + 1
#     diff = x - two_jegob//2
#     return f(two_jegob//2) + diff +  f(diff)