N = int(input())
cnt = 0
for i in range(N):
    s = input()
    stack = []
    for j in range(len(s)):
        if len(stack) == 0 or stack[-1] != s[j]:
            stack.append(s[j])
        else:
            stack.pop()
    if len(stack) == 0:
        cnt += 1
print(cnt)