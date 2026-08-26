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

t = int(input())
for i in range(t):
    solve()
MAXN = 100000
G = [[] for i in range(MAXN)]
dep = [0] * MAXN
@bootstrap
def dfs(curr = 0):
    if(curr == 0):
        dep[curr] = 0
    for i in G[curr]:
        dep[i] = dep[curr] + 1
        yield dfs(i)
    yield
def solve():
    n = int(input())
    for i in range(n):
        G[i].clear()
    p = [int(i)-1 for i in input().split()]
    for i in range(n-1):
        G[p[i]].append(i+1)
    dfs()
    m = int(input())
    a = [int(i)-1 for i in input().split()]
    ind = -1
    mn = MAXN
    for (i , val) in enumerate(a):
        if(dep[val] < mn):
            ind = i 
            mn = dep[val]
    print(" ".join(map(str , [m-1] + [a[i]+1 for i in range(m) if i != ind])))

##########################################################

