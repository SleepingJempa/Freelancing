a = [list(map(int, input().split(','))) for i in range(3)]

A = a[0]
B = a[1]
C = a[2]

J = []

for x in A:
    if x not in J:
        J.append(x)
for x in B:
    if x not in J:
        J.append(x)
for x in C:
    if x not in J:
        J.append(x)

for x in J:
    if (x in A and x in B) or (x in C and x in B) or (x in A and x in C):
            J.remove(x)

x = [str(e) for e in J]

print(','.join(x))
