import sys
input = sys.stdin.readline

N, M = map(int, input().split())
word_cnt = {}

for i in range(N):
    word = input().rstrip()
    if len(word) < M:
        continue
    else:
        if word in word_cnt:
            word_cnt[word] += 1
        else:
            word_cnt[word] = 1

word_cnt = sorted(word_cnt.items(), key=lambda x : (-x[1], -len(x[0]), x[0]))

for i in word_cnt:
    print(i[0])