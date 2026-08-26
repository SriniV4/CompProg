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
def solve():
    n , x = [int(i) for i in input().split()]
    arr = []
    mx = 0
    best = []
    for i in range(n):
        m = int(input())
        mx = max(mx , m)
        a = [int(i) for i in input().split()]
        b = [int(i) for i in input().split()]
        for j in range(m):
        arr.append((m , a , b))
    
##########################################################

t = int(input())
for i in range(t):
    solve()
