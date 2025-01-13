n, k = map(int, input().split())
arr = list(map(int, input().split()))

cnt = 0
ans_list = []
pre = 0
for i in range(n):
    if arr[i] != pre:
        cnt += 1
    else:
        ans_list.append(cnt)
        cnt = 1
    pre = arr[i]
    if i == n - 1:
        ans_list.append(cnt)
print(max(ans_list))