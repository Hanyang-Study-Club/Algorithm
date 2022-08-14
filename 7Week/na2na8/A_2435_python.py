import sys
input = sys.stdin.readline

if __name__ == "__main__" :
    N, K = map(int, input().strip().split(' '))
    temp = list(map(int, input().strip().split(' ')))

    max_sum = sum(temp[0:K])
    sub_sum = max_sum
    first_day = 0

    for day in range(K, len(temp)) :
        sub_sum = sub_sum + temp[day] - temp[first_day]
        max_sum = sub_sum if sub_sum > max_sum else max_sum
        first_day += 1
    print(max_sum)
