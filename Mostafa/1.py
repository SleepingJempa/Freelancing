students = []

s = input()

while s != '-1':
    info = list(map(int, s.split(' ')))
    students.append(info)
    s = input()

print(students)

def avg(students):
    f = open('myOutput.txt', 'w')
    result = ''
    for info in students:
        code = info[0]
        mat_score = info[1]
        eng_score = info[2]
        prg_score = info[3] 

        avg = (mat_score + eng_score + prg_score) / 3

        result += '{}\t\t{}\n'.format(str(code), str(avg))
        # print(result)
    
    f.write(result)
    f.close()
    
avg(students)