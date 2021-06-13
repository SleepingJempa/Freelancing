bars = [
    [1, 2, 6, 7],
    [3, 4, 5, 8, 9, 10],
    []
]

# move from a to b
def move(bars, p, q):
    bars[q].append(bars[p].pop())

# a be komake b goto c
def hanoi(bars, a, b, c, disks):
    if disks == 1:
        move(bars, a, c)
    else:
        hanoi(bars, a, c, b, disks-1)
        move(bars, a, c)
        hanoi(bars, b, a, c, disks-1)


def ex_hanoi(bars, a, b, c, patterns):
    if patterns == 1:
        hanoi(bars, b, c, a, 3)
        hanoi(bars, a, b, c, 5)
    else:
        ex_hanoi(bars, a, b, c, patterns-1)
        hanoi(bars, c, a, b, 5*(patterns-1))
        hanoi(bars, b, c, a, 5*(patterns-1) + 3)
        hanoi(bars, a, b, c, 5*patterns)

ex_hanoi(bars, 0, 1, 2, 2)