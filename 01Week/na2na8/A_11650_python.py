import sys
sys.setrecursionlimit(10**8)

def merge(num_list, left, mid, right) :
    l = left # 왼쪽 리스트 시작점
    r = mid+1 # 오른쪽 리스트 시작점
    merge_list = []
    while l<=mid and r<=right :
        if num_list[l] <= num_list[r] :
            merge_list.append(num_list[l])
            l += 1
        else :
            merge_list.append(num_list[r])
            r += 1
    if l<=mid : # 왼쪽 리스트 남았을 경우
        for i in range(l, mid+1) :
            merge_list.append(num_list[i])
    else : # 오른쪽 리스트 남았을 경우
        for i in range(r, right+1) :
            merge_list.append(num_list[i])
    
    num_list[left:right+1] = merge_list
    
def merge_sort(num_list, left, right) :
    if left < right :
        mid = int((left + right)/2)
        merge_sort(num_list, left, mid)
        merge_sort(num_list, mid+1, right)
        merge(num_list, left, mid, right)
    
N = input()
coordinate = []

for i in range(int(N)) :
    x, y = input().split(' ')
    coordinate.append((int(x),int(y)))
merge_sort(coordinate, 0, len(coordinate)-1)

for co in coordinate :
    print(co[0], co[1])