class Node:
    def __init__(self, value):
        self.value: int = value
        self.children: list[Node] = []
        self.attributes: dict = {}

    def add_child(self, node):
        self.children.append(node)
    
    def get(self, key):
        return self.attributes[key]
    
    def set(self, key, value):
        self.attributes[key] = value

def dfs(node: Node, level, levels):
    if level in levels:
        levels[level] += node.value
    else:
        levels[level] = node.value
    
    for child in node.children:
        dfs(child, level + 1, levels)

a = Node(3)
b = Node(6)
c = Node(1)
d = Node(0)
e = Node(4)
f = Node(5)
g = Node(2)
h = Node(2)

a.add_child(b)
a.add_child(c)

c.add_child(d)
c.add_child(e)

d.add_child(f)

e.add_child(g)

f.add_child(h)

l = {}
dfs(a, 0, l)

print(l)