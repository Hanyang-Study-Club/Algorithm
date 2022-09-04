import sys

input = sys.stdin.readline

def integral(a, b, coeffs, K) :
    integral_sum = 0.0
    for idx, c_i in enumerate(coeffs) :
        degree = K - idx
        integral_sum += (b**(degree+1) - a**(degree+1))/(degree+1) * c_i
    return integral_sum

def f(coeffs, K, x) :
    f_sum = 0.0
    for idx, c_i in enumerate(coeffs) :
        f_sum += float(c_i) * x**(K - idx)
    return f_sum

def approximate(a, b, N, coeffs, K, integral_sum) :
    delta = (b-a)/N
    crit_left = 0.0
    crit_right = delta
    while crit_left <= crit_right :
        epsilon = (crit_left + crit_right)/2
        apprx = 0.0
        for k in range(N) :
            apprx += f(coeffs, K, a+ k*delta + epsilon) * delta
        if abs(integral_sum - apprx) <= 0.0001 : break
        else :
            if integral_sum > apprx : crit_left = epsilon
            else : crit_right = epsilon
    return round(epsilon,6)

if __name__ == "__main__" :
    K = int(input().rstrip())
    coeffs = list(map(int, input().rstrip().split(' ')))
    a, b, N = list(map(int, input().rstrip().split(' ')))
    integral_sum = integral(a, b, coeffs, K)
    print(approximate(a, b, N, coeffs, K, integral_sum))

