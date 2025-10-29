public class UnionFind {
    private final int[] father;

    public UnionFind(int length) {
        father = new int[length];
        for (int i = 0; i < length; i++) {
            father[i] = i;
        }
    }

    public void merge(int x, int y) {
        if (!isConnected(x, y)) {
            father[findRoot(x)] = findRoot(y);
        }
    }

    public boolean isConnected(int x, int y) {
        return findRoot(x) == findRoot(y);
    }

    public int size() {
        return father.length;
    }

    public int numBlocks() {
        boolean[] visited = new boolean[father.length];
        int res = 0;
        for (int i = 0; i < father.length; i++) {
            int root = findRoot(i);
            if (!visited[root]) {
                res++;
                visited[root] = true;
            }
        }
        return res;
    }

    private int findRoot(int x) {
        if (father[x] == x) {
            return x;
        }
        int temp = findRoot(father[x]);
        father[x] = temp;
        return temp;
    }
}
