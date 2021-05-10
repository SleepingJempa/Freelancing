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

def dfs(node: Node, color) -> bool:
    if 'color' not in node.attributes:
        node.set('color', color)
    elif node.get('color') != color:
        return False
    else:
        return True

    for child in node.adj_list:
        if not dfs(child, 1-color):
            return False
    
    return True

a1 = Node(1)
a2 = Node(2)
a3 = Node(3)

a1.connect(a2)
a2.connect(a3)

print(dfs(a1, 0))

b1 = Node(1)
b2 = Node(2)
b3 = Node(3)

b1.connect(b2)
b2.connect(b3)
b3.connect(b1)

print(dfs(b1, 0))