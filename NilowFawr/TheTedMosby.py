"""
At first enter the number of people in the party
then enter every single pair of start and finish
    time of the intervals in seperate lines.
The sample input format:
3
1 2
3 5
4 9
"""

# The number of people
n = int(input())

# The intervals which people don't dance
d = [ tuple(map(int, input().split())) for i in range(n) ]

# To store answers
t = []

d.sort(key=lambda i: i[1])

t.append(d[0][1])

i = 1
while i < n:
    last = t[-1]

    if d[i][0] > last:
        t.append(d[i][1])
    
    i += 1

print(t)