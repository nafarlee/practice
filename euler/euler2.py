def fib(limit):
    """return list of fibonacci numbers till limit"""
    lis = []
    x = 1
    y = 1
    while y <= limit:
        lis.append(y)
        x, y = (y, x)
        y = x+y
    return lis

print sum([x for x in fib(4000000) if x % 2 == 0])


