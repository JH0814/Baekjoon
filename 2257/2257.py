S = input()
Ato_Wei = {'C' : 12, 'O' : 16, 'H' : 1}

stack = []
total = 0

for i in range(len(S)):
    c = S[i]
    if c == '(':
        stack.append(c)
    elif c == ')':
        sum = 0
        while True:
            temp = stack.pop()
            if temp == '(':
                break
            sum += temp
        stack.append(sum)
    elif c in Ato_Wei.keys():
        stack.append(Ato_Wei[c])
    else:
        stack[-1] *= int(c)
for i in range(len(stack)):
    total += stack[i]

print(total)
    