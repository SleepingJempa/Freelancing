bars = [
    [1, 2, 3, 4, 5, 6],
    [],
    [],
]

def move(bars, a, b):
    if abs(a-b) == 2:
        move(bars, a, 1)
        move(bars, 1, b)
        return
    
    bars[b].append(bars[a].pop())



def hanoi(bars, n, a, b, c):
    if n == 1:
        move(bars, a, c)
    else:
        hanoi(bars, n-1, a, c, b)
        move(bars, a, c)
        hanoi(bars, n-1, b, a, c)

hanoi(bars, 6, 0, 1, 2)
print(bars)