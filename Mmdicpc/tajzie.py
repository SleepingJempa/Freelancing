n = int(input())

def boom(n):
    dic = {}

    i = 2
    while n > 1:
        # print('Hame taghsire mahlas {}'.format(n))
        cnt = 0
        while n % i == 0:
            cnt += 1
            n //= i
        if cnt: dic[i] = cnt
        i += 1

    
    return dic

def printDic(dic: dict):
    l = []
    for item in dic.items():
        l.append(item)
    k = len(l)
    for i in range(k):
        if i == k-1:
            print('{}^{}'.format(l[i][0], l[i][1]))
        else:
            print('{}^{}*'.format(l[i][0], l[i][1]), end='')


printDic(boom(n))