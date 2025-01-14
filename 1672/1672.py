N = int(input())
s = list(input())
table = {"AA" : "A", "AG" : "C", "AC" : "A", "AT" : "G", "GA" : "C","GG" : "G",
       "GC" : "T", "GT" : "A", "CA" : "A", "CG" : "T", "CC" : "C", "CT" : "G",
       "TA" : "G", "TG" : "A", "TC" : "G","TT" : "T"}

while len(s) != 1:
    ss = s[-2] + s[-1]
    if ss in table:
        s.pop()
        s.pop()
        s.append(table.get(ss))
print(*s)