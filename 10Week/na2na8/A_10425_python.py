import sys
input = sys.stdin.readline

def make_fibonacci() :
    fibonacci = {}
    fibonacci[0] = 0
    fibonacci[1] = 1
    n_2 = 0
    n_1 = 1
    for n in range(2, 100001) :
        new = n_2 + n_1
        fibonacci[new] = n
        n_2 = n_1
        n_1 = new
    return fibonacci
        
if __name__ == "__main__" :
    T = int(input().rstrip())
    fibonacci = make_fibonacci()
    for t in range(T) :
        print(fibonacci[int(input().rstrip())])