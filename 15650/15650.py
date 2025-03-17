N, M = map(int, input().split())
result = [0 for i in range(M + 1)]

def DFS(d, last):
    if d == M:
        for i in range(M):
            print(result[i], end=' ')
        print()
    else:
        for i in range(last, N + 1):
            result[d] = i
            DFS(d + 1, i + 1)
DFS(0, 1)