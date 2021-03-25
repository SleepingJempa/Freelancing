def f(n: int) -> str:
    if n == 0: return "0"
    if n == 1: return "1"
    else: return f(n-1) + f(n-2)