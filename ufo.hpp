#include <algorithm>

namespace ufo {
template<typename T = void> struct min {
  constexpr T const &operator()(T const &a, T const &b) const noexcept {
    return std::min(a, b);
  }
};

template<> struct min<void> {
  template<typename T1, typename T2>
  constexpr auto operator()(T1 const &a, T2 const &b) const noexcept
    -> decltype(std::min(a, b)) {
    return std::min(a, b);
  }
};

template<typename T = void> struct max {
  constexpr T const &operator()(T const &a, T const &b) const noexcept {
    return std::max(a, b);
  }
};

template<> struct max<void> {
  template<typename T1, typename T2>
  constexpr auto operator()(T1 const &a, T2 const &b) const noexcept
    -> decltype(std::max(a, b)) {
    return std::max(a, b);
  }
};

template<typename T = void> struct abs_diff {
  constexpr T const &operator()(T const &a, T const &b) const noexcept {
    return std::abs(a - b);
  }
};

template<> struct abs_diff<void> {
  template<typename T1, typename T2>
  constexpr auto operator()(T1 const &a, T2 const &b) const noexcept
    -> decltype(std::abs(a - b)) {
    return std::abs(a - b);
  }
};

template<typename T> class plus {
  T val;

public:
  explicit plus(T v) : val(v) {}

  constexpr auto operator()(T const &a) const noexcept { return val + a; };
};
}// namespace ufo
