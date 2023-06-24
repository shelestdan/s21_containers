#ifndef S21_QUEUE_H_
#define S21_QUEUE_H_

#include <vector/s21_vector.h>

namespace s21 {

template <class T, class Container = s21::vector<T>>
class queue {
 public:
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

 public:
  queue() = default;
  queue(std::initializer_list<value_type> const& items) : elements(items) {}

  queue(const queue& other) = default;
  queue(queue&& other) noexcept = default;
  queue& operator=(const queue& other) = default;
  queue& operator=(queue&& other) noexcept = default;

  const_reference front() const { return elements.front(); }
  const_reference back() const { return elements.back(); }

  bool empty() const { return elements.empty(); }
  size_type size() const { return elements.size(); }

  void push(const_reference value) { elements.push_back(value); }
  template <class... Args>
  void emplace(Args&&... args) {
    elements.emplace_back(std::forward<Args>(args)...);
  }
  void pop() { elements.erase(elements.begin()); }
  void swap(queue& other) { elements.swap(other.elements); }
  void emplace_back(const_reference value) { elements.emplace_back(value); }

 private:
  Container elements;
};

}  // namespace s21

#endif  // S21_QUEUE_H_
