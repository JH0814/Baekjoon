N = int(input())
P_arr = list(map(int, input().split()))
M = int(input())

dp = [0 for _ in range(M + 1)]
for i in range(N - 1, -1 ,-1):
    for j in range(P_arr[i], M + 1):
        dp[j] = max(dp[j], i, dp[j - P_arr[i]] * 10 + i)
print(dp[M])