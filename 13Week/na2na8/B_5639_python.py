import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

def postorder(start, end) :
    global preorder
    if start > end : return

    mid = end + 1
    for i in range(start + 1, end + 1) :
        if preorder[start] < preorder[i] :
            mid = i
            break
    postorder(start+1, mid-1)
    postorder(mid, end)
    print(preorder[start])

if __name__ == "__main__" :
    preorder = []
    while True:
        try:
            num = int(input())
            preorder.append(num)
        except:
            break

    postorder(0, len(preorder)-1)