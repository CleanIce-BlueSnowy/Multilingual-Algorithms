#ifndef _UNION_FIND_H_
#define _UNION_FIND_H_

#include <memory>

class UnionFind {
public:
    using usize = std::size_t;

private:
    const std::unique_ptr<usize[]> father;
    const usize length;

    usize find_root(usize x) noexcept;

public:
    UnionFind(usize length) noexcept;
    void merge(usize x, usize y) noexcept;
    bool is_connected(usize x, usize y) noexcept;
    usize size() const noexcept;
    usize num_blocks() noexcept;
};

#endif
