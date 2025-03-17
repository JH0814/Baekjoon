def Cantor_set(n):
    if n == 1:
        return "-"
    
    unit = Cantor_set(n // 3)
    res = unit + " " * (n // 3) + unit

    return res
while True:
    try:
        N = int(input())
        print(Cantor_set(3 ** N))
    except:
        break