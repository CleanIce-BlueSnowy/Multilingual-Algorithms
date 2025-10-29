#include "union_find.h"

UnionFind::UnionFind(usize size) noexcept: father(std::make_unique<usize[]>(size)), _size(size) {
    for (usize i = 0; i < size; i++) {
        father[i] = i;
    }
}

void UnionFind::merge(usize x, usize y) noexcept {
    if (!is_connected(x, y)) {
        father[find_root(x)] = find_root(y);
    }
}

bool UnionFind::is_connected(usize x, usize y) noexcept {
    return find_root(x) == find_root(y);
}

UnionFind::usize UnionFind::size() const noexcept {
    return _size;
}

UnionFind::usize UnionFind::num_blocks() noexcept {
    auto visited = std::make_unique<bool[]>(_size);
    usize res = 0;
    for (usize i = 0; i < _size; i++) {
        usize root = find_root(i);
        if (!visited[root]) {
            res++;
            visited[root] = true;
        }
    }
    return res;
}

UnionFind::usize UnionFind::find_root(usize x) noexcept {
    if (father[x] == x) {
        return x;
    }
    usize temp = find_root(father[x]);
    father[x] = temp;
    return temp;
}
