import sys
input = sys.stdin.readline

def divide(num, arr) :
    minimum = maximum = arr[0]
    count = 1
    for idx in range(1, len(arr)) :
        maximum = max(arr[idx], maximum)
        minimum = min(arr[idx], minimum)
        if maximum - minimum > num :
            count += 1
            maximum = arr[idx]
            minimum = arr[idx]
    return count

if __name__ == "__main__" :
    N, M = map(int, input().rstrip().split(' '))
    arr = list(map(int, input().rstrip().split(' ')))
    small, big = 0, max(arr)
    ans = 0
    while small <= big :
        mid = (small + big)//2
        if divide(mid, arr) <= M :
            big = mid - 1
            ans = mid
        else :
            small = mid + 1

    print(ans)

