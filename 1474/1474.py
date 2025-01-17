N, M = map(int, input().split())
str_arr = []
tot_len = 0
for i in range(N):
    s = input()
    str_arr.append(s)
    tot_len += len(s)

under_cnt = (M - tot_len) // (N - 1)
under_left = (M - tot_len) % (N - 1)

result = str_arr[0]
for i in range(1, N):
    if str_arr[i][0].islower() and under_left != 0:
        under_left -= 1
        result += '_' * (under_cnt + 1) + str_arr[i]
    elif i + under_left == N:
        under_left -= 1
        result += '_' * (under_cnt + 1) + str_arr[i]
    else:
        result += '_' * under_cnt + str_arr[i]
print(result)