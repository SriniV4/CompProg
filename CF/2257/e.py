from types import GeneratorType


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        to = f(*args, **kwargs)
        while True:
            if type(to) is GeneratorType:
                stack.append(to)
                to = next(to)
            else:
                stack.pop()
                if not stack:
                    return to
                to = stack[-1].send(to)
    return wrappedfunc

##########################################################
import heapq
from collections import deque


def solve():
    n , x = [int(i) for i in input().split()]
    arrQ = []
    pq = []
    arr = []
    for i in range(n):
        m = int(input())
        a = [int(i) for i in input().split()]
        b = [int(i) for i in input().split()]
        curr = 0
        mn = 0
        cnt = 0
        arrQ.append(deque())
        for j in range(m):
            cnt += 1
            curr -= a[j]
            mn = min(curr, mn)
            curr += b[j]
            if(curr >= 0):
                arrQ[i].append((-mn , curr , cnt))
                curr = 0
                cnt = 0
        if(len(arrQ[i])):
            heapq.heappush(pq , (*arrQ[i][0] , i))
            arrQ[i].popleft()
        arr.append([m , a , b, 0])
    while(len(pq) and (x >= pq[0][0])):
        ele = heapq.heappop(pq)
        x += ele[1]
        i = ele[3]
        arr[i][3] += ele[2]
        if(len(arrQ[i])):
            heapq.heappush(pq,  (*arrQ[i][0] , i))
            arrQ[i].popleft()
    best , ind = (-1 , -1)
    for j in range(n):
        m , a , b, done = arr[j]
        temp = x
        for i in range(done , m):
            temp -= a[i]
            if(temp < 0):
                if(best < i):
                    best = i 
                    ind = j
                break;
            temp += b[i]
        if(temp >= 0 and best < m):
            best = m
            ind = j
    print(best , ind+1)
##########################################################

# t =1 
t = int(input())
for i in range(t):
    solve()
