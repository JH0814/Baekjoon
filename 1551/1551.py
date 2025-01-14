N, K = map(int, input().split())
arr = list(map(int, input().split(',')))

for t in range(K):
    new_arr = []
    for i in range(len(arr) - 1):
        new_arr.append(arr[i + 1] - arr[i])
    arr = new_arr

for i in range(len(arr) - 1):
    print(arr[i], end=',')
print(arr[-1])