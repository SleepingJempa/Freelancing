def say(p, i):
    print(f'{p[i]} to {p[i+1]}: ke ba in dar agar dar bande dar manand, dar manand.')

    for j in range(i+1, 0, -1):
        print(f'{p[j]} to {p[j-1]}: dar manand?')

    for j in range(i+1):
        print(f'{p[j]} to {p[j+1]}: dar manand.')

n = int(input())
p = [ input() for i in range(n) ]

for i in range(n-1):
    say(p, i)