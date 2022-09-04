import sys
input = sys.stdin.readline

def preprocess(formula) :
    numbers = []
    init_number = ''
    
    op_idx = 0
    
    first = -1
    # span = []
    minus_idx = []
    for item in formula :
        if item == '+' or item == '-' :
            numbers.append(int(init_number))
            init_number = ''
            if item == '-' :
                if first != -1 :
                    # span.append((first+1, op_idx+1))
                    for i in range(first+1, op_idx+1) :
                        minus_idx.append(i)
                first = op_idx
            op_idx += 1
        else :
            init_number += item
    if init_number :
        numbers.append(int(init_number))
    if first != -1 :
        # span.append((first+1, len(numbers)))
        for i in range(first+1, len(numbers)) :
            minus_idx.append(i)
    return numbers, minus_idx
def get_smallest(numbers, minus_idx) :
    idx = 0
    ans = 0
    if not minus_idx :
        return sum(numbers)
    for i, num in enumerate(numbers) :
        if i == minus_idx[idx] :
            ans -= num
            idx += 1
            continue
        ans += num
    return ans


if __name__ == "__main__" :
    formula = list(input().rstrip())
    numbers, minus_idx = preprocess(formula)
    print(get_smallest(numbers, minus_idx))
    
    