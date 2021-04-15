from random import randint


class Vertex:
    def __init__(self, value):
        self.value = value
        self.adj = {}

    def connect(self, other, length, line):
        self.adj[other.value] = Edge(self, other, length, line)

    def get_value(self):
        return self.value

    def get_edge(self, value):
        return self.adj[value]


class Edge:
    def __init__(self, start, end, length, line):
        self.start = start
        self.end = end
        self.length = length
        self.line = line


class Network:
    """
    m: rows
    n: columns
    a: horizontal length
    b: vertical length
    path: the file name
    lower: lower bound for random number (demand)
    upper: upper bound for random number (demand)
    """
    def __init__(self, m, n, a, b, path, lower: str, upper: str):
        self.m = m
        self.n = n
        self.a = a
        self.b = b
        self.path = path

        if lower.isnumeric():
            self.lower = int(lower)
        else:
            self.lower = 0
        if upper.isnumeric():
            self.upper = int(upper)
        else:
            self.upper = 1000

        self.vertices = {}
        self.demand = {}

        self.build()

    def get_demand(self, s, e):
        if s == e:
            return 0

        t = tuple(sorted([s, e]))

        if t not in self.demand:
            self.demand[t] = randint(self.lower, self.upper)

        return self.demand[t]

    def get_index(self, i, j):
        return self.n * i + j

    def get_coords(self, value):
        j = value % self.n
        i = value // self.n
        return i, j

    def build(self):
        for i in range(self.m):
            for j in range(self.n):
                self.vertices[(i, j)] = Vertex(self.n * i + j + 1)

        for i in range(self.m):
            for j in range(self.n):
                if i+1 < self.m:
                    self.vertices[(i, j)].connect(self.vertices[(i+1, j)], self.b, j+1)
                if i-1 >= 0:
                    self.vertices[(i, j)].connect(self.vertices[(i-1, j)], self.b, j+1)
                if j+1 < self.n:
                    self.vertices[(i, j)].connect(self.vertices[(i, j+1)], self.a, self.n+i+1)
                if j-1 >= 0:
                    self.vertices[(i, j)].connect(self.vertices[(i, j-1)], self.a, self.n+i+1)

    def get_vertex(self, value):
        i, j = self.get_coords(value)
        return self.vertices[(i, j)]

    def get_edge(self, s, e):
        return self.vertices[self.get_coords(s)].get_edge(e)
