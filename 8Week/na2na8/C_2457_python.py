import sys
input = sys.stdin.readline

if __name__ == "__main__" :
    N = int(input().rstrip())
    flowers = []
    for _ in range(N) :
        m1, d1, m2, d2 = map(int, input().rstrip().split(' '))
        date1, date2 = m1*100 + d1, m2*100 + d2
        if date1 > 1130 or date2 < 301 : continue
        flowers.append([date1, date2])
    flowers = sorted(flowers, key=lambda x : x[0])
    
    ans = 1
    bloom = 301
    end = 301
    for idx, flower in enumerate(flowers) :
        # 3월 1일부터 필 수 있는 꽃이 없을 경우 0
        if end == 301 and flower[0] > bloom :
            print(0)
            exit()
        if flower[0] <= bloom and flower[1] > end :
            end = flower[1]
        elif bloom < flower[0] <= end and end < flower[1] :
            bloom = end
            end = flower[1]
            ans += 1
        if end > 1130 :
            print(ans)
            exit()
        # 마지막까지 11/30까지 꽃을 피울 수 없다면
        if idx == len(flowers)-1 and end <= 1130 :
            print(0)
            exit()
        
    print(ans)
        
