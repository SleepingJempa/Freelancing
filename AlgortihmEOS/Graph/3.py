class Node:
    def __init__(self, value):
        self.value: int = value
        self.adj_list: list[Node] = []
        self.attributes: dict = {}

    def connect(self, node):
        self.adj_list.append(node)
        node.adj_list.append(self)
    
    def get(self, key):
        return self.attributes[key]
    
    def set(self, key, value):
        self.attributes[key] = value

def dfs(node: Node) -> int:
    node.set('visited', True)

    minimum = node.value

    for adj in node.adj_list:
        if 'visited' not in adj.attributes:
            minimum = min(minimum, dfs(adj))
    
    return minimum

a = Node(4)
b = Node(2)
c = Node(8)

d = Node(9)
e = Node(5)

f = Node(3)

a.connect(b)
a.connect(c)

d.connect(e)

A = [a, b, c, d, e, f]
ans = 0

for i in range(len(A)):
    if 'visited' not in A[i].attributes:
        ans += dfs(A[i])

print(ans)