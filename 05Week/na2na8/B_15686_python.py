from itertools import combinations
import sys
input = sys.stdin.readline

N, M = map(int, input().strip().split(' '))
house = []
chicken = []

for row in range(N) :
    line = list(map(int, input().strip().split(' ')))
    for collumn in range(N) :
        if line[collumn] == 1 :
            house.append((row+1, collumn+1))
        if line[collumn] == 2 :
            chicken.append((row+1, collumn+1))
            
min_city_distance = 1000000
for comb in combinations(chicken, M) :
    distance = [100]*len(house)
    for c in comb :
        distance = [abs(c[0]-h[0])+abs(c[1]-h[1]) if abs(c[0]-h[0])+abs(c[1]-h[1]) < distance[i] else distance[i] for i, h in enumerate(house)]
        sum_distance = sum(distance)
        if min_city_distance > sum_distance :
            min_city_distance = sum_distance

print(min_city_distance)