names = input().split()
n = len(names)
result = []

def seda(c):
    return c in ['a', 'A', 'i', 'I', 'u', 'U', 'e', 'E', 'o', 'O']

def convert(name, r):
    name = list(name)

    for i in range(len(name)):
        if seda(name[i]):
            name[i] = chr(ord(name[i]) + 1)
    
    while len(name) > 10:
        w, name = ''.join(name[:10]), name[10:]
        r.append(w)
    
    r.append(''.join(name))

for name in names:
    convert(name, result)

# print(*result)
n = len(result)

for i in range(n-1):
    for j in range(n-i-1):
        # print(f'comparing {result[j]} with {result[j+1]}')
        if result[j][0].upper() > result[j+1][0].upper():
            result[j], result[j+1] = result[j+1], result[j]
            # print('first')
        if result[j][0].upper() == result[j+1][0].upper():
            if result[j][0].islower():
                result[j], result[j+1] = result[j+1], result[j]
                # print('second')

print(*result)

