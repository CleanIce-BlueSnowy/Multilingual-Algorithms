#include "prefix_sum.h"
#include <format>
#include <stdexcept>

template <std::input_iterator Iterator>
PrefixSum::PrefixSum(Iterator begin, Iterator end) noexcept {
    length = end - begin;
    prefix = std::make_unique<int[]>(length + 1);

    prefix[0] = 0;
    usize i = 1;
    Iterator it = begin;
    while (i <= length) {
        prefix[i] = prefix[i - 1] + *it;
        i++;
        it++;
    }
}

int PrefixSum::get_sum(usize left, usize right) const {
    if (right > length) {
        throw std::out_of_range(std::format("Index out of range: {}", right));
    } else if (left > right) {
        throw std::out_of_range(std::format("Left is greater than right: {} > {}", left, right));
    }
    return prefix[right] - prefix[left];
}
