n = int(input()) # 사람들의 수
num_arr = list(map(int, input().split())) # 왼쪽에 더 큰 사람이 몇 명 있었는지
visit = [0 for i in range(n)] # 줄의 자리에 이미 차 있는지 여부 저장

for i in range(n):
    cnt = 0 # 큰 사람 count
    for j in range(n):
        if cnt == num_arr[i] and visit[j] == 0: # i보다 큰 사람 count가 끝나고 자리도 비어있는 경우
            visit[j] = i + 1
            break
        elif visit[j] == 0: # i보다 큰 사람 세기
            cnt += 1

# 출력
for i in range(n):
    print(visit[i], end=' ')
print()
