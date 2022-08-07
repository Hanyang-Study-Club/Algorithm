import sys
input = sys.stdin.readline

if __name__ == "__main__" :
    n, k = map(int, input().strip().split(' '))
    coins = []
    for _ in range(n) :
        coins.append(int(input().strip()))
    
    DP = [0] * (k+1)
    DP[0] = 1
    for coin in coins :
        for mini_sum in range(coin, k+1) :
            if mini_sum - coin >= 0 :
                DP[mini_sum] += DP[mini_sum - coin]
    print(DP[k])