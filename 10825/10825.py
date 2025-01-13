# sorting 시 사용할 class
class student:
    name = ""
    lan = 0
    eng = 0
    math = 0

# 문제의 정렬 기준에 맞게 비교하는 함수수
def cmp(a, b):
    if a.lan == b.lan and a.eng == b.eng and a.math == b.math:
        return a.name < b.name
    elif a.lan == b.lan and a.eng == b.eng:
        return a.math > b.math
    elif a.lan == b.lan:
        return a.eng < b.eng
    else:
        return a.lan > b.lan

# merge 시 사용용
def merge(left, right):
    i = 0
    j = 0
    sort_list = []
    while i < len(left) and j < len(right):
        if cmp(left[i], right[j]):
            sort_list.append(left[i])
            i += 1
        else:
            sort_list.append(right[j])
            j += 1
    while i < len(left):
        sort_list.append(left[i])
        i += 1
    while j < len(right):
        sort_list.append(right[j])
        j += 1
    return sort_list

# merge sort하는 함수
def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = int(len(arr)/2)
    left = arr[:mid]
    right = arr[mid:]

    af_left = merge_sort(left)
    af_right = merge_sort(right)
    return merge(af_left, af_right)


N = int(input()) # 학생의 수
arr = [] # student class의 객체를 넣어줄 list
for i in range(N):
    a = student() # 클래스 생성성
    b = input().split()
    # 클래스에 맞게 넣어주기기
    a.name = b[0]
    a.lan = int(b[1])
    a.eng = int(b[2])
    a.math = int(b[3])
    arr.append(a) # 클래스 객체 리스트에 추가

res = merge_sort(arr) # 함수 호출
# 출력력
for i in range(N):
    print(res[i].name)