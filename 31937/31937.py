N, M, K = map(int, input().split())
virus_list = list(map(int, input().split()))
arr = []
for i in range(M):
    log = tuple(map(int, input().split()))
    arr.append(log)

arr.sort(key = lambda log:log[0])
infected = [False] * (N + 1)
for i in virus_list:
    infected[i] = True

for i in range(1, N+1):
    if not infected[i]:
        continue
    visited = [False] * (N + 1)
    visited[i] = True
    flag = True
    for log in arr:
        t = log[0]
        a = log[1]
        b = log[2]
        if visited[a]: 
            if infected[a]:
                if not infected[b]:
                     flag = False
                     break
                else:
                     visited[b] = True
            else:
                flag = False
                break
    for j in range(1, N + 1):
        if visited[j] != infected[j]:
            flag = False
            break
    if flag:
        print(i)
        exit()