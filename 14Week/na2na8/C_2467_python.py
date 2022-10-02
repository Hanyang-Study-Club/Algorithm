import sys
input = sys.stdin.readline

if __name__ == "__main__" :
    N = int(input().rstrip())
    solutions = list(map(int, input().rstrip().split(' ')))

    left, right = 0, N - 1
    min_sum = 1e10
    answer_L, answer_R = 0, N-1
    while left != right :
        sum_ = solutions[left] + solutions[right]
        if abs(sum_) <= min_sum :
            min_sum = abs(sum_)
            answer_L, answer_R = left, right
        if sum_ < 0 :
            left += 1
        else : right -= 1
    print(solutions[answer_L], solutions[answer_R])        

