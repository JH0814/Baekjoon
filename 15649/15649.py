N, M = map(int, input().split())
result = [0 for i in range(M)]
check = [0 for i in range(N + 1)]

def DFS(N, M, d):
    if d == M:
        for i in range(M):
            print(result[i], end=' ')
        print()
    else:
        for i in range(1, N + 1):
            if check[i] == 0:
                result[d] = i
                check[i] = 1
                DFS(N, M, d + 1)
                check[i] = 0
DFS(N, M, 0)