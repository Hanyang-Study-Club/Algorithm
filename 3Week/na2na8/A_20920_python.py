import sys
input = sys.stdin.readline
# N :단어 개수, M : 기준 길이
N, M = map(int, input().strip().split(' '))
alphabet = {'a':0, 'b':1, 'c':2, 'd':3, 'e':4, 'f':5, 'g':6, 'h':7, 'i':8, 'j':9, 'k':10, 
            'l':11, 'm':12, 'n':13, 'o':14, 'p':15 ,'q':16, 'r':17, 's':18, 't':19, 'u':20, 
            'v':21, 'w':22, 'x':23, 'y':24, 'z':25}
dictionary = {}
for n in range(N) :
    word = input().strip()
    if len(word) >= M :
        try :
            dictionary[word][0] += 1
        except KeyError :
            word_num = ''
            for char in word :
                word_num += str(25-alphabet[char]).zfill(2)
            dictionary[word] = [1, word_num]
                
for word in sorted([(item[0], str(item[1][0]).zfill(6) + str(len(item[0])).zfill(2) + item[1][1]) for item in dictionary.items()], key=lambda x : x[1], reverse=True) :
    print(word[0])


