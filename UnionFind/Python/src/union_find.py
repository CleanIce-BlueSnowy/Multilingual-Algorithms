class UnionFind:
    def __init__(self, length: int):
        self.father = [i for i in range(length)]

    def merge(self, x: int, y: int):
        if not self.is_connected(x, y):
            self.father[self.__find_root(x)] = self.__find_root(y)

    def is_connected(self, x: int, y: int) -> bool:
        return self.__find_root(x) == self.__find_root(y)

    @property
    def size(self) -> int:
        return len(self.father)

    @property
    def num_blocks(self) -> int:
        visited = [False for _i in range(len(self.father))]
        res = 0
        for i in range(len(self.father)):
            root = self.__find_root(i)
            if not visited[root]:
                res += 1
                visited[root] = True
        return res

    def __find_root(self, x: int) -> int:
        if self.father[x] == x:
            return x
        temp = self.__find_root(self.father[x])
        self.father[x] = temp
        return temp
