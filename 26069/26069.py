N = int(input())
rainbow_dance = {"ChongChong"}
for i in range(N):
    A, B = input().split()
    if A in rainbow_dance:
        rainbow_dance.add(B)
    if B in rainbow_dance:
        rainbow_dance.add(A)
    
print(len(rainbow_dance))