n = int(input())
for t in range(n):
    event_list = []
    while True:
        event = list(map(int, input().split()))
        if event[0] == 0 and event[1] == 0:
            break
        event_list.append(event)
    event_list.sort(key=lambda event:event[1])
    cnt = 0
    end_time = 0
    for i in range(len(event_list)):
        fir = event_list[i][0]
        lst = event_list[i][1]
        if fir >= end_time:
            cnt += 1
            end_time = lst
    print(cnt)