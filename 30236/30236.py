def sol(n, arr):
    ans = 1
    for i in range(n):
        if ans == arr[i]:
            ans += 1
        ans += 1
    ans -= 1
    return ans
        


t = int(input()) # 테스트 case 개수
for _ in range(t):
    n = int(input()) # n 입력
    arr = list(map(int, input().split())) # n개의 정수 입력 받음
    ans = sol(n, arr)
    print(ans)
