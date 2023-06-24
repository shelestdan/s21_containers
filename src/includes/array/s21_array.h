#ifndef __S21_ARRAY_H__
#define __S21_ARRAY_H__

#include <stdexcept>
#include <utility>

namespace s21 {
template <typename Ty, size_t Size>
class array {
 public:
  using value_type = Ty;
  using reference = Ty&;
  using const_reference = const Ty&;
  using iterator = Ty*;
  using const_iterator = const Ty*;
  using size_type = size_t;

  array() {}

  array(std::initializer_list<value_type> const& items) {
    size_type index = 0;
    for (const_reference& item : items) {
      if (index >= Size) {
        break;
      }
      data_[index++] = item;
    }
  }

  array(const array& a) {
    for (size_type i = 0; i < size(); ++i) {
      data_[i] = a.data_[i];
    }
  }

  array(array&& a) {
    for (size_type i = 0; i < size(); ++i) {
      data_[i] = a.data_[i];
      a.data_[i] = value_type{};
    }
  }

  ~array() {}

  array& operator=(array&& a) {
    for (size_type i = 0; i < size(); ++i) {
      data_[i] = a.data_[i];
      a.data_[i] = value_type{};
    }
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= Size) {
      throw std::out_of_range("array: Index out of range");
    }
    return data_[pos];
  }

  reference operator[](size_type pos) { return data_[pos]; }

  const_reference front() { return data_[0]; }

  const_reference back() { return data_[Size - 1]; }

  iterator data() { return data_; }

  iterator begin() { return data_; }

  iterator end() { return data_ + Size; }

  bool empty() { return Size == 0; }

  size_type size() { return Size; }

  size_type max_size() { return Size; }

  void swap(array& other) {
    for (size_type i = 0; i < size(); ++i) {
      value_type tmpValue = data_[i];
      data_[i] = other.data_[i];
      other.data_[i] = tmpValue;
    }
  }

  void fill(const_reference value) {
    for (size_type i = 0; i < size(); ++i) {
      data_[i] = value;
    }
  }

 private:
  value_type data_[Size];
};
}  // namespace s21

#endif  // __S21_ARRAY_H__