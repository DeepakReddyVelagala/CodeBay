def func(n):
    str = bin(n).replace('0b', '')
    str = str[::-1]
    
    res = 0
    for i in range(len(str)):
        if i % 2 == 0 and str[i] == '1':
            res += 1
    return res


def solve(k):

    low, high = 1, k * 2
    res = 1

    while low <= high:
        mid = (low + high) // 2
        if sum(func(i) for i in range(1, mid + 1)) <= k:
            res = mid
            low = mid + 1
        else:
            high = mid - 1

    print(res)