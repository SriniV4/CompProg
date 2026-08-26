s = input()
n = len(s)
l = len(set(s))
ans = 0
arr = [0] * 26
zc = l
cnt = {}
for j in range(n):
    ans += cnt.get(tuple(arr) , 0)
    cnt[tuple(arr)] = cnt.get(tuple(arr) , 0) + 1
    ind = ord(s[j]) - 97
    if(arr[ind] == 0):
        zc -= 1
    arr[ind] += 1
    if(zc == 0):
        for x in range(26):
            if(arr[x] > 0):
                arr[x] -= 1
                if(arr[x] == 0):
                    zc+=1
ans += cnt.get(tuple(arr), 0)
print(ans)
