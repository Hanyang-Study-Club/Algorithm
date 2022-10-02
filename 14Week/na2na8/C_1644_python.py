import sys
input = sys.stdin.readline

def get_prime(n) :
    is_prime = [True] * (n + 1)
    is_prime[0], is_prime[1] = False, False
    primes = []
    for i in range(2 ,n + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(2 * i, n + 1, i):
                is_prime[j] = False
    return primes

def get_cases(primes) :
    pass               
if __name__ == "__main__" :
    N = int(input().rstrip())
    primes = get_prime(N)
    print(primes)