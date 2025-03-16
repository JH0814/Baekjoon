N, L, R = map(int, input().split())
A = list(map(int, input().split()))

B = A[L-1:R]
B.sort()

A = A[:L-1] + B + A[R:]
for i in range(len(A) - 1):
    if A[i] > A[i + 1]:
        print(0)
        exit(0)
print(1)