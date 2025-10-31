namespace CSharp;

public class UnionFind {
    private readonly int[] father;

    public UnionFind(int length) {
        father = new int[length];
        for (var i = 0; i < length; i++) {
            father[i] = i;
        }
    }

    public void Merge(int x, int y) {
        if (!IsConnected(x, y)) {
            father[FindRoot(x)] = FindRoot(y);
        }
    }

    public bool IsConnected(int x, int y) {
        return FindRoot(x) == FindRoot(y);
    }

    public int Size {
        get {
            return father.Length;
        }
    }

    public int NumBlocks {
        get {
            var visited = new bool[father.Length];
            var res = 0;
            for (var i = 0; i < father.Length; i++) {
                var root = FindRoot(i);
                if (!visited[root]) {
                    res++;
                    visited[root] = true;
                }
            }
            return res;
        }
    }

    private int FindRoot(int x) {
        if (father[x] == x) {
            return x;
        }
        var temp = FindRoot(father[x]);
        father[x] = temp;
        return temp;
    }
}
