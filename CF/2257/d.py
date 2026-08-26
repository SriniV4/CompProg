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
import bisect


def solve():
    S , q = [int(i) for i in input().split()]
    rect = []
    p = []
    i = 1
    while(i * i <= S):
        if(S%i==0):
            rect.append(i)
            if(i != S//i):
                rect.append(S//i)
        i+=1
    rect.sort()
    p.append(S)
    for i in range(1 , len(rect)):
        p.append(p[-1] + (rect[i] - rect[i-1]) * (S//rect[i]))
    # print(rect , p)
    for i in range(q):
        x , y = [int(i) for i in input().split()]
        ans = 0
        # want to find largest guy that big enough
        ind = bisect.bisect_right(rect , y)
        ind -= 1
        assert(ind >= 0)
        # find last ind that exceeds
        indx = len(rect) - bisect.bisect_right(rect , x) - 1 # last guy thats greater than x
        # print(ind , indx)
        if(indx > ind):
            print(x * y)
            continue
        ans = 0 if indx == -1 else rect[indx] * x 
        ans += p[ind] - (0 if indx == -1 else p[indx])
        if(ind + 1 < len(rect)):
            ans += (y-rect[ind]) * S//rect[ind+1]
        print(ans)
##########################################################

t = int(input())
for i in range(t):
    solve()
