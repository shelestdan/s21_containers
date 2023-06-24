#ifndef S21_STACK_H_
#define S21_STACK_H_

#include <vector/s21_vector.h>

namespace s21 {

template <class T, class Container = s21::vector<T>>
class stack {
 public:
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

 public:
  stack() = default;
  stack(std::initializer_list<value_type> const &items) : elements(items) {}

  stack(const stack &other) = default;
  stack(stack &&other) noexcept = default;
  stack &operator=(const stack &other) = default;
  stack &operator=(stack &&other) noexcept = default;

  const_reference top() const { return elements.back(); }

  bool empty() const { return elements.empty(); }
  size_type size() const { return elements.size(); }

  void push(const_reference value) { elements.push_back(value); }
  template <class... Args>
  void emplace(const Args &...args) {
    elements.emplace_back(args...);
  }
  void pop() { elements.pop_back(); }
  void swap(stack &other) { elements.swap(other.elements); }
  void emplace_back(const_reference value) { elements.push_back(value); }

  template <typename... Args>
  void emplace_front(Args &&...args) {
    elements.emplace_back(std::forward<Args>(args)...);
  }

 private:
  Container elements;
};

}  // namespace s21

#endif  // S21_STACK_H_
