import math

s = input()
t = input()

n = len(s)


ones = 0
zero = 0
same = 0
for i in range(n):
    if s[i] == t[i]:
        same += 1
    elif s[i] == '1':
        ones += 1
    else:
        zero += 1
    
mx, mn = max(ones, zero), min(ones, zero)

print(mx)