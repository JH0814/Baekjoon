N, K = map(int, input().split())
d_list = list(map(int, input().split()))

res = K + 1
for i in range(1, N):
    res += min(K + 1, d_list[i] - d_list[i - 1])
print(res)