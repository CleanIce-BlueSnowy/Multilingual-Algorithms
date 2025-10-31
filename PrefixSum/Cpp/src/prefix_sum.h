#include <iterator>
#include <memory>

class PrefixSum {
public:
    using usize = std::size_t;

private:
    std::unique_ptr<int[]> prefix;
    const usize length;

public:
    template <std::input_iterator Iterator>
    PrefixSum(Iterator begin, Iterator end) noexcept;
    int get_sum(usize left, usize right) const;
};
