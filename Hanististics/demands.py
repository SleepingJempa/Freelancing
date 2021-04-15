from openpyxl import load_workbook
import operator

# file_path = 'out3x4.xlsx'
file_path = input("Enter the python filename: ")

wb = load_workbook(filename=file_path, read_only=True)

demands = wb.sheets[1]

sizes = demands.title.split(' ')[0].split('x')
n, m = map(int, sizes)
k = n * m

print(n, m, k)

all_demands = {}

for row in demands.rows:
    the_row = [cell.value for cell in row]
    [x, y, d] = the_row
    all_demands[(x, y)] = d

def get_demand(x, y):
    print('=>', x, y)
    return all_demands[(x, y)]


# print(get_demand(1, 3))
nodes_demand = {}

for i in range(k):
    value = 0
    node = i + 1
    row = i // m + 1
    col = i % m + 1
    x = node % m
    if x == 0:
        x = m
    y = row * m + 1

    print('=-=-=-')
    print(node)

    if x == node:
        x += m

    while x <= k:
        value += get_demand(node, x) + get_demand(x, node)
        x += m

    while y <= row * m:
        value += get_demand(node, y) + get_demand(y, node)
        y += 1

    nodes_demand[node] = value

sorted_nodes_total_trip = dict(sorted(nodes_demand.items(), key=lambda t: t[1], reverse=True))

print(sorted_nodes_total_trip)
