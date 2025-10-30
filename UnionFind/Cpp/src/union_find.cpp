#include "union_find.h"

UnionFind::UnionFind(const usize length) noexcept: father(std::make_unique<usize[]>(length)), length(length) {
    for (usize i = 0; i < length; i++) {
        father[i] = i;
    }
}

void UnionFind::merge(const usize x, const usize y) noexcept {
    if (!is_connected(x, y)) {
        father[find_root(x)] = find_root(y);
    }
}

bool UnionFind::is_connected(const usize x, const usize y) noexcept {
    return find_root(x) == find_root(y);
}

UnionFind::usize UnionFind::size() const noexcept {
    return length;
}

UnionFind::usize UnionFind::num_blocks() noexcept {
    auto visited = std::make_unique<bool[]>(length);
    usize res = 0;
    for (usize i = 0; i < length; i++) {
        const usize root = find_root(i);
        if (!visited[root]) {
            res++;
            visited[root] = true;
        }
    }
    return res;
}

UnionFind::usize UnionFind::find_root(const usize x) noexcept {
    if (father[x] == x) {
        return x;
    }
    const usize temp = find_root(father[x]);
    father[x] = temp;
    return temp;
}
